#include<iostream>
using namespace std;

class DynamicArray
{
    int* data;
    int capacity;
    int size;

    void resize()
    {
       capacity*=2;
       cout<<"Resize Called : "<<endl;
       int* newData = new int[capacity];
       for(int i=0;i<size;++i)
       {
           newData[i]=data[i];
       }
       delete[] data;
       data=newData;
    }

public:
    DynamicArray(int intitialCapacity=4)
    {
        capacity=intitialCapacity;
        data=new int[capacity];
        size=0;
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    void insert(int value)
    {
        if(size==capacity)
        {
            resize();
        }
        data[size++]=value;
    }

    void remove(int index)
    {
        if(index<0 || index>=size)
        {
            cout<<"Invalid Index"<<endl;
            return;
        }

        for(int i=index;i<size-1;i++)
            data[i]=data[i+1];
        size--;
    }

    int get(int index) const
    {
        if(index<0 || index>=size )
        {
            cout<<"Invalid Index"<<endl;
            return -1;
        }
        return data[index];
    }

    int getSize() const
    {
        return size;
    }

    void print() const
    {
        for(int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DynamicArray arr;

    arr.insert(5);
    arr.insert(10);
    arr.insert(15);
    arr.insert(20);
    arr.insert(25);

    arr.print();

    arr.remove(2);
    arr.print();

    cout << "Element at index 1: " << arr.get(1) << endl;

    cout << "Array size: " << arr.getSize() << endl;

    return 0;
}

