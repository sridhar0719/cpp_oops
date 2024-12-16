#include <ncurses.h>

int main() {
    int ch;
    int x = 10, y = 10;

    // Initialize ncurses
    initscr();
    raw();               // Disable line buffering
    keypad(stdscr, TRUE); // Enable keypad input
    noecho();            // Don't display input
    curs_set(0);         // Hide the cursor

    // Game loop
    while (1) {
        clear();  // Clear the screen
        mvprintw(y, x, "O");  // Print "O" at (x, y)
        refresh();  // Refresh the screen to update the display

        ch = getch();  // Get user input
        if (ch == KEY_UP) {
            y--;
        } else if (ch == KEY_DOWN) {
            y++;
        } else if (ch == KEY_LEFT) {
            x--;
        } else if (ch == KEY_RIGHT) {
            x++;
        } else if (ch == 'q') {  // Quit on 'q' key press
            break;
        }
    }

    // Cleanup and exit
    endwin();
    return 0;
}

