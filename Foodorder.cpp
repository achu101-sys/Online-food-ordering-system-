#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


struct FoodItem {
    std::string name;
    double price;
};


struct Order {
    FoodItem item;
    int quantity;
};

class FoodOrderSystem {
private:
    std::vector<FoodItem> menu;
    std::vector<Order> currentOrder;

public:
    FoodOrderSystem() {
        
        menu.push_back({"Pizza", 8.99});
        menu.push_back({"Burger", 5.49});
        menu.push_back({"Pasta", 6.75});
        menu.push_back({"Salad", 4.25});
        menu.push_back({"Soda", 1.99});
    }

    
    void displayMenu() {
        std::cout << "----- Food Menu -----\n";
        for (int i = 0; i < menu.size(); ++i) {
            std::cout << i + 1 << ". " << menu[i].name << " - $" << menu[i].price << std::endl;
        }
    }

    
    void takeOrder() {
        int choice, quantity;
        char moreOrders = 'y';

        while (moreOrders == 'y' || moreOrders == 'Y') {
            displayMenu();
            std::cout << "Enter the number of the item you'd like to order: ";
            std::cin >> choice;

            if (choice < 1 || choice > menu.size()) {
                std::cout << "Invalid selection. Please try again.\n";
                continue;
            }

            std::cout << "Enter the quantity: ";
            std::cin >> quantity;

            
            Order newOrder = {menu[choice - 1], quantity};
            currentOrder.push_back(newOrder);

            std::cout << "Would you like to order another item? (y/n): ";
            std::cin >> moreOrders;
        }
    }

    
    double calculateTotal() {
        double total = 0.0;
        for (const auto& order : currentOrder) {
            total += order.item.price * order.quantity;
        }
        return total;
    }


    void displayOrderSummary() {
        std::cout << "\n----- Order Summary -----\n";
        for (const auto& order : currentOrder) {
            std::cout << order.item.name << " x " << order.quantity << " = $" 
                      << std::fixed << std::setprecision(2) << order.item.price * order.quantity << std::endl;
        }
        std::cout << "\nTotal Amount: $" << calculateTotal() << std::endl;
    }

    
    void deliverOrder() {
        std::cout << "\nYour order is on the way! Expect delivery soon.\n";
    }
};

int main() {
    FoodOrderSystem system;

    std::cout << "Welcome to the Food Ordering System!\n";

    
    system.takeOrder();

    
    system.displayOrderSummary();


    system.deliverOrder();

    return 0;
}
