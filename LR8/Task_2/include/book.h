#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

struct Book {
  string author;
  string name;
  int id;
  int year;
  string publisher;
  int pages;
};

void CreateBooks(Book*& books, int& size);
void AddBooks(Book*& books, int& size);
void ShowBooks(Book* books, int size);
void FindBooks(Book* books, int size);
void UpdateBooks(Book* books, int size);
void DeleteBooks(Book*& books, int& size);
void SortBooks(Book* books, int size);
void InvalidInput();
void SaveBooksToFile(Book* books, int size, const string& filename);
void LoadBooksFromFile(Book*& books, int& size, const string& filename);
