#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

typedef struct {
  string name;
  int quantity;
  int workshop_number;
} Product;

void CreateProducts(Product*& products, int& size);
void ShowProducts(Product* products, int size);
void AddProducts(Product*& products, int& size);
void FindProducts(Product* products, int size);
void DeleteProducts(Product*& products, int& size);
void UpdateProducts(Product* products, int size);
void ShakerSortProducts(Product* products, int size);
void InvalidInput();