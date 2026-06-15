#include <iostream>
#include <vector>
#include <string>
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
    {
        cout<<"Point(int,int)"<<endl;
    }
    void print() const{
        cout<<"("<<_ix<<","<<_iy<<")"<<endl;
    }
protected:
    int _ix;
    int gety() const{
        return _iy;
    }
private:
    int _iy;
};
class Point3D
:public Point{
public:
    Point3D(int ix,int iy,int iz)
        :Point(ix,iy)
         ,_iz(iz)
    {
        cout<<"Point3D(int,int,int)"<<endl;
    }
    void print3D() const{
        cout<<"("<<_ix    //在Point3D中是protected
            <<","<<gety()//通过函数获取基类的private值
            <<","<<_iz
            <<")"<<endl;
    }
private:
    int _iz;
};

void test0(){
    Point p1(3,4);
    p1.print();

    Point3D p2(5,6,7);
    p2.print3D();

}
int main()
{
    test0();
    return 0;
}

