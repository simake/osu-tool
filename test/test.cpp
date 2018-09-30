#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <string>
#include <vector>
#include "beatmap.hpp"
#include "beatmapset.hpp"

const std::string BEATMAPSETS_PATH = "../test/beatmapsets/";


void testBeatmap(Beatmap& bm, const std::string& expTitle, const std::string& expArtist,
                 const std::string& expCreator, const std::string& expDifficulty,
                 const std::vector<std::string>& expBackgrounds, const std::vector<std::string>& expVideos) {

    BOOST_REQUIRE(bm.parseSuccess());
    BOOST_CHECK_EQUAL(bm.getTitle(), expTitle);
    BOOST_CHECK_EQUAL(bm.getArtist(), expArtist);
    BOOST_CHECK_EQUAL(bm.getCreator(), expCreator);
    BOOST_CHECK_EQUAL(bm.getDifficulty(), expDifficulty);

    BOOST_CHECK_EQUAL_COLLECTIONS(bm.getBackgrounds().begin(), bm.getBackgrounds().end(),
                                  expBackgrounds.begin(), expBackgrounds.end());

    BOOST_CHECK_EQUAL_COLLECTIONS(bm.getVideos().begin(), bm.getVideos().end(),
                                  expVideos.begin(), expVideos.end());
}

void testBeatmapSet(BeatmapSet& bmSet, const std::string& expTitle,
                    const std::string& expArtist, int expBeatmapsAmount) {
    BOOST_CHECK_EQUAL(bmSet.getTitle(), expTitle);
    BOOST_CHECK_EQUAL(bmSet.getArtist(), expArtist);
    BOOST_CHECK_EQUAL(bmSet.getBeatmaps().size(), expBeatmapsAmount);
}


BOOST_AUTO_TEST_SUITE(Beatmap_tests)

BOOST_AUTO_TEST_CASE(Still_Alive_Easy) {
    Beatmap bm(BEATMAPSETS_PATH + "92 Portal - Still Alive/Portal - Still Alive (Hitoshirenu Shourai) [Easy].osu");
    testBeatmap(bm, "Still Alive", "Portal", "Hitoshirenu Shourai", "Easy", {"portal.PNG"}, {});
}

BOOST_AUTO_TEST_CASE(Vodka_Insane) {
    Beatmap bm(BEATMAPSETS_PATH + "26886 Korpiklaani - Vodka/Korpiklaani - Vodka (Charles445) [Insane].osu");
    testBeatmap(bm, "Vodka", "Korpiklaani", "Charles445", "Insane",
                {"bgpic1.jpg"}, {"KORPIKLAANI - Vodka [www.Keep-Tube.com].avi"});
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(BeatmapSet_tests)

BOOST_AUTO_TEST_CASE(Still_Alive) {
    BeatmapSet bmSet(BEATMAPSETS_PATH + "92 Portal - Still Alive");
    testBeatmapSet(bmSet, "Still Alive", "Portal", 2);
}

BOOST_AUTO_TEST_CASE(Vodka) {
    BeatmapSet bmSet(BEATMAPSETS_PATH + "26886 Korpiklaani - Vodka");
    testBeatmapSet(bmSet, "Vodka", "Korpiklaani", 5);
}

BOOST_AUTO_TEST_SUITE_END()
