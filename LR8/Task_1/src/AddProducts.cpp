#include "../include/product.h"

void AddProducts(Product*& products, int& size) {
  string name;
  while (true) {
    cout << "\n---Product № " << size + 1 << "---\n";
    cout << "Enter name of product (or 'done' to finish): ";
    cin >> name;
    for (char &c : name) c = tolower(c);
    if (name == "done") break;

    Product* temp = new Product[size + 1];
    for (int i = 0; i < size; i++) temp[i] = products[i];
    delete[] products;
    products = temp;

    products[size].name = name;
    cout << "Enter quantity: ";
    while (!(cin >> products[size].quantity) || products[size].quantity < 0) InvalidInput();
    cout << "Enter number of workshops: ";
    while (!(cin >> products[size].workshop_number) || products[size].workshop_number < 0) InvalidInput();
    size++;
  }
  cout << "\n";
}