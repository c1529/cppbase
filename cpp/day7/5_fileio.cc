#include <iostream>
#include <vector>
#include <string>
#include<fstream>
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
void test0(){
    ifstream ifs("1_io.cc");
    if(!ifs){
        cout<<"ifstram is fail"<<endl;
        return ;
    }
    ifs.seekg(0,std::ios::end);//先将文件偏移到末尾
    long length = ifs.tellg();
    cout<<"ifs length is "<<length<<endl;
    ifs.close();
}
int main()
{
    test0();
    return 0;
}

