/*
 * Copyright (c) 2016, Thomas Scholtz
 * All rights reserved.
 */
#include "titleCase.h"
#include <algorithm>



std::string titleCase::print(std::string s) {

        //std::string special = "!@#$%^&*()_+-={}|:">?<,.\/;'[]\~`';

        // Trim trailing spaces.
        s = trim(s);

        std::transform(s.begin(), s.end(), s.begin(), ::tolower);


        std::string capitalised = "";

        std::vector<std::string> v;
        split(s, ' ', v);

        std::string temp;

        for (size_t i = 0; i < v.size(); i++) {
                temp = v.at(i);
                if (temp == "and") {
                        capitalised += "and";
                } else if (temp == "the") {
                        capitalised += "the";
                } else if (temp == "a") {
                        capitalised += "a";
                } else {
                        temp[0] = toupper(temp[0]);
                        capitalised += temp;
                }
                capitalised += " ";
        }
        return capitalised;


}
