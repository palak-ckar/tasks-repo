#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
//enum color { RED, BLUE, BLACK, GREEN, ORANGE}
class circle
{
    public: circle()
    {
        float a, r, p;
        cin>>r;
        //virtual void getPerimeter()
        p=2*3.14*r;
        a=3.14*r*r;
        cout<<"Circle\n"<<r<<"\nPerimeter = "<<p<<"\nArea = "<<a<<"\n";
    }
};
class rectangle
{
    public: rectangle()
    {
        float a, p, r, l, b;
        cin>>l>>b;
        //virtual void getPerimeter()
        p=2*(l+b);
        a=l*b;
        cout<<"Rectangle\n"<<l<<" "<<b<<"\nPerimeter = "<<p<<"\nArea = "<<a<<"\n";
    }
};
class triangle
{
    public: triangle()
    {
        float a, p, r, b, h;
        cin>>b>>h;
        //virtual void getPerimeter()
        p=0;
        a=0.5*b*h;
        cout<<"\nTriangle\n"<<b<<" "<<h<<"\nPerimeter cannot be determined "<<p<<"\nArea = "<<a<<"\n";
    }
};
int main()
{
    vector<string> shape={"circle", "triangle", "circle", "rectangle", "rectangle"};
    //enum color { RED, BLUE, BLACK, GREEN, ORANGE};
    for(int i=0;i<shape.size();i++)
    {
        if(shape[i]=="circle")
            circle c1;
        else if(shape[i]=="rectangle")
            rectangle r1;
        else if(shape[i]=="triangle")
            triangle t1;
        else
            cout<<"Invalid input\n";
    }
}
