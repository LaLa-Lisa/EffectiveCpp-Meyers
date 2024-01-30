/*
 *
 * Правило 9: Никогда не вызывайте виртуальные функии в конструкторе или
 * деструкторе.
 *
 * Идея в том, классе наследнике снчала вызывается конструктор базового класса и
 * пока он не завершит свою работу, язык будет считать, что объект принадлежит к
 * базовому классу и поэтому виртуальные функции ещё будут не переопределены.
 *
 */

#include <iostream>

class Base {
public:
  Base() {
    std::cout << "I'm in Constructor! ";
    mistery_print();
  }

  ~Base() {
    std::cout << "I'm in Destructor! ";
    mistery_print();
  }

  virtual void mistery_print() { std::cout << "I'm from Base class\n"; }
};

class Derived : public Base {
public:
  void mistery_print() override {
    std::cout << "I'm already from Derived class\n";
  }
};

int main() {
  Derived object;
  return 0;
}
