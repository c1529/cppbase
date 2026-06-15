#include <iostream>
#include <vector>
#include <string>
#include<math.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
class Point{
public:
    Point(int ix,int iy)
        :_ix(ix)
         ,_iy(iy)
    {cout<<"Point(int,int)"<<endl;}
    void print(){
        cout<<"("<<_ix<<","<<_iy<<")"<<endl;
    }
    // 友元普通函数
    friend double pointDistance(const Point & lhs,const Point & rhs);
private:
    int _ix;
    int _iy;
};
double pointDistance(const Point & lhs,const Point & rhs){
    return sqrt((lhs._ix-rhs._ix)*(lhs._ix-rhs._ix)+(lhs._iy-rhs._iy)*(lhs._iy-rhs._iy));
}


void test0(){
    Point p1(3,4);
    Point p2(6,8);
    double num = pointDistance(p1,p2);
    cout<<num<<endl;
}
int main()
{
    test0();
    return 0;
}

