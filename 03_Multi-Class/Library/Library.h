#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// BookRecord class
class BookRecord
{
public:
    BookRecord(const string &id, const string &title, const string &author, int year, int copies);
    ~BookRecord() = default;

    string getBookID() const { return bookID; }
    void display() const;
    int getAvailableCopies() const;
    int getTotalCopies() const;

private:
    string bookID;
    string title;
    string author;
    int yearPublished;
    int totalCopies;
    int availableCopies;
};

// Borrower class
class Borrower
{
public:
    Borrower(const string &id, const string &name, int numBooks, const vector<string> &bookIDs);
    ~Borrower() = default;

    void display() const;

private:
    string borrowerID;
    string name;
    int numberOfBooksLoaned;
    vector<string> bookIDs;
};

// Catalogue class
class Catalogue
{
public:
    Catalogue(const vector<BookRecord> &records);
    ~Catalogue() = default;

    void display() const;

private:
    vector<BookRecord> bookRecords;
};

// Library class
class Library
{
public:
    Library(const vector<BookRecord> &bookRecords, const vector<Borrower> &borrowers);
    ~Library();

    void displayBooks() const;
    void displayBorrowers() const;

private:
    int totalBooksOnLoan;
    int totalBorrowers;
    Catalogue catalogue;
    vector<Borrower> borrowers;
};

#endif // LIBRARY_H
