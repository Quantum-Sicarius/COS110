#include "OneTimePad.h"

#include <iostream>

using namespace std;

int main() {

        std::string plaintext = "{{ Hello World! }}";

        Caesar* c = new Caesar();
        string result;

        cout << "Test shift of 3" << endl;
        cout << "Should be: " << endl;
        cout << "~~#Khoor#Zruog$#!!" << endl;

        c->setShift(3);

        cout << c->encode(plaintext) << endl;

        cout << "Test shift of 15" << endl;
        cout << "Should be: " << endl;
        cout << "++/Wt{{~/f~\"{s0/--" << endl;
        c->setShift(15);
        result = c->encode(plaintext);
        cout << result << endl;

        cout << "Test decode: " << endl;
        cout << c->decode(result) << endl;

        OneTimePad* oneTimePad = new OneTimePad(1);
        cout << "Testing onetime pad with a seed of 1" << endl;
        cout << "Should be: "<< endl;
        cout << "r!b`wW}ClDz%:QS55c" << endl;

        result = oneTimePad->encode(plaintext);
        cout << result << endl;

        cout << "Test decode: " << endl;
        cout << oneTimePad->decode(result) << endl;

        cout << "Testing onetime pad with a seed of 9999" << endl;
        cout << "Should be: "<< endl;
        cout << "E,Db`WsdAhviX(mvdP" << endl;
        oneTimePad->setSeed(9999);
        result = oneTimePad->encode(plaintext);
        cout << result << endl;

        cout << "Test decode: " << endl;
        cout << oneTimePad->decode(result) << endl;

        return 0;
}
