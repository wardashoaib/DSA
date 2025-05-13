#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    Book* next;

    Book(int bookID, string bookTitle, string bookAuthor) {
        id = bookID;
        title = bookTitle;
        author = bookAuthor;
        next = nullptr;
    }
};

class Library {
private:
    Book* head;

public:
    Library() {
        head = nullptr;
    }

    void addBook(int id, string title, string author) {
        Book* newBook = new Book(id, title, author);
        newBook->next = head;
        head = newBook;
        cout << "Book added successfully!" << endl;
    }

    void displayBooks() {
        if (head == nullptr) {
            cout << "No books available." << endl;
            return;
        }

        Book* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << ", Title: " << temp->title << ", Author: " << temp->author << endl;
            temp = temp->next;
        }
    }

    void removeBook(int id) {
        if (head == nullptr) {
            cout << "No books to remove." << endl;
            return;
        }

        if (head->id == id) {
            Book* temp = head;
            head = head->next;
            delete temp;
            cout << "Book removed successfully!" << endl;
            return;
        }

        Book* temp = head;
        while (temp->next && temp->next->id != id) {
            temp = temp->next;
        }

        if (temp->next) {
            Book* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Book removed successfully!" << endl;
        } else {
            cout << "Book with ID " << id << " not found!" << endl;
        }
    }

    Book* searchBook(int id) {
        Book* temp = head;
        while (temp) {
            if (temp->id == id) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};

class IssueQueue {
private:
    queue<int> requests;

public:
    void addRequest(int bookID) {
        requests.push(bookID);
    }

    void processRequest(Library& library) {
        if (!requests.empty()) {
            int bookID = requests.front();
            Book* book = library.searchBook(bookID);
            if (book) {
                cout << "Book issued: " << book->title << endl;
            } else {
                cout << "Book with ID " << bookID << " not found." << endl;
            }
            requests.pop();
        } else {
            cout << "No pending issue requests." << endl;
        }
    }
};

class ReturnHistory {
private:
    stack<int> returnStack;

public:
    void addReturn(int bookID) {
        returnStack.push(bookID);
    }

    void showHistory() {
        if (returnStack.empty()) {
            cout << "No return history yet." << endl;
            return;
        }

        cout << "Return History:" << endl;
        while (!returnStack.empty()) {
            cout << "Book ID: " << returnStack.top() << endl;
            returnStack.pop();
        }
    }
};

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
    system("cls");
}

int main() {
    Library library;
    IssueQueue issueQueue;
    ReturnHistory returnHistory;

    int choice;

    do {
        system("cls");

        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Display Books" << endl;
        cout << "4. Issue Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Display Return History" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice (1-7): ";
        cin >> choice;
        cin.ignore();

        int id;
        string title, author;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Book Title: ";
                getline(cin, title);
                cout << "Enter Book Author: ";
                getline(cin, author);
                library.addBook(id, title, author);
                break;

            case 2:
                cout << "Enter Book ID to remove: ";
                cin >> id;
                library.removeBook(id);
                break;

            case 3:
                library.displayBooks();
                break;

            case 4:
                cout << "Enter Book ID to issue: ";
                cin >> id;
                issueQueue.addRequest(id);
                issueQueue.processRequest(library);
                break;

            case 5:
                cout << "Enter Book ID to return: ";
                cin >> id;
                returnHistory.addReturn(id);
                cout << "Book returned successfully!" << endl;
                break;

            case 6:
                returnHistory.showHistory();
                break;

            case 7:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

        if (choice != 7) {
            pauseScreen();
        }

    } while (choice != 7);

    return 0;
}

