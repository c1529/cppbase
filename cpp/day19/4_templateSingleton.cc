// 单例模式
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
template <class T> class Singleton {
public:
  template <class... Args> static T *getInstance(Args... args) {
    if (nullptr == _pInstance) {
      _pInstance = new T(args...);
    }
    return _pInstance;
  }

private:
  Singleton() {}
  ~Singleton() {}

private:
  static T *_pInstance;
};
template <class T> T *Singleton<T>::_pInstance = nullptr;
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
  Point *pt1 = Singleton<Point>::getInstance(1, 2);
  Point *pt2 = Singleton<Point>::getInstance(10, 100);
  cout << "pt1:" << pt1 << endl;
  cout << "pt2:" << pt2 << endl;
  cout << "pt1->print() = ";
  pt1->print();
  cout << "pt2->print() = ";
  pt2->print();
}
int main() {
  test0();
  return 0;
}
