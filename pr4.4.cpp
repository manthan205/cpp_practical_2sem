#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class BankAccount
{
    private:
    string accountNumber;
    double balance;

    public:
    BankAccount(string accNum, double Balance)
    {
        accountNumber = accNum;
        balance = Balance;
    }
    double getBalance() const
    {
        return balance;
    }
    void deposit(double amount)
    {
        balance += amount;
        cout<<"Deposited: "<<amount<<endl;
        cout<<"New Balance: "<<balance<<endl;
    }
    int withdraw(double amount)
    {
        if(amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout<<"Withdrawn: "<<amount<<endl;
            cout<<"New Balance: "<<balance<<endl;
            return 1;
        }
        else
        {
            cout<<"Insufficient Amount!!!!"<<endl;
            return 0;
        }
    }
};
class SavingsAccount : public BankAccount
{
    public:
    SavingsAccount(string accNum, double Balance) : BankAccount(accNum,Balance) {}

};
class CurrentAccount : public BankAccount
{
    private:
    double overdraftLimit;

    public:
    CurrentAccount(string accNum, double Balance, double limit) : BankAccount(accNum,Balance), overdraftLimit(limit) {}

    int withdraw(double amount)
    {
        if(amount > 0  && amount <= (getBalance() + overdraftLimit))
        {
            double balance = getBalance() - amount;
            cout<<"Withdrawn: "<<amount<<endl;
            cout<<"New Balance: "<<balance<<endl;
            return 1;
        }
        else
        {
            cout<<"OverDraft Limit Exceeded!!!!"<<endl;
            return 0;
        }
    }
    double getoverDraftlimit()const
    {
       return overdraftLimit;
    }
};
struct Transection
{
    string type;
    double amount;
};
void showMenu()
{
    cout<<"1. Deposit"<<endl;
    cout<<"2. Withdraw"<<endl;
    cout<<"3. Undo Last Transaction"<<endl;
    cout<<"4. Display Balance"<<endl;
    cout<<"0. Exit"<<endl;
}


int main()
{
    string accountType;
    string accountNumber;
    double balance;

    cout<<"Account Type (savings/current): ";
    cin>>accountType;
    cout<<"Account Number: ";
    cin>>accountNumber;
    cout<<"Initial Balance: ";
    cin>>balance;

    stack<Transection> transactionHistory;
    int ch;
    double amount;

    if(accountType == "savings")
    {
        SavingsAccount acc(accountNumber, balance);

        do
        {
            showMenu();
            cout<<"Enter the Choise : ";
            cin>>ch;

            switch(ch)
            {
                case 1:
                    cout<<"Enter amount to deposit: ";
                    cin>>amount;
                    acc.deposit(amount);
                    transactionHistory.push({"Deposit", amount});
                    break;

                case 2:
                    cout<<"Enter amount to withdraw: ";
                    cin>>amount;
                    if(acc.withdraw(amount) == 1)
                    {
                        transactionHistory.push({"Withdraw", amount});
                    }
                    break;

                case 3:
                    if(!transactionHistory.empty())
                    {
                        Transection lastTransaction = transactionHistory.top();
                        transactionHistory.pop();
                        cout<<"Undoing last transaction: "<<lastTransaction.type<<" of amount "<<lastTransaction.amount<<endl;
                        if(lastTransaction.type == "Deposit")
                        {
                            acc.withdraw(lastTransaction.amount);
                        }
                        else if(lastTransaction.type == "Withdraw")
                        {
                            acc.deposit(lastTransaction.amount);
                        }
                    }
                    else
                    {
                        cout<<"No transactions to undo!"<<endl;
                    }
                    break;

                case 4:
                    cout<<"Balance : "<<acc.getBalance()<<endl;
                    break;
            }
            cout<<"-------------------"<<endl;
        } while(ch != 0);
        cout<<"==============================="<<endl;
    }

    else if(accountType == "current")
    {
        double limit;
        cout<<"Overdraft Limit: ";
        cin>>limit;
        CurrentAccount acc(accountNumber, balance, limit);

        do
        {
            showMenu();
            cout<<"Enter the Choise : ";
            cin>>ch;

            switch(ch)
            {
                case 1:
                    cout<<"Enter amount to deposit: ";
                    cin>>amount;
                    acc.deposit(amount);
                    transactionHistory.push({"Deposit", amount});
                    break;

                case 2:
                    cout<<"Enter amount to withdraw: ";
                    cin>>amount;
                    if(acc.withdraw(amount) == 1)
                    {
                        transactionHistory.push({"Withdraw", amount});
                    }
                    break;

                case 3:
                    if(!transactionHistory.empty())
                    {
                        Transection lastTransaction = transactionHistory.top();

                        if(lastTransaction.type == "Deposit")
                        {
                            if(acc.getBalance() - lastTransaction.amount >= -acc.getoverDraftlimit())
                            {
                                acc.withdraw(lastTransaction.amount);
                                transactionHistory.pop();
                                cout<<"Undoing Deposite Of : "<<lastTransaction.amount<<endl;
                            }
                            else
                            {
                                cout<<"Cannot undo Deposit -- Overdraft limit will be exceeded !"<<endl;
                            }
                        }
                        else
                        {
                            acc.deposit(lastTransaction.amount);
                            transactionHistory.pop();
                            cout<<"Undoing Withdraw Of : "<<lastTransaction.amount<<endl;
                        }
                    }
                    else
                    {
                        cout<<"NO transaction to undo!"<<endl;
                    }
                    break;

                case 4:
                    cout<<"Balance : "<<acc.getBalance()<<endl;
                    break;
            }
            cout<<"----------------"<<endl;
        } while(ch != 0);
        cout<<"=============================="<<endl;
    }
    else
    {
        cout<<"Invalid Account Type!"<<endl;
    }
    cout<<"24CE103_Manthan Rangpariya.";
    return 0;
}
