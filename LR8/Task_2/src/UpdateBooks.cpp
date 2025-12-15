#include "../include/book.h"

void UpdateBooks(Book* books, int size) {
  int index, new_id, new_year, new_pages;
  string new_name, new_author, new_publisher;

  cout << "Enter index of book you want to update (0 - " << size - 1 << "): ";
  while (!(cin >> index) || index < 0 || index >= size) InvalidInput();
  cin.ignore(10000, '\n');

  cout << "Enter new name (or press enter to keep current): ";
  getline(cin, new_name);
  if (!new_name.empty()) books[index].name = new_name;

  cout << "Enter new author (or press enter to keep current): ";
  getline(cin, new_author);
  if (!new_author.empty()) books[index].author = new_author;

  cout << "Enter new publisher (or press enter to keep current): ";
  getline(cin, new_publisher);
  if (!new_publisher.empty()) books[index].publisher = new_publisher;

  cout << "Enter new ID (or -1 to keep current): ";
  while (!(cin >> new_id) || new_id < -1) InvalidInput();
  if (new_id != -1) books[index].id = new_id;

  cout << "Enter new year (or -1 to keep current): ";
  while (!(cin >> new_year) || new_year < -1) InvalidInput();
  if (new_year != -1) books[index].year = new_year;

  cout << "Enter new number of pages (or -1 to keep current): ";
  while (!(cin >> new_pages) || new_pages < -1) InvalidInput();
  if (new_pages != -1) books[index].pages = new_pages;
}
