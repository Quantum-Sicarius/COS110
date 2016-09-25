#include "SubstitutionCipher.h"

std::string SubstitutionCipher::encode(std::string s) {
        std::string result = s;

        for (size_t i = 0; i < s.length(); i++) {
                result[i] = encodeChar(s[i]);
        }

        return result;
}
std::string SubstitutionCipher::decode(std::string s) {
        std::string result = s;

        for (size_t i = 0; i < s.length(); i++) {
                result[i] = decodeChar(s[i]);
        }

        return result;
}
