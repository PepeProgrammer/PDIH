#include <ncurses.h>
#include <unistd.h>

#define DELAY 100000//50000
void test( WINDOW *window,char * mensaje) {
    mvwprintw(window,7,5, mensaje);
    wrefresh(window);
}

int main() {
    bool finalizar = false;
    int fils, cols;
    int x = 5, y = 0;
    int max_y = 23, max_x = 79;
    int next_x = 0;
    int direction_x = 1;
    int next_y = 0;
    int direction_y = 1;
    
    int xc = 0, yc = 12;
    int xc2 = 79, yc2 = 12;
    int ch = 0;
    int punt = 0, punt2 = 0; //puntuación de cada jugador
    bool reset = false;

    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);
    clear();
    refresh();
    nodelay(stdscr, FALSE); // Así getch hace pausa

    getmaxyx(stdscr,fils,cols);
    WINDOW *window = newwin(fils, cols, 0, 0);
    box(window, '|', '-');
    mvwprintw(window,5,5, "Pong: El videojuego");
    mvwprintw(window,6,5, "'a' y 's' jugador 1");
    mvwprintw(window,7,5, "'o' y 'p' jugador 2");
    mvwprintw(window,8,5, "'y' para finalizar el juego");
    mvwprintw(window,9,5, "Gana el primer juador en llegar a 3 puntos");
    mvwprintw(window,10,5, "Pulsa una tecla para empezar");
    wrefresh(window);
    getch();

    nodelay(stdscr, TRUE); // Así getch NO hace pausa

    while(!finalizar) {
        reset = false;
        clear();
        mvprintw(y,x,"o");
        mvprintw(yc-1,xc,"|");
        mvprintw(yc,xc,"|");
        mvprintw(yc+1,xc,"|");

        mvprintw(yc2-1,xc2,"|");
        mvprintw(yc2,xc2,"|");
        mvprintw(yc2+1,xc2,"|");

        refresh();
        usleep(DELAY);

        ch = getch();

        if(ch == 'a' && yc > 1){
            yc -= 1;
        } else  if(ch == 's' && yc < 22){
            yc += 1;
        } else if(ch == 'o' && yc2 > 1){
            yc2 -= 1;
        } else  if(ch == 'p' && yc2 < 22){
            yc2 += 1;
        }else  if(ch == 'y'){
           finalizar = true;
        }

        next_x = x + direction_x;
        next_y = y + direction_y;

        if((next_x == 0 && (next_y == yc || next_y == yc-1 || next_y == yc+1)) || (next_x == max_x && (next_y == yc2 || next_y == yc2-1 || next_y == yc2+1))){ //next_x > max_x || next_x < 0
            direction_x *= -1;
        } else if(next_x == 0 || next_x == max_x){
            if(next_x == 0){
                punt2++;
                direction_x = 1;
            } else {
                punt++;
                direction_x = -1;
            }
            x = 40; y = 11;
            xc = 0; yc = 12;
            xc2 = 79; yc2 = 12;
            reset = true;
        } else {
            x += direction_x;
        }

        if(!reset){
            if(next_y > max_y || next_y < 0){
                direction_y *= -1;
            } else {
            y += direction_y;
            }
        }

        if(punt > 2 || punt2 > 2){
            finalizar = true;
        }
        
    }

    clear();
    refresh();

    nodelay(stdscr, FALSE); // Así getch hace pausa

    werase(window);
    box(window, '*', '*');
    mvwprintw(window,5,5, "FINAL DE LA PARTIDA");
    if(punt > punt2){
        mvwprintw(window,6,5, "GANA JUGADOR 1");
    } else {
        mvwprintw(window,6,5, "GANA JUGADOR 2");
    }
    mvwprintw(window,7,5, "Juego realizado por Jordi Pereira Gil, ¡gracias por jugar!");
    mvwprintw(window,8,5, "Pulsa una tecla para finalizar");
    wrefresh(window);
    getch();

    endwin();
    return 0;
}