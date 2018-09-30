#pragma once

#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include "beatmap.hpp"

class BeatmapSet {
  public:
    BeatmapSet(const boost::filesystem::path&);
    void load(const boost::filesystem::path&);
    const std::string& getTitle();
    const std::string& getArtist();
    const std::vector<Beatmap>& getBeatmaps();

  private:
    enum class FileType { IMAGE, VIDEO, OSU };

    bool isType(const boost::filesystem::path& file, FileType type);

    std::string mTitle;
    std::string mArtist;
    std::vector<Beatmap> mBeatmaps;
};
