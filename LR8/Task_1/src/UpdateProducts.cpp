#include "../include/product.h"

void UpdateProducts(Product* products, int size) {
    int index, new_quantity, new_workshop;
    string new_name;
    cout << "Enter index of product you want to update(0 - " << size - 1 << "): ";
    while(!(cin >> index) || index < 0 || index >= size) InvalidInput();
    cin.ignore(10000, '\n');

    cout << "Enter new name (or press enter to keep current): ";
    getline(cin, new_name);
    if (!new_name.empty()) products[index].name = new_name;
    
    cout << "Enter new quantity (or -1 to keep current): ";
    cin >> new_quantity;
    if (new_quantity != -1) products[index].quantity = new_quantity;

    cout << "Enter new workshop number (or -1 to keep current): ";
    cin >> new_workshop;
    if (new_workshop != -1) products[index].workshop_number = new_workshop;
}