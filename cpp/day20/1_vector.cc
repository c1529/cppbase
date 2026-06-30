#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
void test0() {
  // 1. count个value
  vector<int> number(10, 2);
  // size_t 就是 unsigned long
  for (size_t i = 0; i < number.size(); i++) {
    cout << number[i] << " ";
  }
  cout << endl;
  // cout << endl << "sizeof(size_t) = " << sizeof(size_t) << endl;
  // cout << "sizeof(long) = " << sizeof(long) << endl;
  // 2. 迭代器
  int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
  vector<int> number2(
      arr,
      arr + 10); // 最后应该是指向最后一个元素的后一个位置，类似于vertor.end()
  for (unsigned long i = 0; i < number2.size(); i++) {
    cout << number2[i] << " ";
    if (i == number2.size() - 1) {
      cout << endl;
    }
  }
  // 迭代器遍历
  vector<int>::iterator it;
  cout << "使用迭代器(iterator)进行遍历" << endl;
  for (it = number2.begin(); it != number2.end(); it++) {
    cout << *it << " ";
    if (next(it) == number2.end()) {
      cout << endl;
    }
  }
  // 3. 拷贝构造或移动构造
  vector<int> number3(number2);
  cout << "number3: ";
  for (it = number3.begin(); it != number3.end(); it++) {
    cout << *it << " ";
    if (next(it) == number3.end()) {
      cout << endl;
    }
  }
  // 4. 大括号（类似c的数组）
  vector<int> number4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  cout << "number4: ";
  vector<int>::iterator it4;
  for (it4 = number4.begin(); it4 != number4.end(); it4++) {
    cout << *it4 << " ";
    if (next(it4) == number4.end()) {
      cout << endl;
    }
  }
}

int main() {
  test0();
  return 0;
}
