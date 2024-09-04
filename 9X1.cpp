#include<iostream>
#include<iomanip>
using namespace std;

template <class T, size_t n>
T sum(T (&t)[n]) //passing the array by reference to ensure the entire array is passed and the function knows the exact size of the array; avoiding array decay (array implicitly converted to a pointer which loses size information)
{
    T s=0;
    for (int i=0; i<n; i++)
        s+=t[i];
    return s;
}

int main(){
    
    int s[5]={1,2,3,4,5};
    float f[3]={2.34,4.54,42.432};
    float d[4]={1.232424,4.342444443432435,3.452424,344.34242424};
    cout<<fixed<<setprecision(8)<<showpoint;
    cout<<"Sum of elements in integer array is "<<sum(s)<<endl;
    cout.unsetf(ios::fixed);
    cout<<"Sum of elements in long double array is "<<setprecision(18)<<sum(d)<<endl;
    return 0;
}