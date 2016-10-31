#include "doubleList.h"
#include <iostream>

using namespace std;

int main() {
  // Write code to test your implementation.

  int nums[9] = {12, 25, 36, 42, 58, 68, 73, 89, 97};
  int n = 0;
  DoubleList<int> dlist1;

  cout << "-----------insert------------" << endl;

  try {
    dlist1.insert(0, nums[n]);
    n++;
    dlist1.insert(1, nums[n]);

    cout << dlist1 << endl;
  } catch (const char *s) {
    cout << "ERROR: " << s << endl;
  }

  cout << "-----copy constructor---------------" << endl;

  DoubleList<int> *dlist2 = new DoubleList<int>(dlist1);
  cout << *dlist2 << endl;

  cout << "-----------get------------" << endl;
  try {
    cout << "index: 1 " << dlist1.get(1) << dlist1 << endl;

  } catch (const char *s) {
    cout << "ERROR: " << s << endl;
  }

  cout << "-----------operator[]------------" << endl;
  try {
    cout << "index: -1" << dlist1[-1] << endl;

  } catch (const char *s) {
    cout << "ERROR: " << s << endl;
  }

  cout << "-----------remove------------" << endl;
  try {

    cout << dlist1.remove(1) << " -> " << dlist1 << endl;
  } catch (const char *s) {
    cout << "ERROR: " << s << endl;
  }

  cout << "-----------operator=------------" << endl;
  dlist1 = *dlist2;
  cout << dlist1 << endl;

  cout << "-----------operator+------------" << endl;
  DoubleList<int> dlist3 = dlist1 + *dlist2;
  cout << dlist3 << endl;

  return 0;
}
