#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class to represent a Book
class Book
{
public:
    string title;
    string author;
    int id;

    Book(string t, string a, int i) : title(t), author(a), id(i) {}
};

// Library class to manage books
class Library
{
private:
    vector<Book> books;
    int nextId = 1;

public:
    void addBook(string title, string author)
    {
        books.push_back(Book(title, author, nextId));
        nextId++;
        cout << "Book added successfully." << endl;
    }

    void displayBooks()
    {
        cout << "Library Books:" << endl;
        for (const Book &book : books)
        {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << endl;
        }
    }

    void removeBook(int bookId)
    {
        for (auto it = books.begin(); it != books.end(); ++it)
        {
            if (it->id == bookId)
            {
                books.erase(it);
                cout << "Book removed successfully." << endl;
                return;
            }
        }
        cout << "Book with ID " << bookId << " not found." << endl;
    }
};

int main()
{
    Library library;

    while (true)
    {
        cout << "\n\n---------------> Library Management System <--------------" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Remove Book" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Enter Input = ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cerr << "\n Invalid input, Please enter a valid integer." << endl;
            cin.clear();  
            cin.ignore();  
            continue;  
        }

        
            if (choice == 1)
            {
                string title, author;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                library.addBook(title, author);
            }
            else if (choice == 2)
            {
                library.displayBooks();
            }
            else if (choice == 3)
            {
                int bookId;
                cout << "Enter book ID to remove: ";
                cin >> bookId;
                library.removeBook(bookId);
            }
            else if (choice == 4)
            {
                cout << "Exiting..." << endl;
                return 0;
            }
            else
            {
               cout << "Invalid choice. Please select a valid option.\n";
            }
    }
    return 0;
}