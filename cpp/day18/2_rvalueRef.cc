#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
void test0() {
  int a = 10;
  int &ref1 = a;
  cout << "ref1 = " << ref1 << endl;

  int &&ref2 = 100;
  cout << "ref2 = " << ref2 << endl;
}
int main() {
  test0();
  return 0;
}
