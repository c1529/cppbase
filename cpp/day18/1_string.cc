#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::vector;
class String {
public:
  String(const char *pstr) : _pstr(new char[strlen(pstr) + 1]()) {
    cout << "String(const char *)" << endl;
    strcpy(_pstr, pstr);
  }
  String(const String &rhs) : _pstr(new char[strlen(rhs._pstr) + 1]()) {
    cout << "String(const String &)" << endl;
    strcpy(_pstr, rhs._pstr);
  }
  String &operator=(const String &rhs) {
    cout << "String & operator=(const String &)" << endl;
    if (this != &rhs) {
      delete[] _pstr;
      _pstr = new char[strlen(rhs._pstr) + 1]();
      strcpy(_pstr, rhs._pstr);
    }
    return *this;
  }
  // 移动构造函数  右值引用
  String(String &&rhs)
      : _pstr(rhs._pstr) // 浅拷贝
  {
    rhs._pstr = nullptr;
    cout << "String(String&&)" << endl;
  }
  // 移动赋值函数
  String &operator=(String &&rhs) {
    cout << "String & operator=(String &&)" << endl;
    delete[] _pstr;
    _pstr = rhs._pstr;
    rhs._pstr = nullptr;
    return *this;
  }
  ~String() {
    if (_pstr) {
      delete[] _pstr;
      _pstr = nullptr;
    }
    cout << "~String()" << endl;
  }
  friend ostream &operator<<(ostream &os, const String &rhs);
  bool isnull() {
    if (_pstr == nullptr) {
      return false;
    } else {
      return true;
    }
  }

private:
  char *_pstr;
};
ostream &operator<<(ostream &os, const String &rhs) {
  os << rhs._pstr;
  return os;
}
void test0() {
  vector<String> strs;
  strs.push_back("hello");
}
void test1() {
  String &&ref = String("hello");
  cout << "ref = " << ref << endl;
}
void test2() {
  String str1("hello");
  cout << "str1 = " << str1 << endl;
  str1 = String("world");
  cout << "str1 = " << str1 << endl;
}
void test3() {
  String s1("hello");
  String s2(std::move(s1));
  if (s1.isnull()) {
    cout << "s1 = " << s1 << endl;
  } else {
    cout << "s1 is nullptr!!!!!!!!!!!!!!!!" << endl;
  }
}
int main() {
  // test0();
  // test1();
  // test2();
  test3();
  return 0;
}
