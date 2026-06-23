#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
template <class T> T add(T a, T b) { return a + b; }
// 模板的全特化
template <>
const char *add<const char *>(const char *pstr1, const char *pstr2) {
  char *ptmp = new char[strlen(pstr1) + strlen(pstr2) + 1]();
  strcpy(ptmp, pstr1);
  strcat(ptmp, pstr2);
  return ptmp;
}
template <class T1 = double, int base = 100> T1 multiply(T1 x, T1 y) {
  return x * y * base;
}
void test0() {
  int i1 = 2, i2 = 3;
  float f1 = 1.1, f2 = 3.2;
  double d1 = 1.1111111, d2 = 3.78897987;
  cout << add(i1, i2) << endl;
  cout << add(f1, f2) << endl;
  cout << add(d1, d2) << endl;
  const char *p1 = "hello";
  const char *p2 = "world";
  cout << add(p1, p2) << endl;
  cout << "" << endl;
  cout << "template <class T1.int base>" << endl;
  cout << multiply<float, 10>(3.14, 2) << endl;
}
int main() {
  test0();
  return 0;
}
