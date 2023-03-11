#include<iostream>
using namespace std;
class vehicle {
    protected:
        int wheels; // 车轮数
        float weight; // 重量
    public:
        void init(int a, float b){
            wheels = a;
            weight = b;
        }
        float get_weight() { // 返回重量
            return weight;
        }
        int get_wheels() { // 返回车轮数
            return wheels;
        }
        void print() { // 输出车轮数和重量，格式为“车轮数：x，重量：x” 其中x为实际值，不一定相同
            cout << "wheels : " << get_wheels() << " , " << "weight : " << get_weight() << endl;
        }
};

class Car:vehicle {
    private:
        int passenger; // 载人数
    public:
        void init(int a, float b, int c) {
            wheels = a;
            weight = b;
            passenger = c;
        }
        int getpassenger() {
            return passenger;
        }
        void print() {
            cout << "wheels : " << get_wheels() << " , " << "weight : " << get_weight();
            cout << ", passenger : " << getpassenger() << endl;
        }
};

int main() {
    vehicle v;
    v.init(2, 12.2);
    v.print();
    Car car;
    car.init(4, 78.6, 4);
    car.print();

    return 0;
}