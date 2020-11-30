#include "aldeano.h"

void Aldeano::setNombre( const string &n ){
    nombre = n;
}
string Aldeano::getNombre()const{
    return nombre;
}
void Aldeano::setEdad( int n ){
    edad = n;
}
int Aldeano::getEdad()const{
    return edad;
}
void Aldeano::setGenero( const string &n ){
    genero = n;
}
string Aldeano::getGenero()const{
    return genero;
}

void Aldeano::setSalud( int n ){
    salud = n;
}
int Aldeano::getSalud()const{
    return salud;
}
