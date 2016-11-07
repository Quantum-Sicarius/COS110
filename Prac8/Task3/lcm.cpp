#include <cmath> // std::abs

/*
 * gcd(a, b) = gcd(b, a%b)
 */
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int lcm(int a, int b) {
  if (a == 0) {
    return 0;
  }
  return (std::abs(a * b) / gcd(a, b));
}
int lcm(int a, int b, int c) { return lcm(a, lcm(b, c)); }
/*
 * lcm(a, b) = (|a ∗ b|) / (gcd(a, b))
 * Hint: lcm(a, b, c)= lcm (a, lcm(b, c));
 * My attempt at full recursion
 */
/*int lcm(int *numbers, int length) {

  if (length == 0) {
    return 0;
  } else if (length == 1) {
    return numbers[0];
  } else if (length == 2) {
    return lcm(numbers[0], numbers[1]);
  } else if (length == 3) {
    return lcm(numbers[0], numbers[1], numbers[2]);
  } else {
    std::vector<int> v(numbers, numbers + sizeof numbers / sizeof numbers[0]);
    v.erase(v.begin());
    // std::rotate(v.begin(), v.begin() + 1, v.end());
    int arg0 = v[0];
    int *newNumber = &v[0];
    return lcm(arg0, lcm(newNumber, length - 1));
  }
}*/

int lcm(int *number, int len) {
  if (len == 0) {
    return 0;
  }
  long result = number[0];
  for (int i = 1; i < len; i++) {
    result = lcm(result, number[i]);
  }
  return result;
}
