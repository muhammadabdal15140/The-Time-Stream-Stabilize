🕒 The Time-Stream Stabilizer

A Data Structures (BST) Project — Automatic Test Version

📌 Project Description

The Time-Stream Stabilizer is a simulation system created for the fictional Chronos Corporation, responsible for maintaining the stability of the universe’s timeline.
Each event in history is stored inside a Binary Search Tree (BST):

Year → Key

Event Name → Value

Left Subtree → Earlier events

Right Subtree → Later events

This project automatically injects historical events, resolves paradoxes, searches years, and prints the complete chronological timeline.

📚 Data Structure Used

The system uses the following TimeCapsule BST node structure:

struct TimeCapsule {
    int year;
    string eventName;
    TimeCapsule* left;
    TimeCapsule* right;
};


The project demonstrates:

BST Insertion

BST Deletion (all 3 cases)

BST Search

In-order Traversal

🛠 Implemented Operations
INJECT (Insert Event)

Adds a new event based on the year.
Maintains BST properties.

SEARCH (Find Event by Year)

Finds and prints event details.

PARADOX (Delete Event)

Deletes a node using:

Leaf removal

One-child removal

Two-child removal (inorder successor)

REPORT (Chronological Order)

Prints the entire timeline sorted by year.

AUTOMATIC SAMPLE TEST

This version automatically executes a full test without requiring input.

▶ Automatic Test Case Executed

The program automatically performs:

INJECT 2050 "Mars Colony Established"
INJECT 1969 "Moon Landing"
INJECT 2100 "Warp Drive Invented"
INJECT 2000 "Y2K Bug"
SEARCH 1969
INJECT 1990 "World Wide Web"
PARADOX 2000
REPORT
SEARCH 2000

🧪 Expected Output (Summary)
> System: Injecting 2050... Timeline stable.
> System: Injecting 1969... Timeline stable.
> System: Injecting 2100... Timeline stable.
> System: Injecting 2000... Timeline stable.

> Query: Searching for 1969...
> Result: Event Found! [1969: Moon Landing]

> System: Injecting 1990... Timeline stable.

> Alert: Paradox detected at 2000!
> System: Year 2000 removed. Timeline stabilized.

> COMMAND: CHRONOLOGICAL REPORT
-------------------------------
1969: Moon Landing
1990: World Wide Web
2050: Mars Colony Established
2100: Warp Drive Invented
-------------------------------

> Query: Searching for 2000...
> Result: Year 2000 not found in current timeline.

>>> End of Automatic Test.

🖥 How to Compile & Run
Using g++
g++ -o timestream main.cpp
./timestream

Using Code::Blocks

Create a new console project.

Replace the main.cpp with the provided code.

Build and run the project.

📦 Files Included
main.cpp      → Complete program
README.md     → Project documentation

👨‍💻 Author

Muhammad Abdal
BSAI – 3rd Semester
Data Structures Course Project
