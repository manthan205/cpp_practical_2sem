#include<iostream>
using namespace std;

class store
{
    int item_id;
    string product_name;
    float product_price;
    int quantity;

public:
    store()
    {
        item_id=0;
        product_name="N/A";
        product_price=0.0;
        quantity=0;
    }

    store(int id,string name,float price,int qty)
    {
        item_id=id;
        product_name=name;
        product_price=price;
        quantity=qty;
        increes_stock();
        decrees_item();
    }

    void increes_stock()
    {
        int new_item;
        cout<<"Enter How Many New ITEM Added: ";
        cin>>new_item;
        quantity+=new_item;
        cout<<"Updated ITEM Quantity is: "<<quantity<<endl;
    }

    void decrees_item()
    {
        int sold_item;
        cout<<"How Many ITEM are sold: ";
        cin>>sold_item;

        if(sold_item<quantity)
        {
           quantity-=sold_item;
        }
        else
        {
            cout<<"Enter correct value"<<endl;

        }
        cout<<"Available ITEM is: "<<quantity<<endl;
    }

    void display()
    {
        cout<<"ITEM id: "<<item_id<<endl;
        cout<<"ITEM name: "<<product_name<<endl;
        cout<<"ITEM Price: "<<product_price<<endl;
        cout<<"ITEM Quantity is: "<<quantity<<endl;
    }
};

int main()
{
    int n;
    cout<<"Enter how many item Details you want: ";
    cin>>n;

    store s2[n];

    for(int i=0;i<n;i++)
    {
        int id;
        string name;
        float price;
        int qty;

        cout<<"enter item id: ";
        cin>>id;
        cout<<"enter item name: ";
        cin>>name;
        cout<<"enter item price: ";
        cin>>price;
        cout<<"enter item quantity: ";
        cin>>qty;

        s2[i]=store(id,name,price,qty);
    }

    for(int i=0;i<n;i++)
    {
        s2[i].display();
    }

    cout<<"24CE103_Manthan Rangpariya"<<endl;

    return 0;
}
