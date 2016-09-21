#include "cuboid.h"
#include <iostream>

using namespace std;

int main() {
        Cuboid<int>* intc = new Cuboid<int>(2,4,5);

        cout << "Testing functions of integer cuboid: " << endl;
        cout << "Volume is: " << intc->getVolume() << endl;
        cout << "Surface area is: " << intc->getSurfaceArea() << endl;

        Cuboid<double>* doublec = new Cuboid<double>(2.2,4.5,5.2);

        cout << "Testing functions of double cuboid: " << endl;
        cout << "Volume is: " << doublec->getVolume() << endl;
        cout << "Surface area is: " << doublec->getSurfaceArea() << endl;

        return 0;
}
