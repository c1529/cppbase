#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
void test0(){
    string s1="hello";
    string s2;
    s2=s1;//string 属于深拷贝
    cout<<"s1 = "<<s1<<endl;
    cout<<"s2 = "<<s2<<endl;
    cout<<"&s1 = "<<&s1<<endl;
    cout<<"&s2 = "<<&s2<<endl;
    cout<<"sizeof(s1)="<<sizeof(s1)<<endl;

}
int main()
{
    test0();
    return 0;
}

