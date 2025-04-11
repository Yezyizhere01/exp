#include "Library.h"

// BookRecord implementation
BookRecord::BookRecord(const string &id, const string &title, const string &author, int year, int copies)
    : bookID(id), title(title), author(author), yearPublished(year), totalCopies(copies), availableCopies(copies)
{
    if (id.empty() || !isupper(id[0]))
    {
        cerr << "Error: Book ID must start with an uppercase letter." << endl;
        exit(EXIT_FAILURE);
    }
    if (to_string(year).length() != 4 || (year < 1000 || year > 2999))
    {
        cerr << "Error: Year of publication must be a 4-digit number starting with 1 or 2." << endl;
        exit(EXIT_FAILURE);
    }
}

int BookRecord::getAvailableCopies() const
{
    return availableCopies;
}

int BookRecord::getTotalCopies() const
{
    return totalCopies;
}

void BookRecord::display() const
{
    cout << "Book ID: " << bookID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year published: " << yearPublished << endl;
    cout << "Total number of copies: " << totalCopies << endl;
    cout << "Number available for loan: " << availableCopies << endl;
}

// Borrower implementation
Borrower::Borrower(const string &id, const string &name, int numBooks, const vector<string> &bookIDs)
    : borrowerID(id), name(name), numberOfBooksLoaned(numBooks), bookIDs(bookIDs)
{
    if (id.length() != 5 || id.find_first_not_of("0123456789") != string::npos)
    {
        cerr << "Error: Borrower ID must be 5 digits." << endl;
        exit(EXIT_FAILURE);
    }
}

void Borrower::display() const
{
    cout << "Borrower ID: " << borrowerID << endl;
    cout << "Name: " << name << endl;
    cout << "Number of loaned books: " << numberOfBooksLoaned << endl;
    cout << "IDs of books on loan: ";
    for (const auto &id : bookIDs)
    {
        cout << id << " ";
    }
    cout << endl;
}

// Catalogue implementation
Catalogue::Catalogue(const vector<BookRecord> &records) : bookRecords(records) {}

void Catalogue::display() const
{
    cout << "Total number of books in catalogue: " << bookRecords.size() << endl;
    for (size_t i = 0; i < bookRecords.size(); ++i)
    {
        cout << "Book Record " << i << endl;
        cout << "=============" << endl;
        bookRecords[i].display();
    }
}

// Library implementation
Library::Library(const vector<BookRecord> &bookRecords, const vector<Borrower> &borrowers)
    : catalogue(bookRecords), borrowers(borrowers)
{
    totalBooksOnLoan = 0;
    totalBorrowers = borrowers.size();

    for (const auto &book : bookRecords)
    {
        totalBooksOnLoan += book.getTotalCopies() - book.getAvailableCopies();
    }
}

Library::~Library() {}

void Library::displayBooks() const
{
    cout << "Total number of books on loan: " << totalBooksOnLoan << endl;
    catalogue.display();
}

void Library::displayBorrowers() const
{
    cout << "Total number of borrowers: " << totalBorrowers << endl;
    for (size_t i = 0; i < borrowers.size(); ++i)
    {
        cout << "Borrower " << i << endl;
        cout << "===========" << endl;
        borrowers[i].display();
    }
}
