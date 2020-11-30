#include "civilizacion.h"

void Civilizacion::setNombre( const string &n ){
    nombre = n;    
}
string Civilizacion::getNombre(){
    return nombre;
}

void Civilizacion::setX( float n ){
    x = n;    
}
float Civilizacion::getX(){
    return x;
}

void Civilizacion::setY( float n ){
    y = n;    
}
float Civilizacion::getY(){
    return y;
}

void Civilizacion::setPuntuacion( float n ){
    puntuacion = n;    
}
float Civilizacion::getPuntuacion(){
    return puntuacion;
}