#include <iostream>
#include <memory>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::vector;
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
  Point *pt = new Point(1, 2);
  unique_ptr<Point> up(pt);
  cout << "up.get() = " << up.get() << endl;
  cout << "pt       = " << pt << endl;
  up->print();
  (*up).print();
  cout << endl;
  // unique_ptr不能进行复制或者赋值的
  // unique_ptr<Point> up2 = up;
  cout << endl;
}
void test1() {
  Point *pt = new Point(1, 2);
  shared_ptr<Point> sp(pt);
  cout << "sp.get() = " << sp.get() << endl;
  cout << "pt       = " << pt << endl;
  cout << "sp.use_count() = " << sp.use_count() << endl;
  sp->print();
  (*sp).print();
  cout << endl;
  shared_ptr<Point> sp2 = sp;
  cout << "sp2.get() = " << sp2.get() << endl;
  cout << "sp.get()  = " << sp.get() << endl;
  cout << "sp2.use_count() = " << sp2.use_count() << endl;
  cout << "sp.use_count() = " << sp.use_count() << endl;
#if 0
  sp2 = new Point(10, 100);
  cout << "sp2 = new Point(10,100)" << endl;
  cout << "sp2.get() = " << sp2.get() << endl;
  cout << "sp.get()  = " << sp.get() << endl;
  cout << "sp2.use_count() = " << sp2.use_count() << endl;
  cout << "sp.use_count() = " << sp.use_count() << endl;
#endif
  vector<shared_ptr<Point>> numbers;
  for (int i = 0; i < 2; i++) {
    numbers.push_back(sp2);//压入的话会增加use_count()
  }
  cout << "sp.use_count() = " << sp.use_count() << endl;
}
int main() {
  // test0();
  test1();
  return 0;
}
