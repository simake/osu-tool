#pragma once

#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include "beatmap.hpp"

class BeatmapSet {
  public:
    BeatmapSet(boost::filesystem::path&);
    void load(boost::filesystem::path&);
    std::string getTitle();
    std::string getArtist();
    std::vector<Beatmap> getBeatmaps();

  private:
    enum class FileType { IMAGE, VIDEO, OSU };

    bool isType(boost::filesystem::path& file, FileType type);

    std::string mTitle;
    std::string mArtist;
    std::vector<Beatmap> mBeatmaps;
};
