#include <stdio.h>
#include <dos.h>

#define BYTE unsigned char
BYTE cfondo=0;
BYTE ctexto=1;

void gotoxy(int x, int y){
	union REGS inregs, outregs;
	inregs.h.ah = 0x02;
	inregs.h.bh = 0x00;
	inregs.h.dh = y;
	inregs.h.dl = x;
	int86(0x10,&inregs,&outregs);
	return;
}

void setcursortype(int tipo_cursor){
	union REGS inregs, outregs;
	inregs.h.ah = 0x01;
	switch(tipo_cursor){
		case 0: //invisible
			inregs.h.ch = 010;
			inregs.h.cl = 000;
			break;
		case 1: //normal
			inregs.h.ch = 010;
			inregs.h.cl = 011;
			break;
		case 2: //grueso
			inregs.h.ch = 000;
			inregs.h.cl = 010;
			break;
	}
	int86(0x10, &inregs, &outregs);
}

void setvideomode(BYTE modo){
   union REGS inregs, outregs;
   inregs.h.al = modo;
   inregs.h.ah = 0x00;
   int86(0x10, &inregs, &outregs);
}

BYTE getvideomode(){
	union REGS inregs, outregs;
	inregs.h.al = 0x00;
   inregs.h.ah = 0x0F;
   int86(0x10, &inregs, &outregs);
   return outregs.h.al;
}

void cputchar(char c){
	union REGS inregs, outregs;
	inregs.h.ah = 0x09;
	inregs.h.al = c;
	inregs.h.bl = cfondo << 4 | ctexto;
	inregs.h.bh = 0x00;
	inregs.x.cx = 1;
	int86(0x10,&inregs,&outregs);
	return;
}

void textcolor(BYTE c) {
    ctexto = c;
}

void textbackground(BYTE c) {
    cfondo = c;
}

void clrscr(){
   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    
    gotoxy(0,0);
}

char getche(){
	 union REGS inregs, outregs;
	 int caracter;

	 inregs.h.ah = 1;
	 int86(0x21, &inregs, &outregs);

	 caracter = outregs.h.al;
	 return caracter;
}

void mi_pausa(){
   union REGS inregs, outregs;
	 inregs.h.ah = 8;
	 int86(0x21, &inregs, &outregs);
}

void mi_putchar(char c){
	 union REGS inregs, outregs;

	 inregs.h.ah = 2;
	 inregs.h.dl = c;
	 int86(0x21, &inregs, &outregs);
}


int main(){
	//printf("\nEl modo de texto actual es: %c", getvideomode()); 
	char c;
	
    printf("pulsa para que el cursor cambie de posicion");
    mi_pausa();
    clrscr();
    gotoxy(20,15);
    mi_putchar('x');

	printf("\nahora vamos a cambiar el cursor");
	mi_pausa();
	setcursortype(0);
	printf("\nCursor invisible");
	mi_pausa();

	setcursortype(2);
	printf("\nCursor grueso");
	mi_pausa();

	setcursortype(1);
	printf("\nCursor normal");
    mi_pausa();

	printf("\nAhora vamos a cambiar el modo de video");
	mi_pausa();
	setvideomode(0);
	printf("\n Modo de video cambiado, pulsa para volver a la normalidad");
	mi_pausa();
	setvideomode(2);

	//printf("\nEl modo de texto actual es: %c", getvideomode()); 
	textcolor(2);
	printf("\nColor de texto cambiado a verde");
	textbackground(1);
	printf("\nColor de fondo cambiado a azul");

	printf("\nImpriendo un caracter con los colores seleccionados: ");
	cputchar('f');
	printf("\nPulsa para limpiar la ventana");
	mi_pausa();
	clrscr();
	printf("Pantalla limpiada correctamente");

	printf("\nEscribe un caracter: ");
	c = getche();
	printf("\nEl caracter escrito ha sido: %c", c);
    return 0;
}


