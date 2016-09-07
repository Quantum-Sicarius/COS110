#include "backwards.h"
#include <sstream>
#include <vector>

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
        std::stringstream ss;
        ss.str(s);
        std::string item;
        while (getline(ss, item, delim)) {
                elems.push_back(item);
        }
}

std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
}

std::string reverse(std::string s) {
        std::string reverse = s;

        for (size_t i = 0; i < s.size(); i++) {
                reverse[i] = s[s.size() - (i+1)];
        }

        return reverse;
}

std::string backwards::print(std::string s) {

        std::string reversedString;

        std::vector<std::string> v;
        split(s, ' ', v);

        for (size_t i = 0; i < v.size(); i++) {
                reversedString += reverse(v.at(i));
                reversedString += " ";
        }

        return reversedString;
}
