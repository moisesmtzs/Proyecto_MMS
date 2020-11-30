#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include "aldeano.h"

using namespace std;

class Civilizacion{
    
    list<Aldeano> aldeanos;
    string nombre;
    float x,y;
    float puntuacion;
    public:
        Civilizacion(){}
        Civilizacion( const string &nombre, float x, float y, float puntuacion ):nombre{nombre},x(x),y(y),puntuacion(puntuacion){}
        void respaldarA( const Civilizacion &c );
        void recuperarA( const Civilizacion &c );
        void setNombre( const string &n );
        string getNombre();
        void setX( float n );
        float getX();
        void setY( float n );
        float getY();
        void setPuntuacion( float n );
        float getPuntuacion();
        void agregarInicio( const Aldeano &a );
        void agregarFinal( const Aldeano &a );
        void eliminarNombre( const string &s );
        void eliminarSalud( int s );
        void eliminarEdad();
        void clasificarNombre();
        void clasificarEdad();
        void clasificarSalud();
        Aldeano* buscar( const Aldeano &a );
        void mostrar();

        friend ostream& operator<<( ostream &o, const Civilizacion &c ){

            o << left;
            o << setw(16) << c.nombre;
            o << setw(12) << c.x;
            o << setw(12) << c.y;
            o << setw(16) << c.puntuacion;
            o << endl;
            return o;

        }
        friend istream& operator>>( istream &i, Civilizacion &c ){

            cout << "Nombre: ";
            getline(cin,c.nombre);
            cout << "X: ";
            cin >> c.x;
            cout << "Y: ";
            cin >> c.y;
            cout << "Puntuación: ";
            cin >> c.puntuacion;
            cin.ignore();
            return i;

        } 

        bool operator==( const Civilizacion &c ){
            return nombre == c.nombre;
        }
        bool operator==( const Civilizacion &c ) const {
            return nombre == c.nombre;
        }
        bool operator<( const Civilizacion &c ){
            return nombre < c.nombre;
        }
        bool operator<( const Civilizacion &c ) const {
            return nombre < c.nombre;
        }

};

#endif