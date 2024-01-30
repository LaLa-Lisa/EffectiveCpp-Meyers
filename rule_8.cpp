/*
 * Правило 8: Не позволяйте исключениям покидать деструкторы.
 *
 * Идея в том, что если в деструкторе может вылететь исключение, то нужно
 * обязательно его поймать, иначе может возникнуть ситуация где летят сразу 2
 * исключения, а плюсы такое не любят.
 *
 * На g++ вылетает: "terminate called after throwing an instance of 'char
 * const*"
 *
 */

#include <iostream>
#include <vector>

void throwing_function() { throw "throw message"; }

class SafeClass {
public:
  ~SafeClass() noexcept {
    std::cout << "start destruction\n";
    try {
      throwing_function();
    } catch (...) {
      std::cout << "excepation catched\n";
    }

    std::cout << "end destruction\n";
  }
};

int main() {
  std::vector<SafeClass> vec(3, SafeClass());
  return 0;
}
