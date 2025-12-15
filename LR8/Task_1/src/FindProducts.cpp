#include "../include/product.h"

void FindProducts(Product* products, int size) {
  string search_name;
  int search_quantity, search_workshop;

  cout << "Enter product name to search (or press enter to skip): ";
  cin.ignore(10000, '\n');
  getline(cin, search_name);
  cout << "Enter quantity to search (or -1 to skip): ";
  while (!(cin >> search_quantity) || search_quantity < -1) InvalidInput();
  cout << "Enter workshop number to search (or -1 to skip): ";
  while (!(cin >> search_workshop) || search_workshop < -1) InvalidInput();

  for (char &c : search_name) c = tolower(c);
  bool nameGiven = !search_name.empty();
  bool quantityGiven = (search_quantity != -1);
  bool workshopGiven = (search_workshop != -1);

  for (int i = 0; i < size; i++) {
    bool match = true;

    if (nameGiven && products[i].name != search_name) {
      string name = products[i].name;
      for (char &c : name) c = tolower(c);
      if (name != search_name) match = false;
    }
    if (quantityGiven && products[i].quantity != search_quantity) match = false;
    if (workshopGiven && products[i].workshop_number != search_workshop) match = false;

    if (match) {
      cout << "\n---Product № " << i + 1 << "---"
           << "\nName: " << products[i].name
           << "\nQuantity: " << products[i].quantity
           << "\nNumber of a workshop: " << products[i].workshop_number
           << "\n\n";
    }
  }
}