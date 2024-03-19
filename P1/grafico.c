#include <stdio.h>
#include <dos.h>

#define BYTE unsigned char

void setvideomode(BYTE modo){
   union REGS inregs, outregs;
   inregs.h.al = modo;
   inregs.h.ah = 0x00;
   int86(0x10, &inregs, &outregs);
}
// pone un pixel en la coordenada X,Y de color C
void pixel(int x, int y, BYTE C){
   union REGS inregs, outregs;
   inregs.x.cx = x;
   inregs.x.dx = y;
   inregs.h.al = C;
   inregs.h.ah = 0x0C;
   int86(0x10, &inregs, &outregs);
}

void mi_pausa(){
   union REGS inregs, outregs;
	 inregs.h.ah = 8;
	 int86(0x21, &inregs, &outregs);
}

int main(){
    BYTE c = 2;
    int i,j;
    setvideomode(4);

    for (i = 4; i < 40; i++)
    {
        for ( j = 20; j < 50; j++)
        {
           pixel(i, j, c); 
        }      
        
    }

    c = 3;
    for (i = 120; i < 190; i++)
    {
        for ( j = 80; j < 170; j++)
        {
           pixel(i, j, c); 
        }          
    }

    c = 2;
    for (i = 200; i < 260; i++)
    {
        for ( j = 150; j < 190; j++)
        {
           pixel(i, j, c); 
        }          
    }
    
    mi_pausa();
    setvideomode(2);
    return 0;
    
    
}