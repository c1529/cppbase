#include <iostream>
#include <vector>
#include <string>
#include<sstream>
using std::istringstream;
using std::ostringstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
void test0(){
    int num1=512;
    int num2=1024;
    ostringstream oss;
    oss<<"num1= "<<num1<<" num2= "<<num2;//写到oss流中
    string str = oss.str();
    cout<<str<<endl;
    //字符串转化成其他类型
    string s;
    int num;
    istringstream iss(str);
    int number=0;
    while(iss>>s>>num){
        cout<<"第"<<number<<"次："<<s<<"       "<<num<<endl;
    }
}
int main()
{
    test0();
    return 0;
}

