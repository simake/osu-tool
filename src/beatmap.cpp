#include <iostream> // DEBUG
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/trim.hpp>
#include "beatmap.hpp"
#include "utils.hpp"

namespace fs = boost::filesystem;

Beatmap::Beatmap(boost::filesystem::path& beatmapPath) {
    parse(beatmapPath);
}

void Beatmap::parse(boost::filesystem::path& beatmapPath) {
    fs::fstream file(beatmapPath);
    if (!file.is_open()) {
        mParseSuccess = false;
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
        if (line[0] == '[' && line[line.length()-1] == ']') {
            if (section == "Events") {
                break; // we got what we came for
            }
            section = line.substr(1, line.length()-2);
            continue;
        }
        if (section == "Events") {
            parseEvent(line);
        }
    }
    file.close();
    mParseSuccess = true;
}

void Beatmap::parseEvent(std::string& line) {
    std::vector<std::string> tokens = utils::tokenize(line, ",");
    std::string type = tokens[0];
    if (type == "Background" || type == "0") {
        std::string image = tokens[2];
        image = image.substr(1, image.length()-2); // removing quotes
        mBackgrounds.push_back(image);
    } else if (type == "Video" || type == "1") {
        std::string video = tokens[2];
        video = video.substr(1, video.length()-2);
        mVideos.push_back(video);
    }
}

bool Beatmap::parseSuccess() {
    return mParseSuccess;
}

std::vector<std::string> Beatmap::getBackgrounds() { return mBackgrounds; };

std::vector<std::string> Beatmap::getVideos() { return mVideos; };
