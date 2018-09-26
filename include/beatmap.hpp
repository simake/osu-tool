#pragma once

#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include "beatmap.hpp"

class Beatmap {
  public:
    Beatmap(boost::filesystem::path&);
    void parse(boost::filesystem::path&);
    bool parseSuccess();
    std::vector<std::string> getBackgrounds();
    std::vector<std::string> getVideos();

  private:
    void parseEvent(std::string& line);

    bool mParseSuccess;
    std::vector<std::string> mBackgrounds;
    std::vector<std::string> mVideos;
};
