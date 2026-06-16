#include <iostream>
using std::cout;
using std::endl;
class Grandpa {
public:
  Grandpa() {
    cout << "Grandpa()" << endl;
    func1();
  }
  ~Grandpa() {
    cout << "~Grandpa()" << endl;
    func2();
  }
  virtual void func1() const { cout << "Grandpa::func1()" << endl; }
  virtual void func2() const { cout << "Grandpa::func2()" << endl; }
};

class Parent : public Grandpa {
public:
  Parent() {
    cout << "Parent()" << endl;
    func1();
  }
  ~Parent() {
    cout << "~Parent()" << endl;
    func2();
  }
  // 如果把这段虚函数注释掉，那么执行 Parent p1的时候
  // 不会分别输出Grandpa::func1()和Parent::func1()
  // 而是输出两次Grandpa::func1()
  // ----也就是说如果当前class没有这个虚函数就会向上取虚函数----
  virtual void func1() const { cout << "Parent::func1()" << endl; }
  virtual void func2() const { cout << "Parent::func2()" << endl; }
};
class Son : public Parent {
public:
  Son() {
    cout << "Son()" << endl;
    func1();
  }
  ~Son() {
    cout << "~Son()" << endl;
    func2();
  }
  // 如果Son 和 Parent的虚函数都不写的话，那么就会自动调用Grandpa的
  // 自动向上寻祖
  virtual void func1() const { cout << "Son::func1()" << endl; }
  virtual void func2() const { cout << "Son::func2()" << endl; }
};
void test0() {
  cout << "====Parent p1====" << endl;
  Parent p1;
  cout << endl;
  cout << "====Son s1====" << endl;
  Son s1;
  cout << endl;
}
int main() {
  test0();
  return 0;
}
