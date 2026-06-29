#include <chrono>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::vector;
// xx器本质上就是函数对象
struct my_pclose { // 自定义删除器
  void operator()(FILE *fp) const {
    if (fp) {
      fclose(fp);
      cout << "fclose(fp)" << endl;
    }
  }
};
void test0() {
  unique_ptr<FILE, my_pclose> up(fopen("test.txt", "w"));
  for (int i = 0; i < 5; i++) {
    time_t now = time(0);
    tm *localTime = localtime(&now);
    string msg = "this is msg : " + std::to_string(1900 + localTime->tm_year) +
                 "年" + std::to_string(localTime->tm_mon) + "月" +
                 std::to_string(localTime->tm_mday) + "日" +
                 std::to_string(localTime->tm_hour) + "时" +
                 std::to_string(localTime->tm_min) + "分" +
                 std::to_string(localTime->tm_sec) + "秒\n";
    // cout << msg << endl;
    // cout<<msg.size()<<endl;
    // cout<<up.get()<<endl;   get()返回的是保管的原始指针---->这里是FILE*
    // 也就是文件描述符
    size_t ret = fwrite(msg.c_str(), 1, msg.size(), up.get());
    if (ret != msg.size()) {
      cout << "error!!!!,ret = " << ret << endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
  }
  // fclose(up.get());  会导致双重fclose
}
void test1() {
  my_pclose myPclose;
  FILE *fp = fopen("test.txt", "a+");
  myPclose(fp);
}
void test2() {
  my_pclose myPclose;
  shared_ptr<FILE> sp(fopen("text.txt", "a+"), myPclose);
  string msg("this is shared_ptr txt\n");
  fwrite(msg.c_str(), 1, msg.size(), sp.get());
}
int main() {
  // test0();
  // test1();
  test2();
  return 0;
}
