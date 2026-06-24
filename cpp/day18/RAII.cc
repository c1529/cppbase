#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
// 智能指针的雏形
template <class Type> class RAII {
public:
  RAII(Type *p) : _p(p) { cout << "RAII(Type)" << endl; }
  ~RAII() {
    if (_p) {
      delete _p;
      _p = nullptr;
    }
    cout << "~RAIII()" << endl;
  }
  Type *operator->() { return _p; }
  Type &operator*() { return *_p; }
  Type *get() const { return _p; }
  RAII(const RAII &) = delete;
  RAII &operator=(const RAII &) = delete;

private:
  Type *_p; // 托管的是对空间的资源
};
class Point {
public:
  Point(int ix = 0, int iy = 0) : _ix(ix), _iy(iy) {
    cout << "Point(int,int)" << endl;
  }
  void print() { cout << "(" << _ix << "," << _iy << ")" << endl; }
  ~Point() { cout << "~Point()" << endl; }

private:
  int _ix;
  int _iy;
};
void test0() {
  RAII<Point> raii(new Point(1, 2));
  raii->print();
  (*raii).print();
}
int main() {
  test0();
  return 0;
}
