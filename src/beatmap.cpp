#include <vector>
#include <boost/filesystem.hpp>
#include "beatmap.hpp"

namespace fs = boost::filesystem;

Beatmap::Beatmap(fs::path &path) {
    parse(path);
}

void Beatmap::parse(fs::path &path) {
    for (auto &p : fs::directory_iterator(path)) {
        mBackgrounds.push_back(p);
    }
}

std::vector<fs::path> Beatmap::getBackgrounds() { return mBackgrounds; }

std::vector<fs::path> Beatmap::getVideos() { return mVideos; }