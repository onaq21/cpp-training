#include "../include/book.h"

void FindBooks(Book* books, int size) {
  string search_name, search_author;
  int search_id;

  cout << "Enter book name to search (or press enter to skip): ";
  cin.ignore(10000, '\n');
  getline(cin, search_name);

  cout << "Enter author to search (or press enter to skip): ";
  getline(cin, search_author);

  cout << "Enter book ID to search (or -1 to skip): ";
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
}
