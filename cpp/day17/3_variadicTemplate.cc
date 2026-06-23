#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
void print() { cout << "print() is finshed" << endl; }
template <class T, class... Args> void print(T t, Args... args) {
  // sizeof(Args)获取参数
  // Args是类型
  // args是具体参数
  // cout<<"sizeof...(Args) = "<<sizeof...(Args)<<endl;
  // cout<<"sizeof...(args) = "<<sizeof...(args)<<endl;
  cout << t << endl;
  print(args...); //...在参数右边是解包
                  // 最后会调用print()无参数版本
}
void test0() { print(1, 2.2, 'a', "helloworld", 2, 3); }
int main() {
  test0();
  return 0;
}
