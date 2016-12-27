#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "types.h"
#include"prototipos.h"
#include"clases.h"

using namespace std;

ostream &operator<< (ostream &o,const NaveGenerica &p);

int main()
{
  NaveGenerica Apache(20,15);
  NavePro Nexus(10,8,3,3,DERECHA);
  NaveAI AI(70,35,3,3,ARRIBA);

  OcultarCursor();
  Interfaz();
  Nexus.pintar();
  AI.pintar(IZQUIERDA);

  bool game_over=false;
  while(!game_over){
    AI.mover();
    AI.pintar(AI.automatizacion(Nexus));
    AI.disparo(Nexus);
    Nexus.mover();
    Nexus.pintar();
    Nexus.disparo(AI);
    Sleep(55);
  }

  return 0;
}
