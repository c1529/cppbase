#include <iostream>
#include<cstring>
using std::cout;
using std::endl;
class Computer{
public:
    Computer(const char *brand,double price)
        :_brand(new char[strlen(brand)+1])
         ,_price(price){
             strcpy(_brand,brand);
             cout<<"构建完成"<<endl;
         }
    void print(){
        cout<<_brand <<"  "<<_price<<endl;
    }
    // 拷贝构造函数
    // Computer pc1=pc2会调用
    Computer(const Computer &rhs)
        :_brand(new char[strlen(rhs._brand)+1])
         ,_price(rhs._price)
    {
        strcpy(_brand,rhs._brand);
        cout<<"拷贝构造函数"<<endl;
    }
    // 赋值运算符重载函数
    // pc2=pc1会调用
    Computer & operator=(const Computer &rhs){
        cout<<"Computer & operator=(const Computer &)"<<endl;
        if(this!=&rhs){
            delete [] this->_brand;
            this->_brand=new char[strlen(rhs._brand)+1]();
            strcpy(_brand,rhs._brand);
            this->_price=rhs._price;
        }
        return *this;
    }
    ~Computer(){
        delete[] _brand;
    }

private:
    char *_brand;
    double _price;
};
int main()
{
    //std::cout << "Hello world" << std::endl;
    Computer pc1("huawei",9999.0);
    Computer pc2("xiaomi",8888.0);
    pc2=pc1;
    pc2.print();
    Computer pc3=pc1;
    pc3.print();
    return 0;
}

