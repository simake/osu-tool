#include <iostream>
#include <string>
#include <vector>
#include <boost/tokenizer.hpp>
#include "utils.hpp"

namespace utils {

std::vector<std::string> tokenize(const std::string& str, const std::string& delimiters) {
    std::vector<std::string> tokens;
    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
    boost::char_separator<char> sep(delimiters.data());
    tokenizer tok(str, sep);

    for(tokenizer::iterator it = tok.begin(); it != tok.end(); ++it) {
        tokens.push_back(*it);
    }
    return tokens;
}

}
