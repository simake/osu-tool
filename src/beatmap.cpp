#include <set>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include "beatmap.hpp"
#include "config.hpp"
#include "utils.hpp"

namespace fs = boost::filesystem;

Beatmap::Beatmap(fs::path& beatmapDir) {
    parse(beatmapDir);
}

void Beatmap::parse(fs::path& beatmapDir) {
    for (const fs::directory_entry& de : fs::directory_iterator(beatmapDir)) {
        fs::path p = de.path();
        if (isType(p, FileType::IMAGE)) {
            mBackgrounds.push_back(p);
        }
        if (isType(p, FileType::VIDEO)) {
            mVideos.push_back(p);
        }
    }
}

bool Beatmap::isType(fs::path& file, FileType type) {
    std::string confProperty;
    std::string defaults;
    switch (type) {
        case FileType::IMAGE:
            confProperty = "ImageTypes";
            defaults = ".png .jpg";
            break;
        case FileType::VIDEO:
            confProperty = "VideoTypes";
            defaults = "";
    }
    Config& conf = Config::getInstance();
    std::vector<std::string> types = utils::tokenize(conf.get(confProperty, defaults), ", ");
    return find(types.begin(), types.end(), file.extension()) != types.end();
}

std::vector<fs::path> Beatmap::getBackgrounds() { return mBackgrounds; }

std::vector<fs::path> Beatmap::getVideos() { return mVideos; }