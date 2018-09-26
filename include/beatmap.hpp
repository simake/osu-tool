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
    std::string getTitle();
    std::string getArtist();
    std::string getCreator();
    std::string getDifficulty();
    std::vector<std::string> getBackgrounds();
    std::vector<std::string> getVideos();

  private:
    void parseEvent(std::string& line);
    void parseMetadata(std::string& line);

    bool mParseSuccess;
    boost::filesystem::path mPath;
    std::string mTitle;
    std::string mArtist;
    std::string mCreator;
    std::string mDifficulty;
    std::vector<std::string> mBackgrounds;
    std::vector<std::string> mVideos;
};
