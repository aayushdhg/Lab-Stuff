#include <iostream>
#include <typeinfo>  // For RTTI
using namespace std;
class Shape {
public:
    virtual void draw() = 0;  
    virtual ~Shape() {} 
};
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" <<endl;
    }
};
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }
};
class Triangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Triangle" << endl;
    }
};

int main() {
    Shape* shapePtr=new Circle();

    // shapePtr = new Circle();
    shapePtr->draw(); 
    cout << "Type of shape is: " << typeid(*shapePtr).name() << endl;
    cout<< "Type of pointer is: "<< typeid(shapePtr).name()<<endl;
    cout<<"\nPerforming downcasting"<<endl;

    // shapePtr=dynamic_cast<Circle*>(shapePtr);
    // if(shapePtr){ 
    //     shapePtr->draw();
    //     cout << "Type of shape is: " << typeid(*shapePtr).name() << endl;
    //     cout << "Type of pointer is: "<<typeid(shapePtr).name()<<endl;    //still gives P5Shape apparently cause typeid shows the static type of the pointer variable, type of pointer variable itself declared at compile time whose static type remians Shape* throughout the program
    // }
    // else{
    //     cout<<"Shape could not become a rectangle"<<endl;
    // }

    Circle* circlePtr=dynamic_cast<Circle*>(shapePtr);
    if(circlePtr){ 
        circlePtr->draw();
        cout << "Type of shape is: " << typeid(*circlePtr).name() << endl;
        cout << "Type of pointer is: "<<typeid(circlePtr).name()<<endl;
    }
    else{
        cout<<"Shape could not become a rectangle"<<endl;
    }

   // delete shapePtr;  
    cout<<endl;

    Rectangle* rectanglePtr=new Rectangle();
    rectanglePtr->draw();
    cout << "Type of shape is: " << typeid(*rectanglePtr).name() << endl;
    cout<< "Type of pointer is: "<< typeid(rectanglePtr).name()<<endl;

    shapePtr=dynamic_cast<Shape*>(rectanglePtr);
    cout<<"\nPerforming upcasting"<<endl;
    if(shapePtr){ 
        shapePtr->draw();
        cout << "Type of shape is: " << typeid(*shapePtr).name() << endl;
        cout << "Type of pointer is: "<<typeid(shapePtr).name()<<endl;
    }
    else{
        cout<<"Shape could not become a rectangle"<<endl;
    }

    cout<<endl;
    Shape* shape = new Triangle();
    shape->draw(); 
    cout << "Type of shape is: " << typeid(*shape).name() << endl;

    if (Circle* circle = dynamic_cast<Circle*>(shape)) {
        cout << "Shape is a Circle." << endl;
    } else if (Rectangle* rectangle = dynamic_cast<Rectangle*>(shape)) {
        cout << "Shape is a Rectangle." << endl;
    } else if (Triangle* triangle = dynamic_cast<Triangle*>(shape)) {
        cout << "Shape is a Triangle." << endl;
    } else {
        cout << "Unknown shape!" << endl;
    }

   // delete rectanglePtr;  

    return 0;
}
