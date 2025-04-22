#include<iostream>
#include<queue>
using namespace std;

class Fuel
{
protected:
    string fuel_type;
public:

    Fuel(string fuel)
    {
        fuel_type=fuel;
    }

    void display_fuel()
    {
        cout<<" Fuel Type: "<< fuel_type << endl;
    }
};

class Brand
{
protected:
    string brand_name;
public:
    Brand(string brand)
    {
        brand_name=brand;
    }

    void display_brand()
    {
        cout<<" Brand Name: "<< brand_name << endl;
    }
};

class Car:public Fuel, public Brand
{
protected:
    string mod;
public:
    Car(string fuel,string brand,string mod1): Fuel(fuel), Brand(brand), mod(mod1) {}

    void display_data()
    {
        display_fuel();
        display_brand();
        cout<< " Car MOD : "<< mod << endl;
    }
};

int main()
{
    queue<Car> carQueue;
    int num_cars;
    cout << "Enter the number of cars: ";
    cin >> num_cars;

    for (int i = 0; i < num_cars; i++)
    {
        string fuel, brand, model;
        cout << "Enter details for car #" << i + 1 << ":\n";
        cout << "Fuel Type: ";
        cin >> fuel;
        cout << "Brand Name: ";
        cin >> brand;
        cout << "Car Model: ";
        cin >> model;
        carQueue.push(Car(fuel, brand, model));
    }

    while (!carQueue.empty())
    {
        cout<< "----------------------------------" << endl;
        Car currentCar = carQueue.front();
        currentCar.display_data();
        cout << "----------------------------------" << endl;
        carQueue.pop();
    }

    cout<<"24CE103_Manthan Rangpariya";

    return 0;
}

