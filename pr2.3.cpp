#include<iostream>
using namespace std;

class bank_account
{
    string holder_name;
    long account_number;
    long current_bal,deposite_money,withdraw_money;

public:
    bank_account()
    {
        holder_name="N/A";
        account_number=0;
        current_bal=0;
        deposite_money=0;
        withdraw_money=0;
    }

    bank_account(string name,long acc_number,long cur_bal,long depo,long wm)
    {
      holder_name=name;
      account_number=acc_number;
      current_bal=cur_bal;
      deposit();
      withdraw();

    }

    void deposit()
    {
        cout<<"Enter Deposit ammount: ";
        cin>>deposite_money;
        current_bal+=deposite_money;
    }

    void withdraw()
    {
        cout<<"Enter your withdraw ammont: ";
        cin>>withdraw_money;
        if(withdraw_money<=current_bal)
        {
            cout<<"You sufficient balance exists "<<endl;
            current_bal-=withdraw_money;
        }
        else
        {
            cout<<" You are not able to withdraw ammont. "<<endl;
        }
    }

    void display()
    {
        cout<<"Holder Name: "<<holder_name<<endl;
        cout<<"Account Number: "<<account_number<<endl;
        cout<<"Deposite Money: "<<deposite_money<<endl;
        cout<<"withdraw Money: "<<withdraw_money<<endl;
        cout<<"Your Current Balance is: "<<current_bal<<endl;
    }
};

int main()
{
    bank_account s1;
    s1.display();
    int n;
    cout<<"How many holder Details you Want: ";
    cin>>n;
    bank_account s2[n];

    for(int i=0;i<n;i++)
    {
        string name;
        long acc_number;
        long cur_bal,depo,wm;
        cout<<"Enter your Name: ";
        cin>>name;
        cout<<"Enter Your Account Number: ";
        cin>>acc_number;
        cout<<"Enter Your Balance: ";
        cin>>cur_bal;

        s2[i]=bank_account(name,acc_number,cur_bal,depo,wm);

    }
    for(int i=0;i<n;i++)
    {
        s2[i].display();
    }

    cout<<"24CE103_Manthan rangpariya"<<endl;

    return 0;

}
