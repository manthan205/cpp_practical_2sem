#include<iostream>
using namespace std;

class Bankaccount
{
    char name[20];
    double ac_no;
    long balance;
    long depo;
    long wd;

    public:
    void input()
    {
        cout<<"Enter your Name: ";
        cin>>name;
        cout<<"Enter Your Account Number: ";
        cin>>ac_no;
        cout<<"Enter Your Balance: ";
        cin>>balance;
    }

    void deposit()
    {
        cout<<"Enter Deosit ammount: ";
        cin>>depo;
        balance+=depo;
    }

    void withdraw()
    {
        cout<<"Enter your withdraw ammont: ";
        cin>>wd;
        if(wd<=balance)
        {
            cout<<"You sufficient balance exists "<<endl;
            balance-=wd;
        }
        else
        {
            cout<<" You are not able to withdraw ammont. "<<endl;
        }
    }

    void display()
    {
        cout<<"Your current Balance is: "<<balance<<endl;
    }
};

int main()
{
    Bankaccount s1;

    s1.input();
    s1.deposit();
    s1.withdraw();
    s1.display();

    cout<<"24CE103_Manthan"<<endl;
}
