#include<iostream>
#include<string>
using namespace std;

int SuperDigit(int n)
{
    if(n<10)
    {
        return n;
    }
     else
     {

     }

     int sum=0;
     for (; n>0; n/=10)
     {
        sum += n % 10;
     }

     return SuperDigit(sum);
}

int main()
{
    string n;
    int k;

    cout<<"Enter the number of N: ";
    cin>>n;
    cout<<"Enter the value of k: ";
    cin>>k;

    int initialSum=0;

    for(char digit: n)
    {
        initialSum+=digit-'0';
    }

    int totalSum=initialSum*k;
    int result= SuperDigit(totalSum);

    cout<<"The Super Digit is: "<<result<<endl;

    cout<<"24CE103_Manthan Rangpariya"<<endl;

    return 0;

}


