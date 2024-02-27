#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <ncurses.h>

void visualize_memory(pid_t pid);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <pid>" << std::endl;
        return 1;
    }

    pid_t pid = std::stoi(argv[1]);

    initscr();
    noecho();
    curs_set(0);
    timeout(1000);

    while (true) {
        erase();
        visualize_memory(pid);
        refresh();
        if (getch() == 'q') break;
    }

    endwin();
    return 0;
}

void visualize_memory(pid_t pid) {
    std::ostringstream filename;
    filename << "/proc/" << pid << "/maps";

    std::ifstream maps_file(filename.str());
    std::string line;

    int row = 0;
    while (std::getline(maps_file, line)) {
        if (row >= LINES) break;
        mvprintw(row, 0, line.c_str());
        row++;
    }
}

