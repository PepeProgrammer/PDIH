#include <ncurses.h>
#include <unistd.h>

#define DELAY 100000//50000
void test( WINDOW *window,char * mensaje) {
    mvwprintw(window,7,5, mensaje);
    wrefresh(window);
}

int main() {
    bool finalizar = false;
    int x = 40, y = 11;
    int filas, columnas;
    int y_max = 23, x_max = 79;
    int x_sig = 0, y_sig = 0;
    int direccion_x = 1, direccion_y = 1;

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
    nodelay(stdscr, FALSE); // Así getch pausa la ejecución del juego

    getmaxyx(stdscr,filas,columnas);
    WINDOW *window = newwin(filas, columnas, 0, 0);
    box(window, '+', '+');
    mvwprintw(window,5,5, "Pong: El videojuego");
    mvwprintw(window,6,5, "Juego realizado por Jordi Pereira Gil, gracias por jugar!");
    mvwprintw(window,7,5, "'a' y 's' jugador 1");
    mvwprintw(window,8,5, "'o' y 'p' jugador 2");
    mvwprintw(window,9,5, "'y' para finalizar el juego");
    mvwprintw(window,10,5, "Gana el primer juador en llegar a 3 puntos");
    mvwprintw(window,11,5, "Pulsa una tecla para empezar");
    wrefresh(window);
    getch();

    nodelay(stdscr, TRUE); // Así getch no pausa la ejecución del juego

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

        x_sig = x + direccion_x;
        y_sig = y + direccion_y;

        if((x_sig == 0 && (y_sig == yc || y_sig == yc-1 || y_sig == yc+1)) || (x_sig == x_max && (y_sig == yc2 || y_sig == yc2-1 || y_sig == yc2+1))){ //next_x > max_x || next_x < 0
            direccion_x *= -1;
        } else if(x_sig == 0 || x_sig == x_max){
            if(x_sig == 0){
                punt2++;
                direccion_x = 1;
            } else {
                punt++;
                direccion_x = -1;
            }
            x = 40; y = 11;
            xc = 0; yc = 12;
            xc2 = 79; yc2 = 12;
            reset = true;
        } else {
            x += direccion_x;
        }

        if(!reset){
            if(y_sig > y_max || y_sig < 0){
                direccion_y *= -1;
            } else {
            y += direccion_y;
            }
        }

        if(punt > 2 || punt2 > 2){
            finalizar = true;
        }
        
    }

    clear();
    refresh();

    nodelay(stdscr, FALSE);

    werase(window);
    box(window, '|', '-');
    mvwprintw(window,5,5, "FINAL DE LA PARTIDA");
    if(punt > punt2){
        mvwprintw(window,6,5, "GANA JUGADOR 1");
    } else {
        mvwprintw(window,6,5, "GANA JUGADOR 2");
    }
    mvwprintw(window,7,5, "Puntos jugador 1: %d   Puntos jugador 2: %d", punt, punt2);
    mvwprintw(window,8,5, "Pulsa una tecla para finalizar");
    wrefresh(window);
    getch();

    endwin();
    return 0;
}