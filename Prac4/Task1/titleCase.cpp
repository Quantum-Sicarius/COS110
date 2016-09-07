#include "titleCase.h"
#include <algorithm>

std::string trim(std::string& str)
{
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last-first+1));
}

std::string titleCase::print(std::string s) {

        // Trim trailing spaces.
        s = trim(s);

        std::transform(s.begin(), s.end(), s.begin(), ::tolower);

        if (s == "and") {
                return "and";
        } else if (s == "the") {
                return "the";
        } else if (s == "a") {
                return "a";
        } else {
                s[0] = toupper(s[0]);
                return s;

        }
}
