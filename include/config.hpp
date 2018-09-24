#pragma once

#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

class Config {
  public:
    static Config& getInstance();
    template<class T>
    T get(const std::string& prop, const T& defaultValue);
    void loadFile(const std::string& path);

    Config(const Config&) = delete;
    void operator=(const Config&) = delete;

  private:
    boost::property_tree::ptree mProperties;

    Config();
};
