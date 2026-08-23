# Library Management System (C++)

A console-based Library Management System built in C++ as a PBL (Project-Based Learning) project. It uses Object-Oriented Programming and file handling to let a librarian log in, add books, view the full catalog, and search for a book by ID and author — with data persisted to a text file so it survives between runs.

## Features

- **Login System** — Username/password authentication with a limit of 3 attempts before the program exits.
- **Add Book** — Store a new book's Title, Author, and ID.
- **Show Books** — Display the full list of books currently in the library.
- **Search Book** — Find a book by matching both Book ID and Author name.
- **Persistent Storage** — All book records are saved to `data.txt` and automatically reloaded the next time the program runs.
- **Input Validation** — Rejects non-numeric input for Book ID and menu choices instead of crashing.

## Tech Stack

- **Language:** C++
- **Concepts used:** Classes & Objects (OOP), File Handling (`ifstream` / `ofstream`), Arrays, Control Flow, Input Validation

## How It Works

1. On startup, the program asks for a username and password (3 attempts allowed).
2. After a successful login, it reads any existing books from `data.txt` into memory.
3. A menu lets you:
   - `1` → Add a new book
   - `2` → Show all books
   - `3` → Search a book by ID + Author
   - `4` → Exit (saves all data back to `data.txt`)

## How to Run

```bash
g++ Project1.cpp -o Project1
./Project1
```

**Default login credentials** (for testing/demo purposes):
- Username: `Soni`
- Password: `1234`

## File Structure

```
library-management-system/
├── Project1.cpp    # Main source code
├── data.txt        # Auto-generated file storing book records
└── README.md
```

> **Note:** `Project1.exe` (the compiled Windows executable) is not included in the repo — only the source code (`Project1.cpp`) should be pushed to GitHub. Anyone can rebuild the `.exe` from the source using the command above.

## Future Improvements

- Encrypt/hash the stored password instead of keeping it in plain text in the source code.
- Add "Delete Book" and "Update Book" options.
- Use a `vector<Book>` instead of a fixed-size array (`Book b1[100]`) to remove the book limit.
- Add multi-user support with individual login credentials.
