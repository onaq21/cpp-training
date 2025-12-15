#include "../include/book.h"

void CreateBooks(Book*& books, int& size) {
  size = 0;
  string author;
  while (true) {
    cout << "---Product № " << size + 1 << "---\n";
    cout << "Enter author of book (or 'done' to finish): ";
    cin.ignore(1000,'\n');
    getline(cin, author);
    string temp_author = author;
    for (char &c : temp_author) c = tolower(c);
    if (temp_author == "done") break;

    Book* temp = new Book[size + 1];
    for (int i = 0; i < size; i++) temp[i] = books[i];
    delete[] books;
    books = temp;

    books[size].author = author;
    cout << "Enter name: ";
    getline(cin, books[size].name);
    cout << "Enter id: ";
    while (!(cin >> books[size].id) || books[size].id < 0) InvalidInput();
    cout << "Enter year: ";
    while (!(cin >> books[size].year) || books[size].year < 0) InvalidInput(); 
    cin.ignore(1000, '\n');
    cout << "Enter publisher: ";
    getline(cin, books[size].publisher);
    cout << "Enter pages: ";
    while (!(cin >> books[size].pages) || books[size].pages < 0) InvalidInput();
    size++;
  }
  cout << "\n";
}