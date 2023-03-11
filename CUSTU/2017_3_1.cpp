/*
编写程序从基类派生圆柱，设计成员函数输出它们的面积和体积
*/
#include<iostream>
using namespace std;
const double PI = 3.1415926;
class Basic {
    protected:
        double r;
    public:
        Basic(){r = 0;}
        Basic(double a):r(a){}
};
class Column : Basic {
    protected:
        double h; // 圆柱高
        double area; //圆柱表面积
        double cubage; // 圆柱体积
    public:
        Column(double a, double b):Basic(b) {
            h = a;
            area = PI*r*r*2 + PI*2*r*h;
            cubage = PI * r * r * h;
        }
        double getArea() {
            return area;
        }
        double getCubage() {
            return cubage;
        }
};


int main() {
    Column column(10, 12);
    cout << column.getArea() << endl;
    cout << column.getCubage() << endl;

    return 0;
}