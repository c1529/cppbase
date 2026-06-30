#include <iostream>
#include <list>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;
// list相当于是双向链表
void test0() {
  // 1. count个value进行初始化
  list<int> list1(10, 1);
  // 不能使用list1[1]进行访问
  for (auto &it1 : list1) {
    cout << it1 << " ";
  }
  cout << endl;
  // 可以跟deque一样前插以及尾插
  list1.push_front(11);
  list1.push_back(22);
  for (auto &it1 : list1) {
    cout << it1 << " ";
  }
  cout << endl;
  // 2. 大括号
  list<int> list2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  list<int>::iterator it2;
  cout << "list2: ";
  for (it2 = list2.begin(); it2 != list2.end(); it2++) {
    cout << *it2 << " ";
    if (next(it2) == list2.end()) {
      cout << endl;
    }
  }
  // 3. 移动构造
  list<int> list3(list2);
  list<int>::iterator it3;
  cout << "list3: ";
  for (it3 = list3.begin(); it3 != list3.end(); it3++) {
    cout << *it3 << " ";
    if (next(it3) == list3.end()) {
      cout << endl;
    }
  }
  // 4. 迭代器构造
  list<int> list4(list3.begin(), list3.end());
  list<int>::iterator it4;
  cout << "list4: ";
  for (it4 = list4.begin(); it4 != list4.end(); it4++) {
    cout << *it4 << " ";
    if (next(it4) == list4.end()) {
      cout << endl;
    }
  }
  // 删除首元素 尾元素
  list4.pop_front();
  list4.pop_back();
  cout << "list4进行首尾删除之后: ";
  for (it4 = list4.begin(); it4 != list4.end(); it4++) {
    cout << *it4 << " ";
    if (next(it4) == list4.end()) {
      cout << endl;
    }
  }
  // 反转
  list4.reverse();
  cout << "list4反转之后: ";
  for (it4 = list4.begin(); it4 != list4.end(); it4++) {
    cout << *it4 << " ";
    if (next(it4) == list4.end()) {
      cout << endl;
    }
  }
}

int main() {
  test0();
  return 0;
}
