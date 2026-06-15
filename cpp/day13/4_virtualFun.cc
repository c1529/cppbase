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
  // 添加virtual的时候调用dispaly会输出Dervied的_dirvied而不是_base了
  //基类如果定义的函数跟派生类一样(函数名字，返回值，参数)->那么派生类就会是默认为虚函数
  //如果基类不定义虚函数，派生类定义虚函数，那么输出的依旧是_base
  virtual void print() const { cout << "Base::base = " << _base << endl; }

private:
  long _base;
};
class Derived : public Base {
public:
  Derived(long base, long derived) : Base(base), _derived(derived) {
    cout << "Derived(long ,long)" << endl;
  }
  void print() const { cout << "Derived::derived = " << _derived << endl; }

private:
  long _derived;
};
void display(Base *pbase) { pbase->print(); }
void test0() {
  cout << "sizeof(Base) = " << sizeof(Base) << endl;
  cout << "sizeof(Derived) = " << sizeof(Derived) << endl;
  Base base1(1);
  Derived derived1(10, 100);
  display(&base1);
  display(&derived1);
}
int main() {
  test0();
  return 0;
}
