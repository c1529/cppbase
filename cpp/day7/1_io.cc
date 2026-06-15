#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::string;
void printStreamStatus(istream & is){
    cout<<"is's goodbit: "<<is.good()<<endl;
    cout<<"is's badbit: "<<is.bad()<<endl;
    cout<<"is's eofbit: "<<is.eof()<<endl;
    cout<<"is's failbit: "<<is.fail()<<endl;
}
void test0(){
    int number;
    printStreamStatus(cin);
    cin>>number;
    cout<<"number is "<<number<<endl;//输入字符串会导致failbit为1
    printStreamStatus(cin);
    cin.clear();//恢复流的状态
    //清除缓冲区
    cin.ignore(1024,'\n');
    string s1;
    cin>>s1;
    cout<<"s1 = "<<s1<<endl;
    printStreamStatus(cin);
}
int main()
{
    test0();
    return 0;
}

