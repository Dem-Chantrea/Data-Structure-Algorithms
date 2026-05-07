#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>

using namespace std;

// ================= ADMIN LOGIN =================
class AdminAuth {
public:
    bool login() {
        string username, password;

        cout << "USERNAME: ";
        cin >> username;

        cout << "PASSWORD: ";
        cin >> password;

        if (username == "admin" && password == "1234") {
            cout << "\nLogin Successful!\n";
            return true;
        }

        cout << "\nInvalid Credentials!\n";
        return false;
    }
};

// ================= BOOK CLASS =================
class Book {
public:
    int id;
    string title;
    string author;
    int quantity;

    Book() {}

    Book(int i, string t, string a, int q) {
        id = i;
        title = t;
        author = a;
        quantity = q;
    }
};

// ================= STUDENT CLASS =================
class Student {
public:
    int id;
    string name;

    Student() {}

    Student(int i, string n) {
        id = i;
        name = n;
    }
};

// ================= ISSUE RECORD =================
class IssueRecord {
public:
    int studentId;
    int bookId;

    IssueRecord(int sid, int bid) {
        studentId = sid;
        bookId = bid;
    }
};

// ================= INVOICE SYSTEM =================
class Invoice {
public:

    // Issue Invoice
    static void issue(int sid, int bid, string bookName) {

        ofstream out("invoice.txt", ios::app);

        out << "\n===== ISSUE RECEIPT =====\n";
        out << "Student ID : " << sid << "\n";
        out << "Book ID    : " << bid << "\n";
        out << "Book Name  : " << bookName << "\n";
        out << "Status     : ISSUED\n";

        out.close();
    }

    // Return Invoice
    static void ret(int sid, int bid, string bookName, int fine) {

        ofstream out("invoice.txt", ios::app);

        out << "\n===== RETURN RECEIPT =====\n";
        out << "Student ID : " << sid << "\n";
        out << "Book ID    : " << bid << "\n";
        out << "Book Name  : " << bookName << "\n";
        out << "Fine       : " << fine << "\n";
        out << "Status     : RETURNED\n";

        out.close();
    }
};

// ================= LIBRARY SYSTEM =================
class Library {

private:

    vector<Book> books;
    vector<Student> students;
    vector<IssueRecord> issuedBooks;

    unordered_map<int, int> bIndex;
    unordered_map<int, int> sIndex;

    // Auto IDs
    int nextBookId = 1001;
    int nextStudentId = 1;

public:

    // ================= ADD BOOK =================
    void addBook(string title, string author, int qty) {

        int id = nextBookId++;

        books.push_back(Book(id, title, author, qty));

        bIndex[id] = books.size() - 1;

        cout << "\nBook Added Successfully!\n";
        cout << "Generated Book ID: " << id << endl;
    }

    // ================= SHOW BOOKS =================
    void showBooks() {

        if (books.empty()) {
            cout << "No Books Available!\n";
            return;
        }

        cout << "\n========== BOOK LIST ==========\n";

        for (auto& b : books) {

            cout << "ID       : " << b.id << endl;
            cout << "Title    : " << b.title << endl;
            cout << "Author   : " << b.author << endl;
            cout << "Quantity : " << b.quantity << endl;

            cout << "---------------------------\n";
        }
    }

    // ================= ADD STUDENT =================
    void addStudent(string name) {

        int id = nextStudentId++;

        students.push_back(Student(id, name));

        sIndex[id] = students.size() - 1;

        cout << "\nStudent Added Successfully!\n";
        cout << "Generated Student ID: " << id << endl;
    }

