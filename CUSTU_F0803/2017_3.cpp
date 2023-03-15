/*
编写程序从基类派生圆柱，设计成员函数输出它们的面积和体积
*/
#include<iostream>
#include<math.h>
using namespace std;
class Basic {
    protected:
        double r;
    public:
    Basic() {
        r = 0;
    }
    Basic(double a) : r(a){}
};

class Circular:public Basic { // 从基类派生圆类
    protected:
        double area; // 面积
    public:
        Circular(double a) {
            r = a;
            area = 3.1415926 * r * r;
        }
        double getArea() {
            return area;
        }
};

class Column:public Circular { // 从圆类派生圆柱类
    protected:
        double h;
        double cubage;
    public:
        Column(double a, double b):Circular(a) {
            h = b;
            cubage = area * h;
        }
        double getCubage() {
            return cubage;
        }
};

int main() {
    Circular circular(13);
    Column column(12, 10);
    cout << circular.getArea() << endl;
    cout << column.getCubage() << endl;

    return 0;
}