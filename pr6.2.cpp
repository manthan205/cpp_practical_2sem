#include<iostream>
using namespace std;

class Point
{
    int x,y;

public:
    Point(int x=0,int y=0)
    {
        this->x=x;
        this->y=y;
    }

    Point* move(int &dx, int &dy)
    {
        x+=dx;
        y+=dy;
        return this;
    }

    void Display() const
    {
        cout<<"Point("<<x<<" , "<<y<<")"<<endl;
    }
};

int main()
{
    int x,y;
    cout<< " Enter initial x and y coordinatar: ";
    cin>>x>>y;

    Point* p=new Point(x,y);

    cout<< " Initial position: ";
    p->Display();

    int dx1,dy1,dx2,dy2;
    cout<<"Enter dx1 and dy1: ";
    cin>>dx1>>dy1;
    cout<<"Enter dx2 and dy2: ";
    cin>>dx2>>dy2;


    p->move(dx1,dy1)->move(dx2,dy2);

    cout<<"Updated position: ";
    p->Display();

    delete p;

    cout<<"24CE103_Manthan Rangpariya"<<endl;
}
