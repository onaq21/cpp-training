#include "../include/product.h"

void CreateProducts(Product*& products, int& size) {
  size = 0;
  string name;
  while (true) {
    cout << "---Product № " << size + 1 << "---\n";
    cout << "Enter name of product (or 'done' to finish): ";
    cin >> name;
    string temp_name = name;
    for (char &c : temp_name) c = tolower(c);
    if (temp_name == "done") break;

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