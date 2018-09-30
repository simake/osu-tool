#pragma once

#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include "beatmap.hpp"

class Beatmap {
  public:
    Beatmap(const boost::filesystem::path&);
    bool parseSuccess();
    const boost::filesystem::path& getPath();
    const std::string& getTitle();
    const std::string& getArtist();
    const std::string& getCreator();
    const std::string& getDifficulty();
    const std::vector<std::string>& getBackgrounds();
    const std::vector<std::string>& getVideos();

  private:
    void parse(const boost::filesystem::path&);
    void parseEvent(const std::string& line);
    void parseMetadata(const std::string& line);

    bool mParseSuccess;
    boost::filesystem::path mPath;
    std::string mTitle;
    std::string mArtist;
    std::string mCreator;
    std::string mDifficulty;
    std::vector<std::string> mBackgrounds;
    std::vector<std::string> mVideos;
};
