# 📚 Library Management System (C++)

A simple console-based Library Management System built using C++.  
This project demonstrates Object-Oriented Programming (OOP), file handling, and basic data structures.

---

## 🚀 Features

### 🔐 Admin Login
- Secure login system
- Default credentials:
  - Username: `admin`
  - Password: `1234`

### 📖 Book Management
- Add new books
- View all books
- Auto-generated Book IDs
- Stock management

### 👨‍🎓 Student Management
- Add new students
- Auto-generated Student IDs

### 📤 Issue Books
- Issue books to students
- Prevents issuing if stock is unavailable
- Stores issue records

### 📥 Return Books
- Returns issued books
- Calculates fine (₹5 per late day)
- Restores book stock
- Prevents invalid returns

### 🧾 Invoice System
- Generates receipts for:
  - Book Issue
  - Book Return
- Stored in `invoice.txt`

### 📋 Issued Books Tracking
- Displays all currently issued books

---

## 🛠️ Technologies Used

- C++
- Object-Oriented Programming (OOP)
- STL (Vector, Unordered Map)
- File Handling (ofstream)

---

## 📂 output Example

USERNAME: admin<br>
PASSWORD: 1234<br>
Login Successful!<br>

### 📖 Add Book
Enter Title: C++ Programming<br>
Enter Author: Bjarne Stroustrup<br>
Enter Quantity: 5<br>
Book Added Successfully!<br>
Generated Book ID: 1001<br>

### 👨‍🎓 Add Student
Enter Student Name: John Doe<br>
Student Added Successfully!<br>
Generated Student ID: 1<br>

### 📤 Issue Book
Enter Student ID: 1<br>
Enter Book ID: 1001<br>

===== ISSUE RECEIPT =====<br>
Student ID : 1<br>
Book ID    : 1001<br>
Book Name  : C++ Programming<br>
Status     : ISSUED<br>
Book Issued Successfully!<br>

### 📥 Return Book
Enter Student ID: 1<br>
Enter Book ID: 1001<br>
Enter Late Days: 2<br>

===== RETURN RECEIPT =====<br>
Student ID : 1<br>
Book ID    : 1001<br>
Book Name  : C++ Programming<br>
Fine       : $4<br>
Status     : RETURNED<br>
Book Returned Successfully!<br>

### 📚 Issued Books
===== ISSUED BOOK RECORDS =====<br>
Student ID : 1 | Book ID : 1001
