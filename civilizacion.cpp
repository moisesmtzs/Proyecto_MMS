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

void Civilizacion::agregarInicio( const Aldeano &a ){
    aldeanos.push_front(a);
}

void Civilizacion::agregarFinal( const Aldeano &a ){
    aldeanos.push_back(a);
}

void Civilizacion::eliminarNombre( const string &s ){

    for ( auto i = aldeanos.begin() ; i != aldeanos.end() ; i++ ){

        Aldeano &a = *i;
        if ( s == a.getNombre() ){
            aldeanos.erase(i);
            break;
        }

    }

}

void Civilizacion::eliminarSalud( int s ){

    aldeanos.remove_if( [s]( const Aldeano &a ) { return a.getSalud() < s; } );

}

void Civilizacion::eliminarEdad(){

    aldeanos.remove_if([] ( const Aldeano &a ) { return a.getEdad() >= 60 ;} );

}

void Civilizacion::clasificarNombre(){

    aldeanos.sort([] ( const Aldeano &a, const Aldeano &a2 ) { return a.getNombre() < a2.getNombre() ;} );

}

void Civilizacion::clasificarEdad(){

    aldeanos.sort([] ( const Aldeano &a, const Aldeano &a2 ) { return a.getEdad() > a2.getEdad() ;} );

}

void Civilizacion::clasificarSalud(){

    aldeanos.sort([] ( const Aldeano &a, const Aldeano &a2 ) { return a.getSalud() > a2.getSalud() ;}  );

}

Aldeano* Civilizacion::buscar( const Aldeano &a ){

    auto i = find ( aldeanos.begin(), aldeanos.end(), a );
    if ( i == aldeanos.end() ){
        return nullptr;
    } else {
        return &(*i);
    }

}

void Civilizacion::mostrar(){

    cout << endl;
    cout << left;
    cout << setw(16) << "Nombre";
    cout << setw(12) << "Edad";
    cout << setw(12) << "Genero";
    cout << setw(16) << "Salud";
    cout << endl << endl;
    for ( auto i = aldeanos.begin() ; i != aldeanos.end() ; i++ ){

        Aldeano &a = *i;
        cout << a << endl;

    }

}
