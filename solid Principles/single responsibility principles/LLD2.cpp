#include <bits/stdc++.h>
using namespace std;

class Product {
public:
    int price;
    string name;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

// 1. ShoppingCart: Only responsible for Cart related business logic.
class ShoppingCart {
private:
    vector<Product*> products; // Store heap-allocated products

public:
    void addProduct(Product* p) {
        products.push_back(p);
    }

    const vector<Product*>& getProducts() {
        return products;
    }

    // Calculates total price in cart.
    double calculateTotal() {
        double total = 0;

        for (auto p : products) {
            total += p->price;
        }

        return total;
    }
};

// 2. Shopping cart printer: responsible for only printing invoice
class ShoppingCartPrinter {
private:
    ShoppingCart* cart;

public:
    ShoppingCartPrinter(ShoppingCart* cart) {
        this->cart = cart;
    }

    void printInvoice() {
        cout << "shopping cart invoice\n";

        for (auto p : cart->getProducts()) {
            cout << p->name << "- $" << p->price << endl;
        }

        cout << "Total : $" << cart->calculateTotal() << endl;
    }
};

// 3. cart stored to the database
class storingToDatabase {
private:
    ShoppingCart* cart;

public:
    storingToDatabase(ShoppingCart* cart) {
        this->cart = cart;
    }

    void storingToDB() {
        cout << "Products saved to the database" << endl;
    }
};

int main() {

    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 15000));
    cart->addProduct(new Product("Mouse", 200));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    storingToDatabase* database = new storingToDatabase(cart);
    database->storingToDB();

    return 0;
}