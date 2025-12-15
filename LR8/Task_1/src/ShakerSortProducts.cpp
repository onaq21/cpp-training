#include "../include/product.h"

void ShakerSortProducts(Product* products, int size) {
  int left = 0, right = size - 1;
  while (left < right) {
    for (int i = left; i < right; i++) {
      if (products[i].quantity < products[i + 1].quantity) std::swap(products[i], products[i + 1]);
    }
    right--;
    for (int i = right; i > left; i--) {
      if (products[i].quantity > products[i - 1].quantity) std::swap(products[i], products[i - 1]);
    }
    left++;
  }
  cout << "Done\n";
}