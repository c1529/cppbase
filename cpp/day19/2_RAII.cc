#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
template <class Type> struct MyDefaultDelter {
  void operator()(Type *type) const {
    delete type;
    cout << "MyDefaultDelter" << endl;
  }
};
template <class Type, class Deleter = MyDefaultDelter<Type>> class RAII {
public:
  RAII(Type *p) : _p(p) {}
  ~RAII() {
    if (_p) {
      // delete _p;
      deleter(_p);
      _p = nullptr;
    }
  }
  Type *operator->() { return _p; }
  Type &operator*() { return *_p; }
  Type *get() const { return _p; }
  // 从类中删除该函数就不能执行赋值或者复制
  RAII(const RAII &) = delete;
  RAII &operator=(const RAII &) = delete;

private:
  Type *_p;
  Deleter deleter;
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
  Point *p1 = new Point(1, 2);
  p1->print();
  MyDefaultDelter<Point> del;
  del(p1);
  cout << "123456789" << endl;
}
void test1() {
  RAII<Point> raii(new Point(10, 100));
  raii->print();
  /*
      Point *p1 =new Point(3,4);
      p1->print();
      delete p1;
  */
}
int main() {
  // test0();
  test1();
  return 0;
}
