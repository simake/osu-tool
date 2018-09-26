#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include "beatmapset.hpp"
#include "beatmap.hpp"
#include "config.hpp"
#include "utils.hpp"

namespace fs = boost::filesystem;

BeatmapSet::BeatmapSet(fs::path& beatmapDir) {
    load(beatmapDir);
}

void BeatmapSet::load(fs::path& beatmapDir) {
    mBeatmaps.clear();
    for (const fs::directory_entry& de : fs::directory_iterator(beatmapDir)) {
        fs::path p = de.path();
        if (isType(p, FileType::OSU)) {
            mBeatmaps.emplace_back(Beatmap(p));
        }
    }
    for (auto& bm : mBeatmaps) {
        if (bm.parseSuccess()) {
            mTitle = bm.getTitle();
            mArtist = bm.getArtist();
            return;
        }
    }
    std::cerr << "No successfully parsed beatmaps "
              << "to get title/artist from.\n";
    mTitle = "N/A";
    mArtist = "N/A";
}

bool BeatmapSet::isType(fs::path& file, FileType type) {
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
            break;
        case FileType::OSU:
            return file.extension() == ".osu";
    }
    Config& conf = Config::getInstance();
    std::string str = conf.get(confProperty, defaults);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::vector<std::string> types = utils::tokenize(str, ", ");
    std::string ext = file.extension().string();
    transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    return find(types.begin(), types.end(), ext) != types.end();
}

std::vector<Beatmap> BeatmapSet::getBeatmaps() { return mBeatmaps; }

std::string BeatmapSet::getTitle() { return mTitle; }

std::string BeatmapSet::getArtist() { return mArtist; }
