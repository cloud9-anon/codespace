#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person() : name("Default") {}
    string name;
};

class Seller : public Person
{
public:
    static int count;
    int seller_id;

    Seller()
    {
        this->name = "";
        this->seller_id = 0;
    }

    void add_seller()
    {
        count++;
        cout << "Enter Your Name: ";
        cin >> this->name;
        this->seller_id = count;
        cout << "Seller Registered!\nYour Id is: " << seller_id << endl
             << endl;
    }
};

class Product
{
public:
    string product_name;
    int price;
    int product_id;
    int seller_id;

    static int product_count;

    Product()
    {
        this->product_name = "Default";
        this->price = 0;
        this->seller_id = 0;
    }

    void add_product()
    {
        product_count++;
        this->product_id = product_count;
        cout << "Enter Product Name: ";
        cin >> this->product_name;
        cout << "Enter Price: ";
        cin >> this->price;
        cout << "Enter Seller ID: ";
        cin >> this->seller_id;
        cout << "Product Added!\nProduct ID is: " << product_id << endl;
    }

    void displayProduct()
    {
        cout << "Product Id: " << this->product_id << endl;
        cout << "Product Name: " << this->product_name << endl;
        cout << "Product Seller Id: " << this->seller_id << endl;
        cout << "Product Price: " << this->price << endl;
    }
};

int Seller::count = 0;
int Product::product_count = 1000;

void displayProductsSoldBySeller(Product array[], int size, int seller_id)
{
    cout << "List of Products Sold By Seller Id: " << seller_id << endl;

    for (int i = 0; i < size; i++)
    {
        if (array[i].product_id != 0 && array[i].seller_id == seller_id)
        {
            array[i].displayProduct();
            cout << endl;
        }
    }
}

void displayAllSellers(Seller array[], int size)
{
    cout << "List of All Sellers:" << endl;

    for (int i = 0; i < size; i++)
    {
        if (array[i].seller_id != 0)
        {
            cout << "Seller Id: " << array[i].seller_id << endl;
            cout << "Seller Name: " << array[i].name << endl;
            cout << endl;
        }
    }
}

void displayAllProducts(Product array[], int size)
{
    cout << "List of All Products:" << endl;

    for (int i = 0; i < size; i++)
    {
        if (array[i].product_id != 0)
        {
            array[i].displayProduct();
            cout << endl;
        }
    }
}

int main()
{
    const int array_size = 500;
    Seller seller_array[array_size];
    Product product_array[array_size];

    int choice;
    int seller_index = 0;
    int product_index = 0;

    do
    {
        cout << "1: Add Seller\n2: Add Product\n3: Display Products Sold By Seller\n4: Display All Sellers\n5: Display All Products\n6: Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            seller_array[seller_index].add_seller();
            seller_index++;
            break;
        case 2:
            product_array[product_index].add_product();
            product_index++;
            break;
        case 3:
            int id;
            cout << "Enter Seller Id: ";
            cin >> id;
            displayProductsSoldBySeller(product_array, array_size, id);
            cout << endl;
            break;
        case 4:
            displayAllSellers(seller_array, array_size);
            cout << endl;
            break;
        case 5:
            displayAllProducts(product_array, array_size);
            cout << endl;
            break;
        }

    } while (choice != 6);

    return 0;
}
