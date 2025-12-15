#include "../include/book.h"

void AddBooks(Book*& books, int& size) {
  string author, name, publisher;
  int id, year, pages;

  while (true) {
    cout << "\n---Book № " << size + 1 << "---\n";
    cout << "Enter book name (or 'done' to finish): ";
    cin.ignore(10000, '\n');
    getline(cin, name);
    if (name == "done") break;

    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter publisher: ";
    getline(cin, publisher);

    cout << "Enter ID: ";
    while (!(cin >> id) || id < 0) InvalidInput();
    cout << "Enter year: ";
    while (!(cin >> year) || year < 0) InvalidInput();
    cout << "Enter number of pages: ";
    while (!(cin >> pages) || pages <= 0) InvalidInput();

    Book* temp = new Book[size + 1];
    for (int i = 0; i < size; i++) temp[i] = books[i];
    delete[] books;
    books = temp;

    books[size].name = name;
    books[size].author = author;
    books[size].publisher = publisher;
    books[size].id = id;
    books[size].year = year;
    books[size].pages = pages;
    size++;
  }
  cout << "\n";
}
