#include <iostream>
#include <vector>
#include <string>

class Product {
public:
    std::string name;
    double price;
    int quantity;

    Product(std::string n, double p, int q) : name(n), price(p), quantity(q) {}

    bool validate() {
        if (this->name == "" && this->price <= 0 && this->quantity <= 0) {
            return false;
        }
        return true;
    }

    std::string getQuentity() {
        if (this->quantity == 0) {
            return "out of stock";
        }
        return std::to_string(this->quantity);
    }


};

class ShoppingCart {
public:
    std::vector<Product> products;

    void addProduct(Product p) {

        if(!p.validate()) return;

        if (p.quantity <= 0) {
            std::cout << "You can't add that much" << std::endl;
            return;
        }


        products.push_back(p);
    }

    void displayCart() {
        double sum = 0;
        for (auto& p : products) {
            if (p.validate()) {
                std::cout << "Product: " << p.name << ", Price: $" << p.price << ", Quantity: " << p.quantity << std::endl;
                sum += p.price;
            }
        }
        std::cout << "______________________" << std::endl;
        std::cout << "Total Sum: " << sum;
    }

};

class Store {
public:
    std::vector<Product> inventory;

    void addProductToInventory(Product p) {
        if (p.validate() || p.name != "" || p.price > 0) {
            inventory.push_back(p);
            return;
        }
        std::cout << "It is impossible to add" << std::endl;
    }

    void displayInventory() {
        for (auto& p : inventory) {
            if(p.validate()){
                std::cout << "Product: " << p.name << ", Price: $" << p.price << ", Quantity: " << p.getQuentity() << std::endl;
            }
        }
    }

    Product findProductByName(std::string name, int quantity) {
        for (auto& p : inventory) {
            if (p.name == name && p.quantity >= quantity) {
                p.quantity -= quantity;
                return Product(p.name,p.price,quantity);
            }
        }

        std::cout << "There is no such product or there is not enough in stock" << std::endl;
        return Product("", 0.0, 0);
    }
};

int main() {
    Store store;
    store.addProductToInventory(Product("Apple", 1.0, 10));
    store.addProductToInventory(Product("Banana", 0.5, 20));

    ShoppingCart cart;
    cart.addProduct(store.findProductByName("Apple",10));
    cart.addProduct(store.findProductByName("Banana",10));
    cart.addProduct(store.findProductByName("jk",4));


    std::cout << "Inventory:" << std::endl;
    store.displayInventory();

    std::cout << "\nShopping Cart:" << std::endl;
    cart.displayCart();

    return 0;
}
