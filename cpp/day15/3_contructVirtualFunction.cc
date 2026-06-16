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
    this->func1();
  }
  ~Parent() {
    cout << "~Parent()" << endl;
    this->func2();
  }
#if 0
  virtual void func1() const { cout << "Parent::func1()" << endl; }
  virtual void func2() const { cout << "Parent::func2()" << endl; }
#endif
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
#if 0
  virtual void func1() const { cout << "Son::func1()" << endl; }
  virtual void func2() const { cout << "Son::func2()" << endl; }
#endif
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
