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

        cout << "Testing /=operator: " << endl;
        try {
                cout << "Result: ";
                fith /= six;
                cout << fith << endl;
        } catch(Exception e) {
                cout << e.what() << endl;

        }

        std::string str7 = "dog";
        char *cstr7 = &str7[0u];
        std::string str8 = "dog";
        char *cstr8 = &str8[0u];

        CharString seven(cstr7,3);
        CharString eight(cstr8,3);

        cout << "Testing ==operator: " << endl;
        try {
                cout << "Result: should be 1 ";
                cout << (seven == eight) << endl;

                cout << "Result: should be 0 ";
                cout << (seven == six) << endl;
        } catch(Exception e) {
                cout << e.what() << endl;

        }

        cout << "Test all errors: " << endl;
        try {
                cout << "Test out of bounds: " << endl;
                first[10000];
        } catch (Exception e) {
                cout << "Exception thrown: ";
                cout << e.what() << endl;
        }

        std::string str9 = "";
        char *cstr9 = &str9[0u];

        CharString nine(cstr9,0);

        try {
                cout << "Test empty: " << endl;
                nine / eight;
        } catch (Exception e) {
                cout << "Exception thrown: ";
                cout << e.what() << endl;
        }

        std::string str10 = "a";
        char *cstr10 = &str10[0u];

        CharString ten(cstr10,1);

        try {
                cout << "Test result empty: " << endl;
                ten - 'a';
        } catch (Exception e) {
                cout << "Exception thrown: ";
                cout << e.what() << endl;
        }

        try {
                cout << "Test character not found: " << endl;
                ten - 'b';
        } catch (Exception e) {
                cout << "Exception thrown: ";
                cout << e.what() << endl;
        }


        return 0;
}
