#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include "beatmapset.hpp"
#include "config.hpp"
#include "utils.hpp"

namespace fs = boost::filesystem;

int main() {
    fs::path bmPath = fs::path(
            "osumaps/"
            "28565 Hyadain - Hyadain no Kakakata Kataomoi-C (TV Size)/"
            "Hyadain - Hyadain no Kakakata Kataomoi-C (TV Size) (Sushi) [Takuma_s Insane].osu"
    );
    Beatmap bm(bmPath);

    if (bm.parseSuccess()) {
        std::cout << "Parse successful\n\n";
    } else {
        std::cout << "Parse failed\n\n";
    }

    std::cout << "Backgrounds found:\n";
    for (auto& x : bm.getBackgrounds())
        std::cout << x << "\n";
    std::cout << "\n";

    std::cout << "Videos found:\n";
    for (auto& x : bm.getVideos())
        std::cout << x << "\n";
    std::cout << "\n";
}
