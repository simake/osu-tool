#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/filesystem/path.hpp>
#include <string>
#include <vector>
#include "beatmap.hpp"
#include "beatmapset.hpp"

namespace fs = boost::filesystem;

const std::string BEATMAPSETS_PATH = "../test/beatmapsets/";


BOOST_AUTO_TEST_SUITE(Beatmap_tests)

BOOST_AUTO_TEST_CASE(Still_Alive_Easy) {
    Beatmap bm(BEATMAPSETS_PATH + "92 Portal - Still Alive/"
                                  "Portal - Still Alive (Hitoshirenu Shourai) [Easy].osu");

    BOOST_REQUIRE(bm.parseSuccess());
    BOOST_CHECK_EQUAL(bm.getTitle(), "Still Alive");
    BOOST_CHECK_EQUAL(bm.getArtist(), "Portal");
    BOOST_CHECK_EQUAL(bm.getCreator(), "Hitoshirenu Shourai");
    BOOST_CHECK_EQUAL(bm.getDifficulty(), "Easy");

    std::vector<std::string> actualBackgrounds = bm.getBackgrounds();
    std::vector<std::string> expectedBackgrounds = {"portal.PNG"};
    BOOST_CHECK_EQUAL_COLLECTIONS(actualBackgrounds.begin(), actualBackgrounds.end(),
                                  expectedBackgrounds.begin(), expectedBackgrounds.end());

    std::vector<std::string> actualVideos = bm.getVideos();
    std::vector<std::string> expectedVideos = {};
    BOOST_CHECK_EQUAL_COLLECTIONS(actualVideos.begin(), actualVideos.end(),
                                  expectedVideos.begin(), expectedVideos.end());
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(BeatmapSet_tests)

BOOST_AUTO_TEST_CASE(Still_Alive) {
    BeatmapSet bmSet(BEATMAPSETS_PATH + "92 Portal - Still Alive");
    // Perform relevant tests
}

BOOST_AUTO_TEST_SUITE_END()
