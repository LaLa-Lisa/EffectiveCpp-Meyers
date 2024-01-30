/*
 *
 * Парвило 11: В oprator= осуществляйте проверку на присваивние самому себе.
 *
 * Идея в том, что могут возникнуть неочевидные проблемы с данными если
 * попытаться присвоить себя самому себе.
 *
 * Данный код, к примеру, выдаёт Segmentation fault
 *
 */

class Data {};

class DataHolder {
public:
  Data *data_ptr;
  DataHolder &operator=(const DataHolder &rhs) {
    delete data_ptr;
    data_ptr = rhs.data_ptr;
    return *this;
  }
};

int main() {
  DataHolder dh;
  dh = dh;
  return 0;
}
