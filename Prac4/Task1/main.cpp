#include "titleCase.h"
#include "backwards.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
        titleCase t;
        backwards r;

        string s = "hELLO hOW aRE yOU? AND WHAT ARE YOU DOING? are you the grinch? or a grinch?";
        string ignore = "AND";

        cout << "Testing correction of: " << s << endl;
        cout << "Result: " << t.print(s) << endl;

        cout << "Testing correction of:" << ignore << endl;
        cout << "Result: " << t.print(ignore) << endl;

        s = " ###   hello what is thou name?";
        cout << "Testing correction of:" << s << endl;
        cout << "Result: " << t.print(s) << endl;

        string rev = "hello their my name is jan";

        cout << "Testing reverse of: " << rev << endl;
        cout << "Result: " << r.print(rev) << endl;

        rev = "hello there friend";

        cout << "Testing reverse of: " << rev << endl;
        cout << "Result: " << r.print(rev) << endl;

        return 0;
}
