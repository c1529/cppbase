#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
class SafeFile {
public:
  SafeFile(FILE *fp) : _fp(fp) { cout << "SafeFile(FILE *)" << endl; }

  void write(const string &msg) { fwrite(msg.c_str(), 1, msg.size(), _fp); }

  ~SafeFile() {
    if (_fp) {
      fclose(_fp);
      cout << ">>fclose(fp)" << endl;
    }
    cout << "~SafeFile()" << endl;
  }

private:
  FILE *_fp;
};
void test0() {
  SafeFile sf1(fopen("text.txt", "a+"));
  string msg("this is test\n");
  sf1.write(msg);
}
int main() {
  test0();
  return 0;
}
