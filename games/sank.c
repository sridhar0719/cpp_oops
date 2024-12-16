#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#define WIDTH  50
#define HEIGHT 25

// Snake structure
typedef struct {
    int x, y;
} Point;

Point snake[100];  // Snake body
int snake_length = 3;  // Snake starts with length 3
int food_x, food_y;  // Food coordinates
int direction = 1;  // Initial movement direction (1=RIGHT, 2=LEFT, 3=UP, 4=DOWN)

void init_game();
void draw_game();
void move_snake();
void generate_food();
int collision();
void game_over();

int main() {
    srand(time(0));  // Seed random number generator

    // Initialize ncurses
    initscr();
    curs_set(0);  // Hide cursor
    timeout(100);  // 100 ms timeout for user input
    keypad(stdscr, TRUE);  // Enable keypad mode
    noecho();  // Don't echo user input

    init_game();  // Set up initial game state

    while (1) {
        int ch = getch();  // Get user input

        if (ch == KEY_UP && direction != 4) direction = 3;
        else if (ch == KEY_DOWN && direction != 3) direction = 4;
        else if (ch == KEY_LEFT && direction != 1) direction = 2;
        else if (ch == KEY_RIGHT && direction != 2) direction = 1;
        else if (ch == 'q') break;  // Quit the game on 'q'

        move_snake();
        if (collision()) {
            game_over();
            break;
        }
        draw_game();
    }

    endwin();  // End ncurses mode
    return 0;
}

void init_game() {
    // Initial position of the snake
    snake[0].x = WIDTH / 4;
    snake[0].y = HEIGHT / 2;
    snake[1].x = snake[0].x - 1;
    snake[1].y = snake[0].y;
    snake[2].x = snake[0].x - 2;
    snake[2].y = snake[0].y;

    generate_food();
}

void draw_game() {
    clear();  // Clear screen
    // Draw walls
    for (int i = 0; i < WIDTH; i++) {
        mvaddch(0, i, '#');
        mvaddch(HEIGHT - 1, i, '#');
    }
    for (int i = 0; i < HEIGHT; i++) {
        mvaddch(i, 0, '#');
        mvaddch(i, WIDTH - 1, '#');
    }

    // Draw snake
    for (int i = 0; i < snake_length; i++) {
        mvaddch(snake[i].y, snake[i].x, 's');
    }

    // Draw food
    mvaddch(food_y, food_x, '*');

    // Refresh the screen to show changes
    refresh();
}

void move_snake() {
    Point new_head = snake[0];

    // Move the snake's head based on the current direction
    if (direction == 1) new_head.x++;
    if (direction == 2) new_head.x--;
    if (direction == 3) new_head.y--;
    if (direction == 4) new_head.y++;

    // Shift the body of the snake
    for (int i = snake_length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    // Add the new head to the snake
    snake[0] = new_head;

    // Check if the snake has eaten the food
    if (snake[0].x == food_x && snake[0].y == food_y) {
        snake_length++;  // Increase the length of the snake
        generate_food();  // Generate new food
    }
}

void generate_food() {
    food_x = rand() % (WIDTH - 2) + 1;
    food_y = rand() % (HEIGHT - 2) + 1;
}

int collision() {
    // Check if the snake hits the walls
    if (snake[0].x == 0 || snake[0].x == WIDTH - 1 || snake[0].y == 0 || snake[0].y == HEIGHT - 1)
        return 1;

    // Check if the snake collides with itself
    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return 1;
    }

    return 0;  // No collision
}

void game_over() {
    clear();
    mvprintw(HEIGHT / 2, WIDTH / 2 - 5, "GAME OVER");
    mvprintw(HEIGHT / 2 + 1, WIDTH / 2 - 8, "Press any key to exit...");
    refresh();
    getch();  // Wait for user input
}

