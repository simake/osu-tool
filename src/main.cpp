#include <iostream>
#include "beatmap.hpp"
#include <string>
#include <cstring>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

int main() {
    fs::path path = fs::path(".");
    Beatmap bm(path);
    std::cout << "Detected images:\n";
    for (auto &bg : bm.getBackgrounds()) {
        std::cout << bg << "\n";
    }
}
