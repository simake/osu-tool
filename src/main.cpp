#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include "beatmapset.hpp"

namespace fs = boost::filesystem;

int main() {
    fs::path bmSetPath = fs::path(
            "../test/beatmapsets/"
            "26886 Korpiklaani - Vodka"
    );
    BeatmapSet bmSet(bmSetPath);

    std::cout << "Title: " << bmSet.getTitle() << "\n"
              << "Artist: " << bmSet.getArtist() << "\n\n";

    for (auto& bm : bmSet.getBeatmaps()) {
        std::cout << "Difficulty: " << bm.getDifficulty() << "\n";
        if (bm.parseSuccess()) {
            std::cout << "Parse successful\n";
        } else {
            std::cout << "Parse failed\n";
        }

        std::cout << "Backgrounds found:\n";
        for (auto& x : bm.getBackgrounds())
            std::cout << "\t" << x << "\n";

        std::cout << "Videos found:\n";
        for (auto& x : bm.getVideos())
            std::cout << "\t" << x << "\n";

        std::cout << "\n";
    }
}
