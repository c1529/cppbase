#include <iostream>
#include <map>
#include <string>
#include <utility>
using std::cout;
using std::endl;
using std::map;
using std::string;
void test0() {
  // map里成员实际是pair
  map<string, string> map1{{"099", "广州"},
                           {"011", "上海"},
                           {"022", "北京"},
                           {"022", "深圳"},
                           {"023", "苏州"}};
  for (auto &it : map1) {
    cout << "it.first = " << it.first << endl;
    cout << "it.second = " << it.second << endl;
  }
  cout << "map1[\"011\"] = " << map1["011"] << endl;
  cout << "map1[\"099\"] = " << map1["099"] << endl;
  map1["051"] = "杭州";
  std::pair<map<string, string>::iterator, bool> pair1 =
      map1.insert({"024", "大连"});
  if (pair1.second) {
    cout << "插入成功" << endl;
  } else {
    cout << "插入失败" << endl;
  }
  for (auto &it : map1) {
    cout << "it.first = " << it.first << "   --->";
    cout << "it.second = " << it.second << endl;
  }
  cout << "map1[\"051\"] = " << map1["051"] << endl;
}
int main() {
  test0();
  return 0;
}
