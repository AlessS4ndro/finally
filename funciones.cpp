#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include"types.h"
#include"clases.h"
using namespace std;

void GoPos(int x,int y)
{

  HANDLE Hcon;
  Hcon=GetStdHandle(STD_OUTPUT_HANDLE);
  COORD Pos;
  Pos.X=x;
  Pos.Y=y;

  SetConsoleCursorPosition(Hcon,Pos);

}

void OcultarCursor()
{
  HANDLE Hcon;
  Hcon=GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cci;
  cci.dwSize=100;
  cci.bVisible=FALSE;

  SetConsoleCursorInfo(Hcon,&cci);
}

/////     EN UNA VENTANA DE 150 DE ANCHO Y 40 DE ALTO
void Interfaz()
{
  system("cls");
  //////       DIBUJAMOS LOS MARGENES HORIZONTALES DESDE EL PUNTO
  ////////  3 HASTA EL PUNTO 147 EN X
  for (int i=3;i<=147;i++){
    GoPos(i,3);printf("%c",205);
    GoPos(i,37);printf("%c",205);
  }
  /////      DIBUJAMOS LOS MARGENES VERTICALES DESDE EL PUNTO
  ////    4 HASTA EL PUNTO 36 EN EL EJE Y
  for (int i=4;i<=36;i++){
    GoPos(3,i);printf("%c",186);
    GoPos(147,i);printf("%c",186);
  }
  /////DIBUJAMOS LAS ESQUINAS
  GoPos(3,3);printf("%c",201);GoPos(147,3);printf("%c",187);
  GoPos(3,37);printf("%c",200);GoPos(147,37);printf("%c",188);
}

ostream &operator<<(ostream &o,const NaveGenerica &p)
{
  GoPos(p.x,p.y); printf("  %c",94);
  GoPos(p.x,p.y+1);printf(" %c%c%c",40,207,41);
  GoPos(p.x,p.y+2);printf("%c%c %c%c",60,190,190,62);
  return o;
}
