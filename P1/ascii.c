#include <stdio.h>
#include <dos.h>

#define BYTE unsigned char

void gotoxy(int x, int y){
	union REGS inregs, outregs;
	inregs.h.ah = 0x02;
	inregs.h.bh = 0x00;
	inregs.h.dh = y;
	inregs.h.dl = x;
	int86(0x10,&inregs,&outregs);
	return;
}

void clrscr(){
   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    
    gotoxy(0,0);
}
void mi_pausa(){
   union REGS inregs, outregs;
	 inregs.h.ah = 8;
	 int86(0x21, &inregs, &outregs);
}

int main(){
    clrscr();
    gotoxy(20,10);
    printf("(\\(\\");
    gotoxy(20,11);
    printf("(-.-)");
    gotoxy(20,12);
    printf("o_(')(')");
    gotoxy(0,25);
    printf(" pulsa una tecla para salir");
    mi_pausa();
    clrscr();
    return 0;
}