#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>

using namespace std;

// Product Class
class Product {
public:
    int id;
    string name;
    int quantity;
    double price;

    Product() {}

    Product(int i, string n, int q, double p) {
        id = i;
        name = n;
        quantity = q;
        price = p;
    }
};

// Inventory Class
class Inventory {
private:
    vector<Product> products;
    unordered_map<int, int> productIndex;
    string filename = "inventory.txt";

public:
    Inventory() {
        loadFromFile();
    }

    void saveToFile() {
        ofstream file(filename);

        for (auto &p : products) {
            file << p.id << "|"
                 << p.name << "|"
                 << p.quantity << "|"
                 << p.price << "\n";
        }

        file.close();
    }

    void loadFromFile() {
        ifstream file(filename);
        if (!file) return;

        products.clear();
        productIndex.clear();

        string line;

        while (getline(file, line)) {
            if (line.empty()) continue;

            Product p;
            size_t pos = 0;

            pos = line.find("|");
            p.id = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find("|");
            p.name = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find("|");
            p.quantity = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            p.price = stod(line);

            products.push_back(p);
            productIndex[p.id] = products.size() - 1;
        }

        file.close();
    }

    void addProduct(int id, string name, int quantity, double price) {
        if (productIndex.find(id) != productIndex.end()) {
            cout << "Product ID already exists!\n";
            return;
        }

        products.push_back(Product(id, name, quantity, price));
        productIndex[id] = products.size() - 1;

        saveToFile();
        cout << "Product added successfully!\n";
    }

    void updateStock(int id, int quantity, double price) {
    if (productIndex.find(id) != productIndex.end()) {
        Product &p = products[productIndex[id]];

        p.quantity += quantity;   // update stock
        p.price = price;          // update price

        saveToFile();
        cout << "Stock and Price updated!\n";
    } else {
        cout << "Product not found!\n";
    }
}

    void deleteProduct(int id) {
        if (productIndex.find(id) != productIndex.end()) {
            int idx = productIndex[id];

            swap(products[idx], products.back());
            productIndex[products[idx].id] = idx;

            products.pop_back();
            productIndex.erase(id);

            saveToFile();
            cout << "Product deleted!\n";
        } else {
            cout << "Product not found!\n";
        }
    }

    void searchProduct(int id) {
        if (productIndex.find(id) != productIndex.end()) {
            Product p = products[productIndex[id]];

            cout << "ID: " << p.id
                 << " | Name: " << p.name
                 << " | Qty: " << p.quantity
                 << " | Price: " << p.price << endl;
        } else {
            cout << "Product not found!\n";
        }
    }

    void displayInventory() {
        cout << "\nInventory:\n";

        for (auto &p : products) {
            cout << "ID: " << p.id
                 << " | Name: " << p.name
                 << " | Qty: " << p.quantity
                 << " | Price: " << p.price << endl;
        }
    }

    void lowStockAlert() {
        int threshold = 5;

        cout << "\nLow Stock Products (Below " << threshold << "):\n";

        for (auto &p : products) {
            if (p.quantity < threshold) {
                cout << p.name << " (Qty: " << p.quantity << ")\n";
            }
        }
    }
};

// Main Menu
int main() {
    Inventory inv;
    int choice;

    do {
        cout << "\n===== Stock Management System =====\n";
        cout << "1. Add Product\n";
        cout << "2. Update Stock\n";
        cout << "3. Delete Product\n";
        cout << "4. Search Product\n";
        cout << "5. Display Inventory\n";
        cout << "6. Low Stock Alert\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int n;
            cout << "How many products to add? ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                int id, qty;
                double price;
                string name;

                cout << "\nProduct " << i + 1 << endl;

                cout << "Enter ID: ";
                cin >> id;

                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);

                cout << "Enter Quantity: ";
                cin >> qty;

                cout << "Enter Price: ";
                cin >> price;

                inv.addProduct(id, name, qty, price);
            }
        }

        else if (choice == 2) {
            int id, qty;
            double price;
        
            cout << "Enter Product ID: ";
            cin >> id;
        
            cout << "Enter Quantity to Add: ";
            cin >> qty;
        
            cout << "Enter New Price: ";
            cin >> price;
        
            inv.updateStock(id, qty, price);
        }

        else if (choice == 3) {
            int id;
            cout << "Enter Product ID: ";
            cin >> id;

            inv.deleteProduct(id);
        }

        else if (choice == 4) {
            int id;
            cout << "Enter Product ID: ";
            cin >> id;

            inv.searchProduct(id);
        }

        else if (choice == 5) {
            inv.displayInventory();
        }

        else if (choice == 6) {
            inv.lowStockAlert();
        }

        else if (choice == 7) {
            cout << "Exiting...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
