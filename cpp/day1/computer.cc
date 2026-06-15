#include <iostream>
#include <cstring>
class Computer{
public:
    void setBrand(const char *brand){
        strcpy(_brand,brand);
    }
    void setPrice(double price){
        _price=price;
    }
    void print(){
        std::cout<<"brand:"<<_brand<<",price:"<<_price<<std::endl;
    }
private:
    char _brand[20];
    double _price;
};
void test0(){
    Computer pc;
    pc.setBrand("apple");
    pc.setPrice(25298.0);
    pc.print();
}
int main()
{
    //std::cout << "Hello world" << std::endl;
    test0();
    return 0;
}

