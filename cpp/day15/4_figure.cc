#include <iostream>
#include <math.h>
#include <string>
using std::cout;
using std::endl;
using std::string;
class Figure {
public:
  // 纯虚函数，方便为子类提供接口
  virtual string name() const = 0;
  virtual double area() const = 0;
};
class Rectangle : public Figure {
public:
  Rectangle(double length, double width) : _length(length), _width(width) {
    cout << "Rectangle(double,double)" << endl;
  }
  // override是重载虚函数的，编译器可以校验是否为重写虚函数
  // 也可以不写，只不过为了工程严谨
  string name() const override { return string("rectangle"); }
  double area() const override { return _length * _width; }

private:
  double _length;
  double _width;
};
class Circle : public Figure {
public:
  Circle(double radius) : _radius(radius) { cout << "Circle(double)" << endl; }
  string name() const override { return string("circle"); }
  double area() const override { return PI * _radius * _radius; }

private:
  constexpr static double PI = 3.14159;
  double _radius;
};
class Triangle : public Figure {
public:
  Triangle(double a, double b, double c) : _a(a), _b(b), _c(c) {
    cout << "Triangle(double,double,double)" << endl;
  }
  string name() const override { return string("triangle"); }
  double area() const override {
    double p = (_a + _b + _c) / 2;
    return sqrt(p * (p - _a) * (p - _b) * (p - _c));
  }

private:
  double _a;
  double _b;
  double _c;
};
void display(Figure &fig) {
  cout << fig.name() << " area is :" << fig.area() << endl;
  cout << endl;
}
void test0() {
  Rectangle r1(10, 12);
  display(r1);

  Circle c1(10);
  display(c1);

  Triangle t1(3, 5, 4);
  display(t1);
}
int main() {
  test0();
  return 0;
}
