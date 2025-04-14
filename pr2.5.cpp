#include<iostream>
#include<cmath>
using namespace std;

class bank_loan
{
    int loan_id;
    string application_name;
    float loan_ammount,interest_rate;
    int loan_tenure;
    double emi;

public:
    bank_loan()
    {
        loan_id=0;
        application_name="N/A";
        loan_ammount=0;
        interest_rate=0;
        loan_tenure=0;
        emi=0;
    }

    bank_loan(int id,string name,float p,float ir,int t)
    {
        loan_id=id;
        application_name=name;
        loan_ammount=p;
        interest_rate=ir;
        loan_tenure=t;
        cal_tenure();
        cal_emi();
    }

    void cal_emi()
    {
      if (interest_rate == 0)
        {
            emi = loan_ammount / loan_tenure;
        } else
        {
            float r = interest_rate / (12 * 100);
            emi = (loan_ammount * r * pow(1 + r, loan_tenure)) / (pow(1 + r, loan_tenure) - 1);
        }
    }

    void cal_tenure()
    {
         if (loan_tenure < 12)
        {
            cout << "Loan tenure is less than 12 months." << endl;
        }
        else
        {
            cout << "Loan tenure is " << loan_tenure << " months." << endl;
        }
    }

    void display()
    {
       cout<<"Loan ID: "<<loan_id<<endl;
       cout<<"Application Name: "<<application_name<<endl;
       cout<<"Loan Ammount: "<<loan_ammount<<endl;
       cout<<"Interest Rate: "<<interest_rate<<endl;
       cout<<"Loan tenure: "<<loan_tenure<<endl;
       cout<<"EMI is: "<<emi<<endl;
    }

};

int main()
{

    int n;
    cout<<"Enter how many loan information you reqired: ";
    cin>>n;

    bank_loan s1[n];

    for(int i=0;i<n;i++)
    {
        int id;
        string name;
        float p,ir;
        int t;
        cout<<"Enter loan id: ";
        cin>>id;
        cout<<"Enter Application name: ";
        cin>>name;
        cout<<"Enter loan ammount: ";
        cin>>p;
        cout<<"Enter interest Rate: ";
        cin>>ir;
        cout<<"Enter loan tenure: ";
        cin>>t;

        s1[i]=bank_loan(id,name,p,ir,t);

    }

    for(int i=0;i<n;i++)
    {
        s1[i].display();
    }

    cout<<"24CE103_Manthan Rangpariya"<<endl;
    return 0;
}
