#include<iostream>
using namespace std;

class student
{
    int roll_no;
    string s_name;
    float marks[3];

public:
    student()
    {
        roll_no=0;
        s_name="N/A";
        marks[0]=marks[1]=marks[2]=0;
        cout<<"Student Details Programe"<<endl;
    }

    student(int roll,string name,float m1,float m2, float m3)
    {
        roll_no=roll;
        s_name=name;
        marks[0]=m1;
        marks[1]=m2;
        marks[2]=m3;
    }

    double cal_avg()
    {
        return (marks[0]+marks[1]+marks[2])/3.0;
    }

    void display()
    {
        cout<<"Roll No is : "<<roll_no<<endl;
        cout<<"Name is: "<<s_name<<endl;
        cout<<"Marks is: "<<marks[0]<<" "<<marks[1]<<" "<<marks[2]<<endl;
        cout<<"Average Marks is: "<<cal_avg()<<endl;
    }
};

int main()
{
    student s;
    s.display();
    int n;
    cout<<"How many student Details you Want: ";
    cin>>n;
    student s1[n];

    for(int i=0;i<n;i++)
    {
        int roll;
        string name;
        float m1,m2,m3;

        cout<<"Enter Roll Number: ";
        cin>>roll;
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter Three subject marks: ";
        cin>>m1>>m2>>m3;

        s1[i]=student(roll,name,m1,m2,m3);
    }

    for(int i=0;i<n;i++)
    {
        cout<<"Details of  "<<i+1<<" is:"<<endl;
        s1[i].display();
    }

    cout<<"Name:Manthan Rangpariya"<<endl<<"Id:24CE103";
}
