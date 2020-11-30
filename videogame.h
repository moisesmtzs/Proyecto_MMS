#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"

class Videogame{

    private:
        string nombre;
        vector<Civilizacion> civilizaciones;

    public:
        Videogame(){}
        Videogame( const string &nombre ):nombre(nombre){}
        void setNombreU( const string &nombre );
        string getNombreU();
        size_t Total();
        bool vacio() const;
        void mostrar();
        void push_back( const Civilizacion &c );
        void insert( const Civilizacion &c, size_t p );
        void crear( const Civilizacion &c, size_t n );
        void front()const;
        void back()const;
        void ordenarNombre();
        void ordenarX();
        void ordenarY();
        void ordenarPunt();
        void erase( const string &nombre );
        Civilizacion* modificar( Civilizacion &c );
        Civilizacion* buscar( const Civilizacion &c );

        friend Videogame& operator<<( Videogame &v, const Civilizacion &c ){
            v.push_back(c);
            return v;
        }

};

#endif