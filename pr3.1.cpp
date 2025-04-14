#include<iostream>
#include<vector>
using namespace std;

class employee
{
    string name;
    float salary;
    float bonus;


public:
    employee(string n,float s,float b)
    {
        name=n;
        salary=s;
        bonus=b;
        cal_salary();
    }

    int cal_salary()
    {
        return (salary+bonus);
    }

    void display()
    {
        cout<<"Name is: "<<name<<endl;
        cout<<"salary is: "<<salary<<endl;
        cout<<"Bouns is: "<<bonus<<endl;
        cout<<"Total salary is "<<cal_salary()<<endl;
    }
};

int main()
{
    vector<employee>emp;
    int m=0;
    cout<<"How Many Employee Data You need: ";
    cin>>m;

    string n;
    float s,b;
    for(int i=0;i<m;i++)
    {
        cout<<"enter name: ";
        cin>>n;
        cout<<"Enter Salary: ";
        cin>>s;
        cout<<"enter bonus: ";
        cin>>b;

        emp.emplace_back(n,s,b);
    }


    for( auto&i :emp)
    {
        i.display();
    }

     cout<<"24CE103_Manthan Rangpariya"<<endl;
}
