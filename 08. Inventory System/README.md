# 📦 Stock Management System (C++)

## 📖 Overview

This is a simple **Stock Management System** built in C++ that allows users to manage product inventory efficiently.
The system supports adding, updating, deleting, searching, and storing product data with file persistence.

---

## 🚀 Features

* ➕ Add new products
* 🔄 Update stock quantity and price
* ❌ Delete products
* 🔍 Search products by ID
* 📋 Display full inventory
* ⚠️ Low stock alerts
* 💾 File saving (data persistence using `inventory.txt`)

---

## 🛠️ Technologies Used

* C++ (OOP concepts)
* STL (`vector`, `unordered_map`)
* File Handling (`fstream`)

---

## 📂 File Structure

```
project/
│── main.cpp
│── inventory.txt   (auto-generated)
```

---

## 🧾 Data Storage

* All product data is saved in:

```
inventory.txt
```

### Format:

```
ID|Name|Quantity|Price
```

### Example:

```
101|Dell|10|1000
102|Apple|3|1500
```

---

## 📋 Menu Options

```
1. Add Product
2. Update Stock
3. Delete Product
4. Search Product
5. Display Inventory
6. Low Stock Alert
7. Exit
```

---

## ⚙️ How It Works

* Products are stored in a `vector`
* Fast lookup is done using `unordered_map`
* Data is automatically:

  * Loaded at startup
  * Saved after every change

---

## ⚠️ Limitations

* No graphical interface (CLI only)
* No user authentication
* File format is plain text (not encrypted)

---


