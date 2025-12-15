#include "../include/book.h"

void ShowBooks(Book* books, int size) {
  for (int i = 0; i < size; i++) {
    cout << "\n---Book № " << i + 1 << "---"
         << "\nName: " << books[i].name
         << "\nAuthor: " << books[i].author
         << "\nPublisher: " << books[i].publisher
         << "\nID: " << books[i].id
         << "\nYear: " << books[i].year
         << "\nPages: " << books[i].pages
         << "\n";
  }
}