    // ================= ISSUE BOOK =================
    void issueBook(int sid, int bid) {

        // Check student
        if (!sIndex.count(sid)) {
            cout << "Student ID not found!\n";
            return;
        }

        // Check book
        if (!bIndex.count(bid)) {
            cout << "Book ID not found!\n";
            return;
        }

        Book& b = books[bIndex[bid]];

        // Check stock
        if (b.quantity <= 0) {
            cout << "Book Out of Stock!\n";
            return;
        }

        // Reduce stock
        b.quantity--;

        // Save issue record
        issuedBooks.push_back(IssueRecord(sid, bid));

        // Save invoice
        Invoice::issue(sid, bid, b.title);

        // Console Receipt
        cout << "\n===== ISSUE RECEIPT =====\n";
        cout << "Student ID : " << sid << endl;
        cout << "Book ID    : " << bid << endl;
        cout << "Book Name  : " << b.title << endl;
        cout << "Status     : ISSUED\n";

        cout << "\nBook Issued Successfully!\n";
    }

    // ================= RETURN BOOK =================
    void returnBook(int sid, int bid, int daysLate) {

        // Check student
        if (!sIndex.count(sid)) {
            cout << "Student ID not found!\n";
            return;
        }

        // Check book
        if (!bIndex.count(bid)) {
            cout << "Book ID not found!\n";
            return;
        }

        bool found = false;

        // Check issue record
        for (int i = 0; i < issuedBooks.size(); i++) {

            if (issuedBooks[i].studentId == sid &&
                issuedBooks[i].bookId == bid) {

                found = true;

                // Remove issue record
                issuedBooks.erase(issuedBooks.begin() + i);

                break;
            }
        }

        // Prevent fake return
        if (!found) {
            cout << "This student did NOT issue this book!\n";
            return;
        }

        Book& b = books[bIndex[bid]];

        // Increase stock
        b.quantity++;

        // Fine
        int fine = daysLate * 2;

        // Save invoice
        Invoice::ret(sid, bid, b.title, fine);

        // Console Receipt
        cout << "\n===== RETURN RECEIPT =====\n";
        cout << "Student ID : " << sid << endl;
        cout << "Book ID    : " << bid << endl;
        cout << "Book Name  : " << b.title << endl;
        cout << "Fine       :$ " << fine << endl;
        cout << "Status     : RETURNED\n";

        cout << "\nBook Returned Successfully!\n";
    }

    // ================= SHOW ISSUED BOOKS =================
    void showIssuedBooks() {

        if (issuedBooks.empty()) {
            cout << "No Issued Books!\n";
            return;
        }

        cout << "\n===== ISSUED BOOK RECORDS =====\n";

        for (auto& r : issuedBooks) {

            cout << "Student ID : " << r.studentId
                << " | Book ID : " << r.bookId << endl;
        }
    }
};

// ================= MAIN =================
int main() {

    AdminAuth auth;

    if (!auth.login()) {
        return 0;
    }

    Library lib;

    int choice;

    do {

        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";

        cout << "1. Add Book\n";
        cout << "2. Add Student\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Show Books\n";
        cout << "6. Show Issued Books\n";
        cout << "7. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        // ================= ADD BOOK =================
        if (choice == 1) {

            int qty;
            string title, author;

            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            cout << "Enter Quantity: ";
            cin >> qty;

            lib.addBook(title, author, qty);
        }

        // ================= ADD STUDENT =================
        else if (choice == 2) {

            string name;

            cin.ignore();

            cout << "Enter Student Name: ";
            getline(cin, name);

            lib.addStudent(name);
        }

        // ================= ISSUE BOOK =================
        else if (choice == 3) {

            int sid, bid;

            cout << "Enter Student ID: ";
            cin >> sid;

            cout << "Enter Book ID: ";
            cin >> bid;

            lib.issueBook(sid, bid);
        }

        // ================= RETURN BOOK =================
        else if (choice == 4) {

            int sid, bid, lateDays;

            cout << "Enter Student ID: ";
            cin >> sid;

            cout << "Enter Book ID: ";
            cin >> bid;

            cout << "Enter Late Days: ";
            cin >> lateDays;

            lib.returnBook(sid, bid, lateDays);
        }

        // ================= SHOW BOOKS =================
        else if (choice == 5) {

            lib.showBooks();
        }

        // ================= SHOW ISSUED BOOKS =================
        else if (choice == 6) {

            lib.showIssuedBooks();
        }

        // ================= EXIT =================
        else if (choice == 7) {

            cout << "System Closed!\n";
        }

        else {

            cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}
