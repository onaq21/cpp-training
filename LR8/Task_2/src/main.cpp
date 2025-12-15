#include <iostream>
#include "../include/book.h"

using namespace std;

int main() {
  Book* books = nullptr;
  int size = 0;
  bool running = true;

  while (running) {
    cout << "-----Library Manager-----\n"
         << "1. Create library\n"
         << "2. Add books\n"
         << "3. Show all books\n"
         << "4. Find books\n"
         << "5. Update book\n"
         << "6. Delete books\n"
         << "7. Show books sorted by author's last name after a certain year\n"
         << "8. Save library to file\n"
         << "9. Load library from file\n"
         << "10. Exit\n"
         << "Enter your choice (1-10): ";

    int choice;
    while (!(cin >> choice)) {
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "Invalid input. Enter a number from 1 to 10: ";
    }

    switch (choice) {
      case 1: 
        CreateBooks(books, size);
        break;
      case 2:
        AddBooks(books, size);
        break;
      case 3: 
        ShowBooks(books, size);
        break;
      case 4: 
        FindBooks(books, size);
        break;
      case 5: 
        UpdateBooks(books, size);
        break;
      case 6: 
        DeleteBooks(books, size);
        break;
      case 7: 
        SortBooks(books, size);
        break;
      case 8: 
        SaveBooksToFile(books, size, "library.txt");
        break;
      case 9: 
        LoadBooksFromFile(books, size, "library.txt");
        break;
      case 10: 
        running = false;
        break;
      default:
        cout << "This option doesn't exist :(\n";
        cin.ignore(10000, '\n');
    }
  } 

  if (books != nullptr) {
    delete[] books;
    books = nullptr;
  }

  return 0;
}
