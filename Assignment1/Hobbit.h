/* 
 * Class Hobbit
 */

#ifndef HOBBIT_H
#define	HOBBIT_H

#include "string"
using namespace std;

class Hobbit{
private:
    string name;
public:
    Hobbit();
    ~Hobbit();
    void setName(string n);
    string getName() const;
};

#endif	/* HOBBIT_H */

