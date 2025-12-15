#include "../include/book.h"

void SortBooks(Book* books, int size) {
  if (books == nullptr || size == 0) {
    cout << "Library is empty!\n";
    return;
  }

  int year;
  cout << "Enter year: ";
  while (!(cin >> year) || year <= 0) InvalidInput();

  for (int i = 1; i < size; ++i) {
    Book key = books[i];
    int j = i - 1;
    while (j >= 0 && books[j].author > key.author) {
      books[j + 1] = books[j];
      j--;
    }
    books[j + 1] = key;
  }

  int count = 1;
  bool found = false;
  for (int i = 0; i < size; i++) {
    if (books[i].year > year) {
      cout << "---Book № " << count++ << "---"
          << "\nAuthor: " << books[i].author
          << "\nName: " << books[i].name
          << "\nId: " << books[i].id
          << "\nYear: " << books[i].year
          << "\nPublisher: " << books[i].publisher
          << "\nPages: " << books[i].pages << "\n";
      found = true;
    }
  }
  if (!found) cout << "No books after year " << year;
}