#include<iostream>
#include<list>
#include"types.h"
#include"prototipos.h"


using namespace std;
class NavePro;

class Bala
{
  posicion_x x;
  posicion_y y;
  direccionales direccion;
public:
  Bala(posicion_x xb,posicion_y yb,direccionales d):x(xb),y(yb),direccion(d){}
  ~Bala(){GoPos(x,y);cout<<" ";}
  posicion_x X(){return x;}
  posicion_y Y(){return y;}
  void mover();
  bool fuera();
  bool colision(NavePro &);

};
class NaveGenerica
{
  friend ostream &operator<< (ostream &o,const NaveGenerica &p);
protected:
  posicion_x x;
  posicion_y y;
  corazones c;
  vidas v;
  list<Bala *> B;
  list<Bala *>::iterator it;
public:
  NaveGenerica(posicion_x X,posicion_y Y):x(X),y(Y){}
  virtual void pintar();
  virtual void mover(direccionales);
  virtual void borrar();
  void disparo(NavePro &);
  posicion_x X(){return x;}
  posicion_y Y(){return y;}
  void modificarX(posicion_x a){x=a;}
  void modificarY(posicion_y b){y=b;}
  void morir(direccionales);
  virtual void pintar_corazones();
  list<Bala *> getList(){return B;}
  void setList(list<Bala *> A){B=A;}
};

class NavePro:public NaveGenerica
{
protected:
  direccionales d,a,aux;
public:
  NavePro(posicion_x X,posicion_y Y,corazones cor,vidas vid,direccionales dir)
  :NaveGenerica(X,Y){
  c=cor;v=vid;d=dir;a=dir;aux=dir;
  }
  direccionales A(){return a;}
  direccionales D(){return d;}
  virtual void pintar();
  void borrar();
  void mover();
};

class NaveAI:public NavePro
{
public:
  NaveAI(posicion_x X,posicion_y Y,corazones cor,vidas vid,direccionales dir)
  :NavePro(X,Y,cor,vid,dir){};
  void pintar(direccionales);
  char automatizacion(NavePro);
  void pintar_corazones();
};
