#include<iostream>
#include<vector>
using namespace std;

int addNumberEasy(const vector<int>& numbers)
{
    int total=0;
    for(int num:numbers)
    {
        total+=num;
    }
    return total;
}
int addNumberRecursive(const vector<int>& numbers)
{

    static int total=0;
    if(total== numbers.size())
        return 0;

    return numbers[total++] + addNumberRecursive(numbers);
}
int main()
{
    int size;
    cout<<"How many numbers? : ";
    cin>>size;

    vector<int>numbers(size);
    cout<<"Enter "<<size<<" Number: ";
    for(int i=0; i<size; i++)
    {
        cin>>numbers[i];
    }

    int sum=addNumberEasy(numbers);
    cout<<"The Total is: "<<sum<<endl;

    int sumr= addNumberRecursive(numbers);
    cout << "The Total is: " << sumr << endl;

    cout<<"24CE103_Manthan Rangpariya"<<endl;

    return 0;
}
