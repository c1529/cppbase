#include <iostream>
#include <memory>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;
using std::vector;
using std::weak_ptr;
class Child;
class Parent {
public:
  Parent() { cout << "Parent()" << endl; }
  ~Parent() { cout << "~Parent()" << endl; }
  shared_ptr<Child> _spChild;
};
class Child {
public:
  Child() { cout << "Child()" << endl; }
  ~Child() { cout << "~Child()" << endl; }
  shared_ptr<Parent> _spParent;
};
void test0() {
  shared_ptr<Parent> spParent(new Parent);
  shared_ptr<Child> spChild(new Child);
  cout << "spParent.use_count() = " << spParent.use_count() << endl;
  cout << "spChild.use_count() = " << spChild.use_count() << endl;
  spParent->_spChild = spChild;
  spChild->_spParent = spParent;
  cout<<endl;
  cout << "spParent.use_count() = " << spParent.use_count() << endl;
  cout << "spChild.use_count() = " << spChild.use_count() << endl;
}
int main() {
  test0();
  return 0;
}
