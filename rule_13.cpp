/*
 *
 * Парвило 13: Используйте обьекты для управления ресурсами.
 *
 */

#include <iostream>
#include <memory>

class Data {
public:
  std::string name;
  Data(std::string _name) : name(_name) {}
  ~Data() { std::cout << "Destroied data from " << name << "\n"; }
};

class DataHolder {
public:
  Data *data_ptr;
  explicit DataHolder(Data *ptr) { data_ptr = ptr; }
  ~DataHolder() { delete data_ptr; }
};

Data *data_producer(std::string data_name) { return new Data(data_name); }

int main() {
  DataHolder holder(data_producer("DataHolder"));
  std::shared_ptr<Data> sh_ptr(data_producer("shared_ptr"));
  return 0;
}
