#pragma once

#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include "beatmap.hpp"

class BeatmapSet {
  public:
    BeatmapSet(boost::filesystem::path&);
    void load(boost::filesystem::path&);
    std::vector<Beatmap> getBeatmaps();

  private:
    enum class FileType { IMAGE, VIDEO, OSU };

    bool isType(boost::filesystem::path& file, FileType type);

    std::vector<Beatmap> mBeatmaps;
};
