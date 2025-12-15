#include "../include/product.h"

void ShowProducts(Product* products, int size) {
  for (int i = 0; i < size; i++) {
    cout << "\n---Product № " << i + 1 << "---"
         << "\nName: " << products[i].name
         << "\nQuantity: " << products[i].quantity
         << "\nNumber of a workshop: " << products[i].workshop_number
         << "\n";
  }
}