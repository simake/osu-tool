#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include "config.hpp"

namespace fs = boost::filesystem;
namespace pt = boost::property_tree;

static const char* CONFIG_PATH = "settings.ini";

Config& Config::getInstance() {
    static Config instance;
    return instance;
}

Config::Config() {
    loadFile(CONFIG_PATH);
    printf("Constructor called\n");
}

void Config::loadFile(const std::string& path) {
    try {
        pt::read_ini(path, mProperties);
    } catch (pt::ini_parser_error&) {
        std::cerr << CONFIG_PATH << " not found. Using defaults." << std::endl;
    }
}

template<class T>
T Config::get(const std::string& prop, const T& defaultValue) {
    try {
        return mProperties.get<T>(prop);
    } catch (boost::property_tree::ptree_error&) {
        std::cerr << prop << " property not found in " << CONFIG_PATH
                  << ", using default value instead: " << defaultValue << std::endl;
        return defaultValue;
    }
}

// Add new template declarations below to avoid linker errors

template int Config::get(const std::string& prop, const int& defaultValue);

template std::string Config::get(const std::string& prop, const std::string& defaultValue);
