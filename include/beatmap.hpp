#pragma once

#include <vector>
#include <string>
#include <boost/filesystem.hpp>

class Beatmap {
  public:
    Beatmap(boost::filesystem::path&);
    void parse(boost::filesystem::path&);
    std::vector<boost::filesystem::path> getBackgrounds();
    std::vector<boost::filesystem::path> getVideos();

  private:
    bool isImage(boost::filesystem::path&);
    std::vector<boost::filesystem::path> mBackgrounds;
    std::vector<boost::filesystem::path> mVideos;
};
