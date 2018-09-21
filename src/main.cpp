#include <iostream>
#include <string>
#include <cstring>
#include <boost/filesystem.hpp>
#include "beatmap.hpp"
#include "config.hpp"

namespace fs = boost::filesystem;

int main() {
    fs::path bmPath = fs::path(".");
    Beatmap bm(bmPath);
    std::cout << "Detected images:" << std::endl;
    for (auto &bg : bm.getBackgrounds()) {
        std::cout << bg << "\n";
    }
    std::cout << std::endl;

    Config& conf = Config::getInstance();
    std::cout << conf.get("available", 1337) << "\n";
    std::cout << conf.get("unavailable", std::string("boo")) << std::endl;
}
