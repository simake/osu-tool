#pragma once

#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include "beatmap.hpp"

namespace osutool {
namespace parsing {

class Beatmap {
  public:
    Beatmap();
    Beatmap(const boost::filesystem::path&);
    void parse(const boost::filesystem::path&);
    bool parseSuccess() const;
    const boost::filesystem::path& getPath() const;
    const std::string& getTitle() const;
    const std::string& getArtist() const;
    const std::string& getCreator() const;
    const std::string& getDifficulty() const;
    const std::vector<std::string>& getBackgrounds() const;
    const std::vector<std::string>& getVideos() const;

  private:
    void parseEvent(const std::string& line);
    void parseMetadata(const std::string& line);

    bool mParseSuccess = false;
    boost::filesystem::path mPath;
    std::string mTitle;
    std::string mArtist;
    std::string mCreator;
    std::string mDifficulty;
    std::vector<std::string> mBackgrounds;
    std::vector<std::string> mVideos;
};

}
}
