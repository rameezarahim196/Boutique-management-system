#include <iostream>
#include "BoutiqueManager.h"
#include "inventory.h"
#include "female.h"
#include "male.h"
#include "children.h"
#include <vector>
#include "nlohmann/json.hpp"
#include "boutique.h"
#include "product.h"
using namespace std;
using json = nlohmann::json;
int main() {
    int task;
    cout << "MENU:" << endl;
    cout << "1 -> Boutique " << endl;
    cout << "2 -> Inventory " << endl;
    cout << "3 -> Product " << endl;
    cin >> task;
    if (task == 1) {
        BoutiqueManager *manager = BoutiqueManager::getInstance();
        int choice;
        do {
            cout << endl;
            cout << "----------BOUTIQUE DEPARTMENT-------" << endl;
            cout << "1. Add Boutique " << endl;
            cout << "2. Remove Boutique" << endl;
            cout << "3. Display Boutiques" << endl;
            cout << "4. Exit" << endl;
            cout << "------------------------------------" << endl;
            cout << "Enter your choice (1 or 2 or 3 or 4): ";
            cin >> choice;
            switch (choice) {
                case 1: {
                    int id;
                    string name, location;
                    cout << "Enter Boutique ID: ";
                    cin >> id;
                    cout << "Enter Boutique Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Boutique Location: ";
                    getline(cin, location);
                    manager->addBoutique(Boutique(id, name, location));
                    // Save the updated data to the file
                    manager->saveToFile("boutique.json");
                    cout << "Data saved to boutique.json" << endl;
                    break;
                }
                case 2: {
                    int id;
                    // Remove a boutique
                    cout << "Enter ID of Boutique to remove: ";
                    cin >> id;
                    manager->removeBoutique(id);

                    // Save the updated data to the file after removing the boutique
                    manager->saveToFile("boutique.json");
                    cout << "Boutique removed and updated data saved to boutique.json" << endl;
                    break;
                }
                case 3: {
                    manager->displayBoutiques();
                    break;
                }
                case 4: {
                    cout << "Exiting program..." << endl;
                    break;
                }
                default: {
                    cout << "Invalid choice! Please try again." << endl;
                    break;
                }
            }
        } while (choice != 4);
    } else if (task == 2) {
        int choice;
        Inventory inventory;

        do {
            cout << "------- INVENTORY DEPARTMENT -------" << endl;
            cout << "1. Add Inventory" << endl;
            cout << "2. update Inventory" << endl;
            cout << "3. Remove Inventory" << endl;
            cout << "4. Display Inventory" << endl;
            cout << "5. Find Inventory by name" << endl;
            cout << "-----------------------------------" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    cout << "Enter inventory details:" << endl;
                    cin >> inventory;
                    inventory.addInventoryInJSONArray(inventory);
                    break;
                }
                case 2: {
                    string itemNameToUpdate;
                    cout << "Enter the name of the inventory item you want to update: ";
                    cin >> itemNameToUpdate;
                    cout << "Enter updated details for the inventory item:" << endl;
                    cin >> inventory;
                    // Update inventory item with new details
                    inventory.updateInventoryInJSONArray(inventory);
                    break;
                }
                case 3: {
                    // Take input from user to remove an inventory item
                    string itemNameToRemove;
                    cout << "Enter the name of the inventory item you want to remove: ";
                    cin >> itemNameToRemove;
                    // Remove inventory item by name
                    inventory.removeInventoryByName(itemNameToRemove);
                    break;
                }
                case 4: {
                    cout << "Inventory Details:" << endl;
                    cout << inventory;
                    break;
                }
                case 5: {
                    string itemName;
                    cout << "enter item name to find :";
                    cin >> itemName;
                    inventory.findInventoryItemByName(itemName);
                    break;
                }
                default: {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }
        } while (choice != 5);

    } else if (task == 3) {
        int choice1;
        cout << endl;
        cout << "Welcome to Product department! " << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Remove Product" << endl;
        cout << "3. Update Product" << endl;
        cout << "4, display products" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice (1, 2, 3, or 0): ";
        cin >> choice1;

        if (choice1 >= 1 && choice1 <= 3) {
            int productType;
            cout << "Select product type:" << endl;
            cout << "1. Male Product" << endl;
            cout << "2. Female Product" << endl;
            cout << "3. Children Product" << endl;
            cout << "Enter product type (1, 2, or 3): ";
            cin >> productType;

            if (productType == 1) {
                // Male Product actions
                MaleProduct maleProduct;
                switch (choice1) {
                    case 1: {
                        // Adding a product
                        string name;
                        double price;
                        string itemName;
                        int quantity;
                        double totalPrice;

                        cout << "Enter Product Name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter Price: $";
                        cin >> price;
                        cout << "Enter Inventory Item Name: ";
                        cin.ignore();
                        getline(cin, itemName);
                        cout << "Enter Inventory Quantity: ";
                        cin >> quantity;
                        cout << "Enter Inventory Total Price: $";
                        cin >> totalPrice;
                        Inventory inventory(itemName, quantity, totalPrice, Boutique());
                        MaleProduct product(name, price, "male", &inventory);
                        if (name == "suit") { product.addSuit(product); }
                        else if (name == "coat") { product.addCoat(product); }
                        else {
                            cout << "invalid choice";
                        }
                        break;
                    }
                    case 2: {
                        MaleProduct product;
                        string name;
                        cout << "Enter Product name to remove : ";
                        cin >> name;
                        if (name == "suit") { product.removeSuit(product); }
                        else if (name == "coat") { product.removeCoat(product); }
                        else {
                            cout << "invalid choice";
                        }
                        break;
                    }
                    case 3: {
                        MaleProduct product;
                        // Take input for the updated product details from the user
                        string name;
                        double price;
                        string itemName;
                        int quantity;
                        double totalPrice;
                        cout << "Enter updated Product Name: ";
                        cin.ignore(); // Ignore the newline character left in the buffer
                        getline(cin, name);
                        cout << "Enter updated Price: $";
                        cin >> price;
                        cout << "Enter updated Inventory Item Name: ";
                        cin.ignore();
                        getline(cin, itemName);
                        cout << "Enter updated Inventory Quantity: ";
                        cin >> quantity;
                        cout << "Enter updated Inventory Total Price: $";
                        cin >> totalPrice;
                        Inventory inventory(itemName, quantity, totalPrice, Boutique());
                        if (name == "suit") { product.updateSuit(product); }
                        else if (name == "coat") { product.updateCoat(product); }
                        else {
                            cout << "invalid choice";
                        }
                        break;
                    }
                }
            } else if (productType == 2) {
                switch (choice1) {
                    case 1: {
                        // Adding a product
                        string name;
                        double price;
                        string itemName;
                        int quantity;
                        double totalPrice;
                        string type;
                        cout << "Enter Product Name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter Price: $";
                        cin >> price;
                        cout << "Enter Inventory Item Name: ";
                        cin.ignore();
                        getline(cin, itemName);
                        cout << "Enter Inventory Quantity: ";
                        cin >> quantity;
                        cout << "Enter Inventory Total Price: $";
                        cin >> totalPrice;
                        Inventory inventory(itemName, quantity, totalPrice, Boutique());
                        FemaleProduct product(name, price, "female", &inventory);
                        if (name == "suit") { product.addSuit(product); }
                        else if (name == "scarf") { product.addScarf(product); }
                        else {
                            cout << "invalid choice";
                        }
                        break;
                    }
                    case 2: {
                        string name;
                        Inventory inventory("", 0, 0.0, Boutique());
                        FemaleProduct product(name, 0, "female", &inventory);
                        cout << "Enter Product name to remove : ";
                        cin >> name;
                        if (name == "suit") { product.removeSuit(product); }
                        else if (name == "scarf") { product.removeScarf(product); }
                        else {
                            cout << "invalid choice";
                        }
                        break;
                    }
                    case 3: {

                        // Take input for the updated product details from the user
                        string name;
                        double price;
                        string itemName;
                        int quantity;
                        double totalPrice;

                        cout << "Enter updated Product Name: ";
                        cin.ignore(); // Ignore the newline character left in the buffer
                        getline(cin, name);
                        cout << "Enter updated Price: $";
                        cin >> price;
                        cout << "Enter updated Inventory Item Name: ";
                        cin.ignore();
                        getline(cin, itemName);
                        cout << "Enter updated Inventory Quantity: ";
                        cin >> quantity;
                        cout << "Enter updated Inventory Total Price: $";
                        cin >> totalPrice;
                        Inventory inventory(itemName, quantity, totalPrice, Boutique());
                        FemaleProduct product(name, price, "female", &inventory);
                        if (name == "suit") { product.updateSuit(product); }
                        else if (name == "scarf") { product.updateScarf(product); }
                        else {
                            cout << "invalid choice";
                        }
                        break;
                    }
                }
            } else if (productType == 3) {
                // Children Product actions
                switch (choice1) {
                    case 1: {
                        // Adding a product
                        string name;
                        double price;
                        string itemName;
                        int quantity;
                        double totalPrice;

                        cout << "Enter Product Name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter Price: $";
                        cin >> price;
                        cout << "Enter Inventory Item Name: ";
                        cin.ignore();
                        getline(cin, itemName);
                        cout << "Enter Inventory Quantity: ";
                        cin >> quantity;
                        cout << "Enter Inventory Total Price: $";
                        cin >> totalPrice;
                        Inventory inventory(itemName, quantity, totalPrice, Boutique());
                        KidsProduct product(name, price, "kids", &inventory);
                        if (name == "shirt") { product.addShirt(product); }
                        else if (name == "pant") { product.addPant(product); }
                        else if (name == "suit") { product.addSuit(product); }
                        else {
                            cout << "invalid choice";
                        }
                        break;
                    }
                    case 2: {
                        string name;
                        Inventory inventory("", 0, 0.0, Boutique());
                        KidsProduct product(name, 0.0, "kids", &inventory);
                        cout << "Enter Product name to remove : ";
                        cin >> name;
                        if (name == "shirt") { product.removeShirt(product); }
                        else if (name == "pant") { product.removePant(product); }
                        else if (name == "suit") { product.removeSuit(product); }
                        else {
                            cout << "invalid choice";
                        }
                        break;
                    }
                    case 3: {
                        // Take input for the updated product details from the user
                        string name;
                        double price;
                        string itemName;
                        int quantity;
                        double totalPrice;
                        cout << "Enter updated Product Name: ";
                        cin.ignore(); // Ignore the newline character left in the buffer
                        getline(cin, name);
                        cout << "Enter updated Price: $";
                        cin >> price;
                        cout << "Enter updated Inventory Item Name: ";
                        cin.ignore();
                        getline(cin, itemName);
                        cout << "Enter updated Inventory Quantity: ";
                        cin >> quantity;
                        cout << "Enter updated Inventory Total Price: $";
                        cin >> totalPrice;
                        Inventory inventory(itemName, quantity, totalPrice, Boutique());
                        KidsProduct product(name, price, "kids", &inventory);
                        if (name == "shirt") { product.updateShirt(product); }
                        else if (name == "pant") { product.updatePant(product); }
                        else if (name == "suit") { product.updateSuit(product); }
                        else {
                            cout << "invalid choice";
                        }
                        break;
                    }
                }
            }
        } else if (choice1 == 4) {
            Inventory inventory("", 0, 0.0, Boutique());
            KidsProduct product("", 0.0, "kids", &inventory);
            FemaleProduct femaleProduct("", 0, "female", &inventory);
            MaleProduct maleProduct;

            cout << "Displaying products using Product class:" << endl;
            maleProduct.displayFromJsonFile("product.json");
            cout << endl;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }

    }
    }