/* 
 * main function to test code
 */

#include <cstdlib>
#include <iostream>
#include "Wizard.h"
#include "Spell.h"
using namespace std;

int main() {
    Wizard wiz;
    Spell s1("vanishing",3,1);
    wiz.addSpell(s1);
    wiz + s1;
    
    //test your other code here
    return 0;
}

