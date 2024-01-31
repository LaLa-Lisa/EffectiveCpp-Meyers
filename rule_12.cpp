/*
 *
 * Парвило 12: Копируйте все части обькта.
 *
 */

#include <iostream>

class Base {
public:
  int a = 0;
};

class Derived : public Base {
public:
  int b = 1;
  Derived(int _a, int _b) : b(_b) { a = _a; }
  Derived &operator=(const Derived &rhs) {
    b = rhs.b;
    return *this;
  }
};

int main() {
  Derived first(1, 1);
  Derived second(2, 2);
  second = first;
  std::cout << second.a << " " << second.b << '\n';
  return 0;
}
