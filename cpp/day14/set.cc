#include <iostream>
#include <set>
#include <utility>
#include <vector>
using std::cout;
using std::endl;
using std::set;
using std::vector;
void test0() {
  set<int> set1{2, 5, 8, 4, 11, 10};
  for (auto x : set1) {
    cout << x << ", ";
  }
  cout << endl;
  set1.insert(6);
  set1.insert(99);
  set1.erase(8);
  for (auto it = set1.begin(); it != set1.end(); ++it) { //++it效率比it++高
    if (next(it) == set1.end()) { // next(it)表示it下一个迭代器
      cout << *it << endl;
    } else {
      cout << *it << ", ";
    }
  }
  vector<int> arr = {11, 2,  3,  5,  7, 88, 100, 99, 12, 14,
                     13, 15, 17, 11, 3, 4,  5,   6,  8};
  cout << "arr.size() = " << arr.size() << endl;
  set<int> set2(arr.begin(), arr.end()); // 直接通过迭代器
  cout << "set2.size() = " << set2.size() << endl;
  for (auto x : set2) {
    cout << x << "  ";
  }
  cout << endl;
  set<int>::iterator it = set2.find(99);
  if (it != set2.end()) {
    cout << "查找成功" << endl;
    cout << "*it = " << *it << endl;
  } else {
    cout << "查找失败" << endl;
  }
  // 返回类型第一个是迭代器，第二个是bool值
  std::pair<set<int>::iterator, bool> pair1 = set2.insert(66);
  cout << "*pair1.first = " << *pair1.first << endl;
  cout << "pair.second = " << pair1.second << endl;
  int distance = std::distance(set2.begin(), pair1.first);
  // 对于树状结构的容器来说没有it-v.begin()这种操作
  // 只有vector这种连续的有
  cout << "插入成功的位置距离第一个元素的位置 distance = " << distance << endl;
}
int main() {
  test0();
  return 0;
}
