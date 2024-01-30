/*
  Правило 7: Объявляйте деструкторы виртуальными в полиморфном базовом классе.

  Идея в том, что бы в классе которые будет базовым сделать деструктор virtual
  Если у класса есть свой базовый класс в котором не virtual деструктор, то
  деструктор этого класса тоже не стоит делать virtual, иначе ub

*/

#include <iostream>

class A {
public:
  int data;
  virtual ~A() { std::cout << "A destructed\n"; }
};

class B : public A {
public:
  virtual ~B() { std::cout << "B destructed\n"; }
};

int main() {
  B b;
  A *a = new B();

  delete a;
  return 0;
}
