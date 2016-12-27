#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

#include"clases.h"
#include"windows.h"
#include"conio.h"
#include"prototipos.h"

void NaveGenerica::pintar()
{
  GoPos(x,y);  printf("  %c",94);
  GoPos(x,y+1);printf(" %c%c%c",40,207,41);
  GoPos(x,y+2);printf("%c%c %c%c",60,190,190,62);
}

void NaveGenerica::mover(direccionales tecla)
{
      borrar();
      if(tecla==ARRIBA && y>4) y--;
      if(tecla==ABAJO && y<34) y++;
      if(tecla==IZQUIERDA && x>4) x--;
      if(tecla==DERECHA && x<141) x++;
      pintar();

}
void NaveGenerica::borrar()
{
  GoPos(x,y);  printf("      ");
  GoPos(x,y+1);printf("      ");
  GoPos(x,y+2);printf("      ");
}
void NaveGenerica::disparo(NavePro &N)
{
  for(it=B.begin();it!=B.end();it++){
    (*it)->mover();
    if((*it)->colision(N) || (*it)->fuera()){
      (*it)->~Bala();
      it=B.erase(it);
      GoPos(5,38);cout<<"borrando";
    }
  }
}
void NaveGenerica::morir(direccionales d_bala)
{
  c--;
  if(c==0){
    v--;
    borrar();
    GoPos(x,y);	 printf("  **  ");
    GoPos(x,y+1);printf(" ****  ");
    GoPos(x,y+2);printf("  **  ");
    Sleep(250);

    borrar();
    GoPos(x,y);	 printf("* ** *");
    GoPos(x,y+1);printf(" **** ");
    GoPos(x,y+2);printf("* ** *");
    Sleep(250);

    GoPos(x,y);	 printf("      ");
    GoPos(x,y+1);printf("      ");
    GoPos(x,y+2);printf("      ");

    pintar();
    c=3;
    pintar_corazones();
  }
}
void NaveGenerica::pintar_corazones()
{
  GoPos(75,2);printf("VIDAS  %d",v);
  GoPos(87,2);printf("Salud: ");
  GoPos(95,2);printf("       ");
  for(int i=0;i<c;i++){
    GoPos(95+i,2);printf("%c",157);
  }
}

void NavePro::pintar()
{
  if(kbhit()){
      d=getch();
  }
  if(d!=ARRIBA&&d!=ABAJO&&d!=IZQUIERDA&&d!=DERECHA&&d!='a'&&d!='s'){
    d=aux;
  }
      switch(d){
        arr: case ARRIBA:
                if(y>34)y=y-2;
                if(x<6)x=x+4;
                if(x>143)x=x-4;
                GoPos(x-2,y);  printf("  %c",94);
                GoPos(x-2,y+1);printf(" %c%c%c",179,207,179);
                GoPos(x-2,y+2);printf("%c%c %c%c",188,207,207,200);
                aux=d;break;
        aba: case ABAJO:
                if(y<6)y=y+2;
                if(x<6)x=x+4;
                if(x>143)x=x-4;
                GoPos(x-2,y-2);  printf("%c%c %c%c",187,207,207,201);
                GoPos(x-2,y-1);printf(" %c%c%c",179,207,179);
                GoPos(x-2,y);printf("  %c ",190);
                aux=d;break;
        dere: case DERECHA:
                if(x<6)x=x+2;
                if(y<6)y=y+3;
                if(y>34)y=y-3;
                GoPos(x-3,y-2);printf("%c",200);
                GoPos(x-3,y-1); printf(" %c%c",207,196);
                GoPos(x-3,y);   printf("  %c%c",207,62);
                GoPos(x-3,y+1); printf(" %c%c",207,196);
                GoPos(x-3,y+2); printf("%c",201);
                aux=d;break;
        izq: case IZQUIERDA:
                if(x>144)x=x-2;
                if(y<6)y=y+3;
                if(y>34)y=y-3;
                GoPos(x,y-2);printf("  %c",188);
                GoPos(x,y-1);printf(" %c%c",196,207);
                GoPos(x,y);printf("%c%c",60,207);
                GoPos(x,y+1);printf(" %c%c",196,207);
                GoPos(x,y+2);printf("  %c",187);
                aux=d;break;
        case 'a':a=aux;d=a;
                if(a==ARRIBA)goto arr;
                if(a==ABAJO)goto aba;
                if(a==DERECHA)goto dere;
                if(a==IZQUIERDA)goto izq;

        case 's':d=aux;
                if(d!=a)
                  B.push_back(new Bala(x,y,d));
                if(d==ARRIBA)goto arr;
                if(d==ABAJO)goto aba;
                if(d==DERECHA)goto dere;
                if(d==IZQUIERDA)goto izq;
      }
      pintar_corazones();
}
void NavePro::mover()
{
      borrar();
      if(a==ARRIBA ){y--;if( y<6)y=33;}
      if(a==ABAJO ) {y++;if(y>34)y=4;}
      if(a==IZQUIERDA ){ x--;if(x<7)x=143;}
      if(a==DERECHA ){ x++;if(x>143)x=7;}
}
void NavePro::borrar()
{
  switch(d){
    case ARRIBA:GoPos(x-2,y);  printf("      ");
                GoPos(x-2,y+1);printf("      ");
                GoPos(x-2,y+2);printf("      ");
                break;
    case ABAJO:GoPos(x-2,y-2);printf("      ");
              GoPos(x-2,y-1); printf("      ");
              GoPos(x-2,y);   printf("      ");
              break;
    case DERECHA:GoPos(x-3,y-2);printf("   ");
                  GoPos(x-3,y-1);printf("   ");
                  GoPos(x-3,y);printf("    ");
                  GoPos(x-3,y+1);printf("   ");
                  GoPos(x-3,y+2);printf("   ");
                  break;
    case IZQUIERDA:GoPos(x,y-2);   printf("   ");
                  GoPos(x,y-1);printf("   ");
                  GoPos(x,y);printf("    ");
                  GoPos(x,y+1);printf("   ");
                  GoPos(x,y+2);printf("   ");
                  break;
  }
}

