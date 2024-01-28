/*
Правило 6: Явно запрещайте компилятору генерировать функции, которые вам не
нужны.

Предотвращаем генерацию конструктора и оператора копирования путём помещения их
в private (возможно в базовом классе).
*/
#include <iostream>

class Uncopyable {
public:
  Uncopyable();
  ~Uncopyable();
  // Uncopyable(const Uncopyable&);
private:
  // Uncopyable(const Uncopyable &);
  Uncopyable &operator=(const Uncopyable &);
};

class myClass : private Uncopyable {
  int data = 2;

public:
  myClass() { data = rand(); }
};

int main() {
  std::cout << "Hello, Meyers!\n";

  myClass obj1;
  myClass obj2;

  myClass obj3 = obj2;
  obj1 = obj2; // compilation failture expected

  return 0;
}
