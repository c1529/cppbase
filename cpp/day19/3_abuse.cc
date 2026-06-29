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
class Point : public std::enable_shared_from_this<Point> {
public:
  Point(int ix = 0, int iy = 0) : _ix(ix), _iy(iy) {
    cout << "Point(int,int)" << endl;
  }
  ~Point() { cout << "~Point()" << endl; }
  // 希望在类内部获取本对象的智能指针shared_ptr;
  shared_ptr<Point> addPoint(Point &pt) {
    _ix += pt._ix;
    _iy += pt._iy;
    return shared_from_this();
  }
  void print() const { cout << "(" << _ix << "," << _iy << ")" << endl; }

private:
  int _ix;
  int _iy;
};
void test0() {
  shared_ptr<Point> sp1(new Point(1, 2));
  shared_ptr<Point> sp2(new Point(11, 22));
  shared_ptr<Point> sp3(sp1->addPoint(*sp2));//sp3实际上就是sp1
  sp3->print();
  cout << "sp1'addre = " << sp1.get() << endl;
  cout << "sp2'addre = " << sp2.get() << endl;
  cout << "sp3'addre = " << sp3.get() << endl;
}
int main() {
  test0();
  return 0;
}
