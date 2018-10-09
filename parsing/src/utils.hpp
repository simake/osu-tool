#pragma once

#include <string>
#include <vector>

namespace utils {

std::vector<std::string> tokenize(const std::string& str, const std::string& delimiters);

}