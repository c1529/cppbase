#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
class CharArray{
public:
    CharArray(int size)
        :_size(size)
         ,_data(new char[_size]()){
             cout<<"CharArray(int size)"<<endl;
         }
    char &operator[](int idx){
        cout<<"char &operator[](int idx)"<<endl;
        if(idx>=0&&idx<_size){
            return _data[idx];
        }else{
            static char nullchar = '\0';
            return nullchar;
        }
    }
    void print(){
        cout<<_data<<endl;
    }
    int size(){return _size;}
private:
    int _size;
    char *_data;
};



void test0(){
    const char * pstr="hello,world";
    CharArray ca(strlen(pstr)+1);
    for(int i=0;i<ca.size();i++){
        ca[i]=pstr[i];
    }
    ca.print();
    for(int i=0;i<ca.size();i++){
        cout<<ca[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    test0();
    return 0;
}

