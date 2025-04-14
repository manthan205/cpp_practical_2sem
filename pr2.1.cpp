#include<iostream>
using namespace std;

class rectangle
{
    float length,width;

public:
    float rec_perimeter()
    {
        return (2*(length+width));
    }

    float rec_area()
    {
        return (length*width);
    }

    void getdata()
    {
        cout<<"Enter rectangle length: ";
        cin>>length;
        cout<<"Enter rectangle width: ";
        cin>>width;
    }

    void putdata()
    {
        cout<<"Rectangle Perimeter is : "<<rec_perimeter()<<endl;
        cout<<"Rectangle Area is: "<<rec_area()<<endl;
    }
};

int main()
{
    int n,i;
    cout<<"How many ractangle you need: ";
    cin>>n;

    rectangle s[n];

    for(i=0 ; i<n ; i++)
    {
        s[i].getdata();
        s[i].putdata();
    }

    cout<<"Name:Manthan Rangpariya"<<endl<<"Id:24CE103";
}
