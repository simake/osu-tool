#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <osutool/parsing/beatmap.hpp>

#include "osutool/parsing/beatmap.hpp"
#include "utils.hpp"

namespace fs = boost::filesystem;

Beatmap::Beatmap(const boost::filesystem::path& beatmapPath) {
    parse(beatmapPath);
}

void Beatmap::parse(const boost::filesystem::path& beatmapPath) {
    mPath = beatmapPath;
    fs::fstream file(beatmapPath);
    if (!file.is_open()) {
        mParseSuccess = false;
        std::cerr << "Failed to open " << beatmapPath << "\n";
        return;
    }
    std::string line;
    std::string section;
    while (std::getline(file, line)) {
        size_t commentStart = line.find("//");
        if (commentStart != std::string::npos) {
            line = line.substr(0, commentStart);
        }
        boost::trim_if(line, [](char x) {
            return isspace(x) > 0;
        });
        if (line.empty()) {
            continue;
        }
        if (line[0] == '[' && line[line.length() - 1] == ']') {
            section = line.substr(1, line.length() - 2);
            continue;
        }
        if (section == "Events") {
            parseEvent(line);
        } else if (section == "Metadata") {
            parseMetadata(line);
        }
    }
    file.close();
    mParseSuccess = true;
}

void Beatmap::parseEvent(const std::string& line) {
    std::vector<std::string> tokens = utils::tokenize(line, ",");
    std::string type = tokens[0];
    if (type == "Background" || type == "0") {
        std::string image = tokens[2];
        image = image.substr(1, image.length() - 2); // removing quotes
        mBackgrounds.push_back(image);
    } else if (type == "Video" || type == "1") {
        std::string video = tokens[2];
        video = video.substr(1, video.length() - 2);
        mVideos.push_back(video);
    }
}

void Beatmap::parseMetadata(const std::string& line) {
    std::vector<std::string> tokens = utils::tokenize(line, ":");
    std::string type = tokens[0];
    if (type == "Title") {
        mTitle = tokens[1];
    } else if (type == "Artist") {
        mArtist = tokens[1];
    } else if (type == "Creator") {
        mCreator = tokens[1];
    } else if (type == "Version") { // not a typo
        mDifficulty = tokens[1];
    }
}

bool Beatmap::parseSuccess() const { return mParseSuccess; }

const fs::path& Beatmap::getPath() const { return mPath; }

const std::string& Beatmap::getTitle() const { return mTitle; }

const std::string& Beatmap::getArtist() const { return mArtist; }

const std::string& Beatmap::getCreator() const { return mCreator; }

const std::string& Beatmap::getDifficulty() const { return mDifficulty; }

const std::vector<std::string>& Beatmap::getBackgrounds() const { return mBackgrounds; }

const std::vector<std::string>& Beatmap::getVideos() const { return mVideos; }
