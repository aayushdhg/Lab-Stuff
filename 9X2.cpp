#include<iostream>
using namespace std;

template <typename T>
class calculator{
    T x,y;
    public:
    calculator(){
    // T add(T a, T b){return a+b;}
    // T subtract(T a, T b){return a-b;}
    // T multiply(T a, T b){return a*b;}
    // T divide(T a, T b){return a/b;}
        cout<<"Enter the two numbers"<<endl;
        cin>>x;
        cin>>y;
        cin.ignore();
     }
    
    void display(){
        cout<<"\nSum is: "<<x+y<<endl;
        cout<<"Difference is: "<<x-y<<endl;
        cout<<"Product is: "<<x*y<<endl;
        cout<<"Quotient is: "<<x/y<<endl;
    }
};

int main()
{
    cout<<"For integers"<<endl;
    calculator<int> obj1;
    // obj1.getNumbers();
    obj1.display();
    cout<<endl<<"For floats"<<endl;
    calculator<float> obj2;
    // obj2.getNumbers();
    obj2.display();

    return 0;


}