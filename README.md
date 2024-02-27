This little C++ program uses the ncurses library to 'visualize' the memory of a
process identified by its PID (Process ID). The program is designed to run in the terminal.

Prerequisites:
- C++ compiler (e.g. g++)
- ncurses (e.g. RedHat/Fedora: sudo dnf install ncurses-devel)

Compile:
g++ -o ramwatch main.cpp -lncurses
