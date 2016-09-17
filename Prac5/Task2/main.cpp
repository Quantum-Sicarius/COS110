#include "CharString.h"
#include <iostream>

int main() {

        std::string str = "bananna";
        char *cstr = &str[0u];

        CharString first(cstr, 7);

        cout << "Testing -operator: " << endl;
        cout << "Result: " << (first-'a') << endl;

        cout << "Testing -=operator: " << endl;
        (first-='a');
        cout << "Result: " << first << endl;

        std::string str2 = "cat";
        char *cstr2 = &str2[0u];

        CharString second(cstr2, 3);

        cout << "Testing +operator: " << endl;
        try {
                cout << "Result: " << (first+second) << endl;
        } catch(Exception e) {
                cout << e.what() << endl;
        }


        cout << "Testing +=operator: " << endl;
        try {
                (first+=second);
        } catch(Exception e) {
                cout << e.what() << endl;

        }
        cout << "Result: " << first << endl;


        std::string str3 = "aaaa";
        char *cstr3 = &str3[0u];
        std::string str4 = "bbbb";
        char *cstr4 = &str4[0u];

        CharString third(cstr3,4);
        CharString forth(cstr4,4);


        cout << "Testing *operator: " << endl;
        try {
                cout << "Result: " << third*forth << endl;
        } catch(Exception e) {
                cout << e.what() << endl;

        }

        std::string str5 = "bananas";
        char *cstr5 = &str5[0u];
        std::string str6 = "and";
        char *cstr6 = &str6[0u];

        CharString fith(cstr5,7);
        CharString six(cstr6,4);

        cout << "Testing /operator: " << endl;
        try {
                cout << "Result: " << endl;
                fith /= six;
                cout << fith << endl;
        } catch(Exception e) {
                cout << e.what() << endl;

        }


        return 0;
}
