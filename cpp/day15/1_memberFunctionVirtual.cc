#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
class Base {
public:
  Base(long base) : _base(base) { cout << "Base(long)" << endl; }
  virtual void print() const { cout << "Base::base = " << _base << endl; }
  void func1() { print(); }

private:
  long _base;
};
class Derived : public Base {
public:
  Derived(long base, long derived) : Base(base), _derived(derived) {
    cout << "Derived(long,long)" << endl;
  }
  virtual void print() const {
    cout << "Derived::derived = " << _derived << endl;
  }

private:
  long _derived;
};
void test0() {
  Base base(1);
  base.func1();

  Derived derived(10, 100);
  // 最终输出是100 Derived继承了Base的func1()-->会执行print()函数
  // 但是print()函数是虚函数，导致Derived调用func1()实际上是调用虚函数print()
  derived.func1();
}
int main() {
  test0();
  return 0;
}
