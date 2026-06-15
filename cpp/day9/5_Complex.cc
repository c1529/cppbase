#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
class Complex{
public:
    Complex(double dreal,double dimage)
        :_dreal(dreal)
         ,_dimage(dimage)
    {cout<<"Complex(double ,double)"<<endl;}
    //友元函数
    friend double get_dreal(const Complex & c);
    friend double get_dimage(const Complex & c);
    void print() const
    {
        cout<<_dreal;
        if(_dimage>0){
            cout<<" + "<<_dimage<<"i";
        }else if(_dimage<0){
            cout<<" - "<<(-1)*_dimage<<"i";
        }
        cout<<endl;
    }
private:
    double _dreal;
    double _dimage;
};
double get_dreal(const Complex & c){
    return c._dreal;
}
double get_dimage(const Complex & c){
    return c._dimage;
}
Complex operator+(const Complex & lhs,const Complex & rhs){
    return Complex(get_dreal(lhs)+get_dreal(rhs),
                   get_dimage(lhs)+get_dimage(rhs));
}
void test0(){
    Complex c1(1,2),c2(2,3);
    Complex c3=c1+c2;
    c3.print();
}
int main()
{
    test0();
    return 0;
}

