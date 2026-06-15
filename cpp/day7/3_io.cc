#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ifstream;
using std::string;
void test0(){
    ifstream ifs;
    ifs.open("1_io.cc");
    if(!ifs.good()){
        cout<<"ifstream open file error!"<<endl;
        return;
    }
    string word;
    int number=0;
    while(ifs>>word){
        cout<<word<<"--行数:"<<number<<endl;
        number++;
    }
    ifs.close();
}
void test1(){
    ifstream ifs;
    ifs.open("2_io.cc");
    if(!ifs.good()){
        cout<<"ifstream open file error!"<<endl;
        return;
    }
    string line;
    int number=0;
    while(std::getline(ifs,line)){
        number++;
        cout<<"行数:"<<number<<" "<<line<<endl;
    }
    ifs.close();
}
int main()
{
    //test0();
    test1();
    return 0;
}

