#include <iostream>
#include <vector>
#include <string>
#include <functional>
using std::cout;
using std::cin;
using std::endl;
using std::function;
using std::string;
using std::vector;
int add(int a,int b){return a+b;}
int multiply(int a,int b){return a*b;}
void test0(){

}
void test2(){
    //    <返回类型(值1类型,值2类型)>  
    function<int(int,int)> f1;
    f1=add;
    cout<<"add:f1(1,2) = "<<f1(1,2)<<endl;
    f1=multiply;
    cout<<"multiply:f1(1,2) = "<<f1(1,2)<<endl;
}
int main()
{
    //test0();
    test2();
    return 0;
}

