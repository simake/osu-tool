#pragma once

#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include "beatmap.hpp"

class BeatmapSet {
  public:
    BeatmapSet(const boost::filesystem::path&);
    void load(const boost::filesystem::path&);
    const std::string& getTitle() const;
    const std::string& getArtist() const;
    const std::vector<Beatmap>& getBeatmaps() const;

  private:
    std::string mTitle;
    std::string mArtist;
    std::vector<Beatmap> mBeatmaps;
};
