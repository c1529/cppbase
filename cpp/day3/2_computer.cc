#include <iostream>
#include<cstring>
using std::cout;
using std::endl;
class Computer{
public:
    void setBrand(const char *brand){
        // _brand=brand  //浅拷贝 只复制地址
        _brand=new char[strlen(brand)+1]();
        strcpy(_brand,brand);
    }
    void setPrice(double price){
        _price=price;
    }
    void print(){
        cout<<"brand is "<<_brand<<", price is "<<_price<<endl;
    }
    ~Computer(){
        if(_brand){
            delete [] _brand;;
            _brand=nullptr;
            cout<<"_brand is delete"<<endl;
        }
    }
private:
    char *_brand;
    double _price;
};
void test0(){
    Computer pc;
    pc.setBrand("mac book pro");
    pc.setPrice(25000.0);
    pc.print();
}
int main()
{
    test0();
    return 0;
}

