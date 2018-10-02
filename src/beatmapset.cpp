#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include "beatmapset.hpp"
#include "beatmap.hpp"
#include "utils.hpp"

namespace fs = boost::filesystem;

BeatmapSet::BeatmapSet(const fs::path& beatmapDir) {
    load(beatmapDir);
}

void BeatmapSet::load(const fs::path& beatmapDir) {
    mBeatmaps.clear();
    for (const fs::directory_entry& de : fs::directory_iterator(beatmapDir)) {
        const fs::path& p = de.path();
        if (p.extension() == ".osu") {
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

const std::vector<Beatmap>& BeatmapSet::getBeatmaps() const { return mBeatmaps; }

const std::string& BeatmapSet::getTitle() const { return mTitle; }

const std::string& BeatmapSet::getArtist() const { return mArtist; }
