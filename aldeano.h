#ifndef ALDEANO_H
#define ALDEANO_H

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>

using namespace std;

class Aldeano{

    string nombre;
    int edad, salud;
    string genero;
    public:
        Aldeano(){}
        Aldeano( const string &nombre, int edad, const string &genero, int salud ):nombre(nombre),edad(edad),genero(genero),salud(salud){}
        void setNombre( const string &n );
        string getNombre()const;
        void setEdad( int n );
        int getEdad()const;
        void setGenero( const string &g );
        string getGenero()const;
        void setSalud( int n );
        int getSalud()const;

        friend ostream& operator<<( ostream &o, const Aldeano &a ){

            o << left;
            o << setw(16) << a.nombre;
            o << setw(12) << a.edad;
            o << setw(12) << a.genero;
            o << setw(16) << a.salud;
            o << endl;
            return o;

        }
        friend istream& operator>>( istream &i, Aldeano &a ){

            cout << "Nombre: ";
            getline(cin, a.nombre);
            cout << "Edad: ";
            cin >> a.edad; cin.ignore();
            cout << "Género: ";
            getline(cin,a.genero);
            cout << "Salud: ";
            cin >> a.salud; cin.ignore();

            return i;

        }

        bool operator==( const Aldeano &a ) const {
            return nombre == a.nombre;
        }

};

#endif