void Bala::mover()
{
  switch(direccion){
    case ARRIBA:GoPos(x,y);if(y>6) {cout<<" ";y--;GoPos(x,y);cout<<"*";}break;
    case ABAJO:GoPos(x,y);if(y<34){cout<<" ";y++;GoPos(x,y);cout<<"*";}break;
    case IZQUIERDA:GoPos(x,y);if(x>5){cout<<" ";x--;GoPos(x,y);cout<<"*";}break;
    case DERECHA:GoPos(x,y);if(x<145){cout<<" ";x++;GoPos(x,y);cout<<"*";}break;
  }
}
bool Bala::fuera()
{
  switch(direccion){
    case ARRIBA:if(y==6||y==5)return true;else return false;break;
    case ABAJO:if(y==34||y==35)return true;else return false;break;
    case IZQUIERDA:if(x==5||x==4)return true;else return false;break;
    case DERECHA:if(x==145||x==146)return true;else return false;break;
  }
}
bool Bala::colision(NavePro &N)
{
  list<Bala *> A=N.getList();
  list<Bala *>::iterator et;

  for(et=A.begin();et!=A.end();et++){
    switch(direccion){
      case ARRIBA:if(x==(*et)->X() && (y==(*et)->Y() || y-1==(*et)->Y())){
                    (*et)->~Bala();
                    et=A.erase(et);
                    N.setList(A);
                    return true;
                  }
                  break;
      case DERECHA:if(y==(*et)->Y() && (x==(*et)->X() || x+1==(*et)->X())){
                    (*et)->~Bala();
                    et=A.erase(et);
                    N.setList(A);
                    return true;
                  }
                  break;
      case ABAJO:if(x==(*et)->X() && (y==(*et)->Y() || y+1==(*et)->Y())){
                    (*et)->~Bala();
                    et=A.erase(et);
                    N.setList(A);
                    return true;
                  }
                  break;
      case IZQUIERDA:if(y==(*et)->Y() && (x==(*et)->X() || x-1==(*et)->X())){
                        (*et)->~Bala();
                        et=A.erase(et);
                        N.setList(A);
                        return true;
                      }
                      break;
    }
  }
  switch(N.D()){
    case ARRIBA:if(x==N.X()-2 && (y==N.Y()+3 || y==N.Y()+2)){N.morir(direccion);return true;}
                if(x==N.X()-1 && (y==N.Y()+2 || y==N.Y()+1)){N.morir(direccion);return true;}
                if(x==N.X() && (y==N.Y() || y==N.Y()+1)){N.morir(direccion);return true;}
                if(x==N.X()+1 && (y==N.Y()+2 || y==N.Y()+1)){N.morir(direccion);return true;}
                if(x==N.X()+2 && (y==N.Y()+3 || y==N.Y()+2)){N.morir(direccion);return true;}
                return false;
    case ABAJO:if(x==N.X()-2  && (y==N.Y()-3 || y==N.Y()-2)){N.morir(direccion);return true;}
                if(x==N.X()-1  && (y==N.Y()-2 || y==N.Y()-1)){N.morir(direccion);return true;}
                if(x==N.X()  && (y==N.Y() || y==N.Y()-1)){N.morir(direccion);return true;}
                if(x==N.X()+1  && (y==N.Y()-2 || y==N.Y()-1)){N.morir(direccion);return true;}
                if(x==N.X()+2  && (y==N.Y()-3 || y==N.Y()-2)){N.morir(direccion);return true;}
                return false;
    case DERECHA:if(y==N.Y()-2 && (x==N.X()-3 || x==N.X()-2)){N.morir(direccion);return true;}
                if(y==N.Y()-1 && (x==N.X()-2 || x==N.X()-1)){N.morir(direccion);return true;}
                if(y==N.Y() && (x==N.X() || x==N.X()-1)){N.morir(direccion);return true;}
                if(y==N.Y()+1 && (x==N.X()-2 || x==N.X()-1)){N.morir(direccion);return true;}
                if(y==N.Y()+2 && (x==N.X()-3 || x==N.X()-2)){N.morir(direccion);return true;}
                return false;
    case IZQUIERDA:if(y==N.Y()-2 && (x==N.X()+3 || x==N.X()+2)){N.morir(direccion);return true;}
                if(y==N.Y()-1 && (x==N.X()+2 || x==N.X()+1)){N.morir(direccion);return true;}
                if(y==N.Y() && (x==N.X() || x==N.X()+1)){N.morir(direccion);return true;}
                if(y==N.Y()+1 && (x==N.X()+2 || x==N.X()+1)){N.morir(direccion);return true;}
                if(y==N.Y()+2 && (x==N.X()+3 || x==N.X()+2)){N.morir(direccion);return true;}
                return false;
  }


}
void NaveAI::pintar(direccionales dir)
{
  d=dir;
  switch(d){
    arr: case ARRIBA:
            if(y>34)y=y-2;
            if(x<6)x=x+4;
            if(x>143)x=x-4;
            GoPos(x-2,y);  printf("  %c",94);
            GoPos(x-2,y+1);printf(" %c%c%c",179,207,179);
            GoPos(x-2,y+2);printf("%c%c %c%c",188,207,207,200);
            aux=d;break;
    aba: case ABAJO:
            if(y<6)y=y+2;
            if(x<6)x=x+4;
            if(x>143)x=x-4;
            GoPos(x-2,y-2);  printf("%c%c %c%c",187,207,207,201);
            GoPos(x-2,y-1);printf(" %c%c%c",179,207,179);
            GoPos(x-2,y);printf("  %c ",190);
            aux=d;break;
    dere: case DERECHA:
            if(x<6)x=x+2;
            if(y<6)y=y+3;
            if(y>34)y=y-3;
            GoPos(x-3,y-2);printf("%c",200);
            GoPos(x-3,y-1); printf(" %c%c",207,196);
            GoPos(x-3,y);   printf("  %c%c",207,62);
            GoPos(x-3,y+1); printf(" %c%c",207,196);
            GoPos(x-3,y+2); printf("%c",201);
            aux=d;break;
    izq: case IZQUIERDA:
            if(x>144)x=x-2;
            if(y<6)y=y+3;
            if(y>34)y=y-3;
            GoPos(x,y-2);printf("  %c",188);
            GoPos(x,y-1);printf(" %c%c",196,207);
            GoPos(x,y);printf("%c%c",60,207);
            GoPos(x,y+1);printf(" %c%c",196,207);
            GoPos(x,y+2);printf("  %c",187);
            aux=d;break;
    case 'a':a=aux;d=a;
            if(a==ARRIBA)goto arr;
            if(a==ABAJO)goto aba;
            if(a==DERECHA)goto dere;
            if(a==IZQUIERDA)goto izq;

    case 's':d=aux;
            if(d!=a)
              B .push_back(new Bala(x,y,d));
            if(d==ARRIBA)goto arr;
            if(d==ABAJO)goto aba;
            if(d==DERECHA)goto dere;
            if(d==IZQUIERDA)goto izq;
  }
  pintar_corazones();
}
char NaveAI::automatizacion(NavePro N)
{
  int num=rand()%100;
  int dif_x=(N.X()-x);
  int dif_y=(N.Y()-y);
  int menor;if(abs(dif_x)<abs(dif_y))menor=dif_x; else menor=dif_y;

  if(num>=20 && num<40)return 'a';
  if(num>=0 && num<20)return 's';
  if(x<8 && y<9)return DERECHA;
  if(x>142&&y<9)return ABAJO;
  if(x<8 && y>31)return ARRIBA;
  if(x>142&&y>31)return IZQUIERDA;

  if(menor==dif_x){
    if(dif_x>0 && dif_y>0)return ABAJO;
    else
      if(dif_x<0 && dif_y<0)return ARRIBA;
      else
        if(dif_x<0 && dif_y>0)return ABAJO;
        else
          return ARRIBA;
  }
  else{
    if(dif_x>0 && dif_y>0)return DERECHA;
    else
      if(dif_x<0 && dif_y<0)return IZQUIERDA;
      else
        if(dif_x<0 && dif_y>0)return IZQUIERDA;
        else
          return DERECHA;
  }
}

void NaveAI::pintar_corazones()
{
  GoPos(10,2);printf("VIDAS  %d",v);
  GoPos(25,2);printf("Salud: ");
  GoPos(33,2);printf("       ");
  for(int i=0;i<c;i++){
    GoPos(33+i,2);printf("%c",157);
  }
}
