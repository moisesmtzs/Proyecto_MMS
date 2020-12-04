#ifndef BARCO_H
#define BARCO_H

#include "guerrero.h"

class Barco{
    private:
        string id;
        double combustible;
        float velocidad;
        float armadura;
        int cont_guerr;
        stack<Guerrero> guerreros;

    public:
        Barco(){
            cont_guerr = 0;
        }
        void setId( const string &i );
        string getId()const;
        void setCombustible( double c );
        double getCombustible() const;        
        void setVelocidad( float v );
        float getVelocidad()const;        
        void setArmadura( float a );
        float getArmadura()const;      
        void setGuerreros(int v);
        int getGuerreros()const;  

        void agregarGuerrero( Guerrero &g );
        void eliminarGuerrero();
        void tope();
        void mostrarG();

        friend ostream& operator<<( ostream &o, Barco *b ){
            
            o << left;
            o << setw(8) << b->getId(); 
            o << setw(12) << b->getCombustible(); 
            o << setw(12) << b->getVelocidad(); 
            o << setw(12) << b->getArmadura();
            o << setw(12) << b->getGuerreros();
            o << endl;
            return o; 

        }
        friend istream& operator>>( istream &i, Barco *b ){

            string temp;
            double c;
            cout << "ID: "; getline(cin, temp);
            b->setId(temp);

            cout << "Combustible: "; 
            bool band = false;
            while ( band != true ){

                cin >> c; cin.ignore(); cout << endl; 
                if ( c > 100 || c < 0.0 ){
                    cout << "Valores fuera del rango permitido" << endl;
                } else {
                    b->setCombustible(c);
                    band = true;
                }

            }

            b->setVelocidad(0.0);
            b->setArmadura(100.0);
            return i;

        }

};

#endif