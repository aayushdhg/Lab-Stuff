#include<iostream>
using namespace std;

class shape{
    public:
        virtual double area()
        {
            return 0;
        }
        virtual void display()
        {
            cout<<"Area is: "<<area()<<endl;
        }

};

class circle: public shape{
    double radius;

    public:
        circle(double r):radius(r){}

        double area () override{
            return 3.14 * radius * radius;
        }
        void display() override{
            cout<<"Circle's ";
            shape::display();
        }
};

class rectangle: public shape{
    double length, breadth;

    public:
        rectangle(double l, double b):length(l), breadth(b){}

        double area () override{
            return length * breadth;
        }
        void display() override{
            cout<<"Rectangle's ";
            shape::display();
        }
};

class triangle: public shape{
    double base, height;

    public:
        triangle(double b, double h):base(b), height(h){}

        double area () override{
            return 0.5 * base * height;
        }
        void display() override{
            cout<<"Triangle's ";
            shape::display();
        }
};

int main()
{
    circle c(1);
    rectangle r(5,10);
    triangle t(3,4);
    c.display();
    r.display();
    t.display();
    return 0;
}