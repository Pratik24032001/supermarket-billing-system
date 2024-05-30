#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Product {
protected:
    int id;
    string name;
    double price;

public:
    Product(int id, const string &name, double price)
        : id(id), name(name), price(price) {}

    virtual void display() const {
        cout << "\t\t" << id << "\t\t" << name << "\t\t\t ₹" << price << endl;
    }

    int getId() const {
        return id;
    }

    double getPrice() const {
        return price;
    }

    virtual ~Product() {}
};


class Perishable : public Product {
    int expiryDays;

public:
    Perishable(int id, const string &name, double price, int expiryDays)
        : Product(id, name, price), expiryDays(expiryDays) {}

    void display() const override {
        Product::display();
        cout << "\t\t\t\tExpiry Days: " << expiryDays << endl;
    }
};


class NonPerishable : public Product {
    string warranty;

public:
    NonPerishable(int id, const string &name, double price, const string &warranty)
        : Product(id, name, price), warranty(warranty) {}

    void display() const override {
        Product::display();
        cout << "\t\t\t\tWarranty: " << warranty << endl;
    }
};


class Shopping {
protected:
    vector<Product *> products;

public:
    ~Shopping() {
        for (size_t i = 0; i < products.size(); ++i) {
            delete products[i];
        }
    }

    void addProduct(Product *product) {
        products.push_back(product);
    }

    void removeProduct(int id) {
        for (size_t i = 0; i < products.size(); ++i) {
            if (products[i]->getId() == id) {
                delete products[i];
                products.erase(products.begin() + i);
                break;
            }
        }
    }

    void displayCart() const {
        cout << "\n\n\t\tCart Contents:" << endl;
        for (size_t i = 0; i < products.size(); ++i) {
            products[i]->display();
        }
    }

    double calculateTotal() const {
        double total = 0.0;
        for (size_t i = 0; i < products.size(); ++i) {
            total += products[i]->getPrice();
        }
        return total;
    }

    Product* getProductById(int id) {
        for (size_t i = 0; i < products.size(); ++i) {
            if (products[i]->getId() == id) {
                return products[i];
            }
        }
        return NULL;
    }
};


class Administrator : public Shopping {
public:
    void addPerishable(int id, const string &name, double price, int expiryDays) {
        products.push_back(new Perishable(id, name, price, expiryDays));
    }

    void addNonPerishable(int id, const string &name, double price, const string &warranty) {
        products.push_back(new NonPerishable(id, name, price, warranty));
    }

   const vector<Product*>& getProducts() const {
        return products;
    }
};


class User : public Shopping {
public:
    void addToCart(Product *product) {
        addProduct(product);
    }

    void removeFromCart(int id) {
        removeProduct(id);
    }

    void checkout() const {
        cout << "\n\n\t\t----Total user bill: ₹" << calculateTotal() << endl;
    }

   void displayAvailableProducts(const Administrator& admin) const {
   	cout << "\n\n\n\t ***********************************************************************\n";
        cout << "                                      Available Products          " << endl;
        cout << "\t ***********************************************************************\n";
        const vector<Product*>& adminProducts = admin.getProducts();
        cout<<"\t\t\t\tID\t\t Name\t\t\t Price";
        for (size_t i = 0; i < adminProducts.size(); ++i) {
            cout << "\n\t\t" << i + 1;
            adminProducts[i]->display();
        }
    }
};


void showMenu() {
      cout << "\n\n\n\t ***********************************************************************\n";
        cout << "\t                          Super Market Main Menu       \n";
        cout << "\t ***********************************************************************\n";
    cout << "\t\t1. Add Perishable Product (Admin)\n";
    cout << "\t\t2. Add Non-Perishable Product (Admin)\n";
    cout << "\t\t3. Add Product to Cart (User)\n";
    cout << "\t\t4. Remove Product from Cart (User)\n";
    cout << "\t\t5. Display Cart (User)\n";
    cout << "\t\t6. Checkout (User)\n";
    cout << "\t\t7. Exit\n";
    cout << "\t\tEnter your choice: ";
}

int main() {
    Administrator admin;
    User user;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 7) {
            break;
        }

        int id;
        string name;
        double price;
        int expiryDays;
        string warranty;

        switch (choice) {
            case 1:
                cout << "\n\n\t\tEnter Product ID: ";
                cin >> id;
                cin.ignore();
                cout << "\t\tEnter Product Name: ";
                getline(cin, name);
                cout << "\t\tEnter Product Price: ";
                cin >> price;
                cout << "\t\tEnter Expiry Days: ";
                cin >> expiryDays;
                admin.addPerishable(id, name, price, expiryDays);
                break;
            case 2:
                cout << "\n\n\t\tEnter Product ID: ";
                cin >> id;
                cin.ignore();
                cout << "\t\tEnter Product Name: ";
                getline(cin, name);
                cout << "\t\tEnter Product Price: ";
                cin >> price;
                cout << "\t\tEnter Warranty: ";
                cin.ignore();
                getline(cin, warranty);
                admin.addNonPerishable(id, name, price, warranty);
                break;
            case 3:
                user.displayAvailableProducts(admin);
                cout << "\n\n\t\tEnter Product ID to add to cart: ";
                cin >> id;
                if (Product* product = admin.getProductById(id)) {
                    user.addToCart(product);
                } else {
                    cout << "-------------------Product not found.------------------\n";
                }
                break;
            case 4:
                cout << "\n\n\t\tEnter Product ID to remove from cart: ";
                cin >> id;
                user.removeFromCart(id);
                break;
            case 5:
                user.displayCart();
                break;
            case 6:
                user.checkout();
                break;
            default:
                cout << "-----------------Invalid choice. Please try again.---------------\n";
        }
    }

    return 0;
}

