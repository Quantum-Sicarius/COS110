#include "xAxis.h"

int main() {
        string* labels = new string[3];
        labels[0] = "one";
        labels[1] = "two";
        labels[2] = "three";

        double* values = new double[3];
        values[0] = 2.3;
        values[1] = 1.2;
        values[2] = 2.2;

        xAxis x(3, labels, values);

        cout << "==================================" << endl;
        x.display();
        cout << "==================================" << endl;

        x.changeLabel("one", "oneChanged");
        x.changeLabel("two", "twoChanged");
        x.changeLabel("three", "threeChanged");

        x.display();
        cout << "==================================" << endl;

        x.increaseValueBy("oneChanged", 0.7);
        x.decreaseValueBy("twoChanged", 0.2);

        x.display();
        cout << "================= TEST EXTEND ==================" << endl;

        x.extend(9.9, "four");
        x.extend(3.9, "five");

        x.display();
        cout << "================= TEST SHORTEN =================" << endl;

        x.shorten();

        x.display();
        cout << "================= TEST DELETE ==================" << endl;

        x.deleteNode("oneChanged");
        x.display();
        cout << "==================================" << endl;

        return 0;
}
