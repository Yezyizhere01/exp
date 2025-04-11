#include "Library.h"
#include <fstream>
#include <vector>

using namespace std;

// Function to read book records from input
vector<BookRecord> readBookRecords(istream &input)
{
    int numBooks;
    input >> numBooks;
    vector<BookRecord> records;
    for (int i = 0; i < numBooks; ++i)
    {
        string id, title, author;
        int year, copies;
        input >> id >> title >> author >> year >> copies;
        records.emplace_back(id, title, author, year, copies);
    }
    return records;
}

// Function to read borrower records from input
vector<Borrower> readBorrowerRecords(istream &input)
{
    int numBorrowers;
    input >> numBorrowers;
    vector<Borrower> borrowers;
    for (int i = 0; i < numBorrowers; ++i)
    {
        string id, name;
        int numBooks;
        input >> id >> name >> numBooks;
        vector<string> bookIDs(numBooks);
        for (int j = 0; j < numBooks; ++j)
        {
            input >> bookIDs[j];
        }
        borrowers.emplace_back(id, name, numBooks, bookIDs);
    }
    return borrowers;
}

int main()
{
    // Read book records from standard input
    vector<BookRecord> bookRecords = readBookRecords(cin);

    // Read borrower records from standard input
    vector<Borrower> borrowers = readBorrowerRecords(cin);

    // Create a library instance
    Library library(bookRecords, borrowers);

    // Display library information
    library.displayBooks();
    library.displayBorrowers();

    return 0;
}
