/*
 *
 * Парвило 10: Операторы присвоения должны возвращать ссылку на *this
 *
 * Идея в том, что это не обязательно с точки зрения компилятора, но без этого
 * не будет работать ассоциативность.
 *
 * Распространяется не только на =, но и на *=, +=, -= и тд.
 */

#include <iostream>

class myGoodCopyableClass {
public:
  std::string data;

  myGoodCopyableClass() : data("Upps.. Old String\n") {}
  myGoodCopyableClass(std::string _in) : data(_in) {}
  myGoodCopyableClass &operator=(const myGoodCopyableClass &rhs) {
    data = rhs.data;
    return *this;
  }
};

class myBadCopyableClass {
public:
  std::string data;

  myBadCopyableClass() : data("Upps.. Old String\n") {}
  myBadCopyableClass(std::string _in) : data(_in) {}
  void operator=(const myBadCopyableClass &rhs) { data = rhs.data; }
};

int main() {
  myGoodCopyableClass a, b, c;
  a = b = c = myGoodCopyableClass("Haha, New String\n");
  std::cout << a.data;

  myBadCopyableClass d, e, f;
  d = e = f = myBadCopyableClass("Haha, New String\n");
  std::cout << d.data;
  return 0;
}
