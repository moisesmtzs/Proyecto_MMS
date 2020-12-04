#include "barco.h"

void Barco::setId( const string &i ){

    id = i;

}
string Barco::getId()const{

    return id;

}
void Barco::setCombustible( double c ){

    combustible = c;

}
double Barco::getCombustible() const {

    return combustible;

}
void Barco::setVelocidad( float v ){

    velocidad = v;

}
float Barco::getVelocidad()const {

    return velocidad;

}
void Barco::setArmadura( float a ){

    armadura = a;

}
float Barco::getArmadura()const {

    return armadura;

}

void Barco::setGuerreros( int v ){
    cont_guerr = v;
}

int Barco::getGuerreros()const{
    return cont_guerr;
}


void Barco::agregarGuerrero( Guerrero &g ){

    if ( g.getSalud() > 100  || g.getSalud() < 0 || g.getEscudo() > 30 || g.getEscudo() < 0 || g.getFuerza() > 60 || g.getFuerza() < 0 ){
        cout << "Valores fuera de rango, guerrero no aceptado" << endl << "Intenta de nuevo" << endl << endl;
    } else {
        guerreros.push(g);
        cont_guerr++;
    }

}
void Barco::eliminarGuerrero(){

    guerreros.pop();
    cont_guerr--;

}
void Barco::tope(){

    cout << endl << left;
    cout << setw(8) << "Id";
    cout << setw(12) << "Salud";
    cout << setw(12) << "Fuerza";
    cout << setw(12) << "Escudo";
    cout << setw(12) << "Tipo";
    cout << endl << endl;
    cout << guerreros.top();
    cout << endl;

}
void Barco::mostrarG(){

    cout << endl << left;
    cout << setw(8) << "Id";
    cout << setw(12) << "Salud";
    cout << setw(12) << "Fuerza";
    cout << setw(12) << "Escudo";
    cout << setw(12) << "Tipo";
    cout << endl << endl;
    
    stack<Guerrero> copia(guerreros);
    while ( !copia.empty() ){

        Guerrero g = copia.top();
        cout << g;
        copia.pop();

    }
    cout << endl;

}