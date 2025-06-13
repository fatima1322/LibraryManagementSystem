# ENSIA Library Management System

Welcome to the **ENSIA Library Management System** — a C++ project designed to help manage library operations such as managing books, users (students and faculty), loans, and reservations. This system was built using Object-Oriented Programming principles and supports file-based data storage using JSON.

---

## 🔧 Features

### ➕ Resource & User Management
- Add, edit, delete, and search resources like books, articles, and theses.
- Manage different user types: Students, Teachers, and Library Staff.

### 📚 Loan & Reservation System
- Borrow, return, and renew loans.
- Make and manage reservations.
- Overdue and availability notifications.

### 📊 Statistics & Reporting
- View total resources, users, active loans, available items, and reservations.

### ✅ Data Validation & Exception Handling
- Ensures valid data entry and prevents crashes via exception management.

### 🔐 Unique Identifiers
- Automatically generates unique IDs for users, resources, loans, and reservations.

---

## 📁 File Structure

- `src/` - All `.cpp` source files
- `include/` - All `.h` header files
- `data/` - JSON files for storing users, resources, loans, and reservations
- `main.cpp` - Entry point of the application

---

## 💾 How to Run the Project

1. **Clone or Download the Repository**
2. **Ensure JSON for Modern C++ (`nlohmann/json`) is available**
3. **Build the Project using your C++ compiler (e.g., g++, clang++)**

```bash
g++ -std=c++17 -Iinclude src/*.cpp -o library_app
./library_app
```

---

## 🧪 Testing

- Manually test core features via the console interface.
- Ensure JSON files are readable and writeable.
- Validate user and resource creation via logging or output messages.

---

## ❌ Troubleshooting

- **Compilation Errors**: Ensure all `.h` and `.cpp` files are included in your build.
- **File Errors**: Make sure the `data/` directory exists with read/write permission.
- **Missing JSON Library**: Download it from [https://github.com/nlohmann/json](https://github.com/nlohmann/json)

---

## 📚 Concepts Applied

- Object-Oriented Programming: Inheritance, Polymorphism, Composition
- Dynamic Memory Management with smart pointers
- Exception Handling
- STL Data Structures: `vector`, `map`, `count_if`, etc.
- Separation of Concerns and Modular Design

---

## 📦 Storage Format

All data is stored using **JSON** files via the `JsonFileHandler` class:
- `resources.json`
- `users.json`
- `loans.json`
- `reservations.json`

---

## 👥 Contributors

- Benikdes Naima Fatima Zohra (ENSIA Student)

---

## 📃 License

This project is licensed under the MIT License — see the LICENSE file for details.

---

## 📞 Feedback

If you have suggestions or want to improve the system, feel free to reach out via ENSIA’s official channels or by opening an issue in your GitHub repository.
