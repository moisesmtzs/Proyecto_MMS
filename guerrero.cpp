#include "guerrero.h"

void Guerrero::setId( int s ){
    id = s;
}

int Guerrero::getId()const{
    return id;
}

void Guerrero::setSalud( int s ){
    salud = s;
}

int Guerrero::getSalud()const{
    return salud;
}

void Guerrero::setFuerza( float s ){
    fuerza = s;
}

float Guerrero::getFuerza() const{
    return fuerza;
}

void Guerrero::setEscudo( float s ){
    escudo = s;
}

float Guerrero::getEscudo() const{
    return escudo;
}

void Guerrero::setTipo( const string &s ){
    tipo = s;
}

string Guerrero::getTipo()const {
    return tipo;
}

