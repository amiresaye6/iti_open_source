
# Bash Shell Script Database Management System (DBMS)

## Project Overview
This project is a **CLI-based Database Management System** implemented entirely using **Bash scripting**.
It enables users to create, manage, and manipulate databases and tables stored directly on the Linux file system,
without using any external database engine.

The project was developed as part of the **Bash Scripting Course at ITI**, with the goal of understanding how
database systems work internally.

---

## Technologies Used
- Bash Shell Scripting
- Linux File System
- Linux text processing utilities:
  - awk
  - sed
  - cut
  - grep

---

## Project Structure
```
.
├── dbms.sh          # Main executable script
├── *.db/            # Databases (directories)
│   ├── table.tbl    # Tables (files)
```

- **Database** → Directory ending with `.db`
- **Table** → File ending with `.tbl`
- **First line of each table file** → Metadata (columns, data types, primary key)

---

## Features

### Database-Level Operations
- Create Database
- List Databases
- Connect To Database
- Drop Database

### Table-Level Operations
- Create Table
- List Tables
- Drop Table
- Insert Into Table
- Select From Table
  - Select All
  - Select Column
  - Select By Column Value
- Update Table Records
- Delete From Table
  - Delete All
  - Delete By Column Value

---

## Table Rules & Constraints
- Supported Data Types:
  - int
  - string
- Only **one primary key** is allowed per table
- Primary key values must be **unique**
- Data type validation is enforced on insert and update
- Special characters (`|` and `:`) are restricted to preserve data integrity

---

## How to Run the Project

### 1. Clone the Repository
```
git clone <REPOSITORY_URL>
cd <REPOSITORY_NAME>
```

### 2. Give Execute Permission
```
chmod +x dbms.sh
```

### 3. Run the Script
```
./dbms.sh
```

---

## How to Use the Script

### Main Menu
After running the script, you will see the main menu:
```
1) Create Database
2) List Databases
3) Connect To Database
4) Drop Database
5) Quit
```

- Choose an option by entering its number.

### Create Database
- Enter a database name
- A directory with `.db` extension will be created

### List Databases
- Displays all existing databases in the current directory

### Connect To Database
- Enter the database name
- You will be moved into the database directory
- A second menu will appear for table operations

---

## Database Menu (After Connection)

```
1) Create Table
2) List Tables
3) Drop Table
4) Insert Into Table
5) Select From Table
6) Delete From Table
7) Update Table
8) Exit Database
```

### Create Table
- Enter table name
- Specify number of columns
- For each column:
  - Column name
  - Data type (int or string)
  - Whether it is a primary key

### List Tables
- Displays all tables in the current database

### Drop Table
- Deletes a selected table file

### Insert Into Table
- Prompts for each column value
- Validates:
  - Data type
  - Primary key uniqueness

### Select From Table
Options:
- Select All → Displays all rows
- Select Column → Displays values of a specific column
- Select By Column → Displays rows matching a value

### Delete From Table
Options:
- Delete All → Deletes all records (keeps metadata)
- Delete By Column → Deletes rows matching a condition

### Update Table
- Select a column to search by
- Select a column to update
- Validates:
  - Data type
  - Primary key uniqueness (if applicable)

### Exit Database
- Returns to the main menu

---

## Learning Outcomes
- Understanding DBMS core concepts
- Using the file system as persistent storage
- Writing structured, validated Bash scripts
- Using awk, sed, and grep for data processing
- Handling user input safely in CLI applications

---

## Future Improvements
- SQL-like command support
- Better output formatting
- Indexing for faster search
- Simple GUI on top of the Bash engine

---

## Contributors
- Amir Alsayed
- Project Partner (ITI Bash Course)

---

## License
This project is intended for **educational purposes**.
