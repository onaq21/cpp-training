#include "../include/book.h"

void DeleteBooks(Book*& books, int& size) {
  if (books == nullptr || size == 0) {
    cout << "No books to delete\n";
    return;
  }

  string search_name, search_author;
  int search_id;

  cout << "Enter book name to search for deletion (or press enter to skip): ";
  cin.ignore(10000, '\n');
  getline(cin, search_name);

  cout << "Enter author to search for deletion (or press enter to skip): ";
  getline(cin, search_author);

  cout << "Enter book ID to search for deletion (or -1 to skip): ";
  while (!(cin >> search_id) || search_id < -1) InvalidInput();

  bool nameGiven = !search_name.empty();
  bool authorGiven = !search_author.empty();
  bool idGiven = (search_id != -1);

  for (int i = 0; i < size; i++) {
    bool match = true;

    if (nameGiven && books[i].name != search_name) match = false;
    if (authorGiven && books[i].author != search_author) match = false;
    if (idGiven && books[i].id != search_id) match = false;

    if (match) {
      int k = 0;
      Book* temp = new Book[size - 1];
      for (int j = 0; j < size; j++) if (j != i) temp[k++] = books[j];
      delete[] books;
      books = temp;
      size--;
      i--;
    }
  }
  cout << "\n";
}
