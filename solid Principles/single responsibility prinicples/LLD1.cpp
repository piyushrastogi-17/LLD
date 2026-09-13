#include <iostream>
#include <vector>
using namespace std;

class Product {
    public:
        int price;
        string name;

        Product(string name, int price) {
            this -> name = name;
            this -> price = price;
        }
};

class ShoppingCart {
    private:
        vector<Product*> products;
    public:
        void addProducts(Product *p) {
            products.push_back(p);
        }

        const vector<Product*> &getProducts() {
            return products;
        }

        // calculate total price in cart 
        double calculateTotal() {
            double total = 0;
            for(auto p: products) {
                total += p->price;
            }
            return total;
        }

        // printing in the invoice 
        void printInvoice() {
            cout << "shopping cart invoice:\n";
            for(auto p: products) {
                cout << p -> name << " - $" << p -> price << endl;
            }
            cout << "Total : $" << calculateTotal() << endl;
        }

        // saving to the database
        void savingToDatabase() {
            cout << "Products saved to the database" << endl;
        }


};
int main() {
    ShoppingCart *cart = new ShoppingCart();

    cart -> addProducts(new Product("Laptop", 15000));
    cart -> addProducts(new Product("Mouse", 200));

    cart -> printInvoice();
    cart -> savingToDatabase();

    
    return 0;
}