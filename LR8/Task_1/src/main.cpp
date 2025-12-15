#include "../include/product.h"

int main() {
  Product* products = nullptr;
  int size = 0;
  bool running = true;
  while (running) {
    cout << "-----Factory Production Manager-----\n"
         << "1. Create products\n"
         << "2. Show all products\n"
         << "3. Add a new product\n"
         << "4. Find a product\n"
         << "5. Delete a product\n"
         << "6. Update a product\n"
         << "7. Sort products by quantity (descending)\n"
         << "8. Exit\n"
         << "Enter your choice (1-8): ";
    char choice;
    while (!(cin >> choice)) InvalidInput();

    switch (choice) {
      case '1': 
        CreateProducts(products, size);
        break;
      case '2':
        ShowProducts(products, size);
        break;
      case '3':
        AddProducts(products, size);
        break;
      case '4':
        FindProducts(products, size);
        break;
      case '5':
        DeleteProducts(products, size);
        break;
      case '6':
        UpdateProducts(products, size);
        break;
      case '7':
        ShakerSortProducts(products, size);
        break;
      case '8':
        running = false;
        break;
      default:
        cout << "This option doesn't exist :(\n";
        cin.ignore(10000, '\n');
    }
  }

  if (products != nullptr) {
    delete[] products;
    products = nullptr;
  }
}