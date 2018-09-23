#include <set>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include "beatmap.hpp"
#include "config.hpp"
#include "utils.hpp"

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
    std::vector<std::string> imageTypes =
            utils::tokenize(conf.get("ImageTypes", std::string(".png .jpg")), ", ");
    return find(imageTypes.begin(), imageTypes.end(), file.extension()) != imageTypes.end();
}

std::vector<fs::path> Beatmap::getBackgrounds() { return mBackgrounds; }

std::vector<fs::path> Beatmap::getVideos() { return mVideos; }