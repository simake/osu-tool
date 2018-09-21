#include <set>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include "beatmap.hpp"
#include "config.hpp"

namespace fs = boost::filesystem;

//static const std::set<std::string> IMAGE_TYPES = {".png", ".jpg"};

Beatmap::Beatmap(fs::path& beatmapDir) {
    parse(beatmapDir);
}

void Beatmap::parse(fs::path& beatmapDir) {
    for (const fs::directory_entry& de : fs::directory_iterator(beatmapDir)) {
        fs::path p = de.path();
        if (isImage(p)) {
            mBackgrounds.push_back(p);
        }
    }
}

bool Beatmap::isImage(fs::path& file) {
    Config& conf = Config::getInstance();
    std::string imageTypes = conf.get("ImageTypes", std::string(".png .jpg")).split(); // TODO
    return imageTypes.contains(file.extension()) // TODO
    //return IMAGE_TYPES.find(path.extension().string()) != IMAGE_TYPES.end();
}

std::vector<fs::path> Beatmap::getBackgrounds() { return mBackgrounds; }

std::vector<fs::path> Beatmap::getVideos() { return mVideos; }