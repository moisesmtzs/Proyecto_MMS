#ifndef GUERRERO_H
#define GUERRERO_H

#include "aldeano.h"

class Guerrero{
    private:
        
        int id, salud;
        float fuerza, escudo;
        string tipo;

    public:
        Guerrero(){}

        void setId( int s );
        int getId()const;
        void setSalud( int s );
        int getSalud()const;
        void setFuerza( float s );
        float getFuerza()const;
        void setEscudo( float s );
        float getEscudo()const;
        void setTipo( const string &s );
        string getTipo()const;

        friend ostream& operator<<( ostream &o, const Guerrero &g ){
            
            o << left;
            o << setw(8) << g.getId();
            o << setw(12) << g.getSalud();
            o << setw(12) << g.getFuerza();
            o << setw(12) << g.getEscudo();
            o << setw(12) << g.getTipo();
            o << endl;
            return o;

        }

        friend istream& operator>>( istream &i, Guerrero &g ){

            int v; 
            float value;
            cout << "ID:" ; cin >> v; cin.ignore();
            g.setId(v);

            cout << "Salud: (0-100) "; cin >> v; cin.ignore();
            g.setSalud(v);

            cout << "Escudo: (0.0 - 30.0) "; cin >> value; cin.ignore();
            g.setEscudo(value);

            cout << "Fuerza: (0.0 - 60.0) "; cin >> value; cin.ignore();
            g.setFuerza(value);

            bool band = false;
            while ( band != true ){

                cout << endl << "\t\t| Tipo de Guerrero |" << endl<< endl;
                cout << "1) Lancero" << endl
                    << "2) Paladin" << endl
                   << "3) Arquero" << endl
                  << "4) Caballero" << endl;
                  cin >> v; cin.ignore();
                  if ( v == 1 ){
                      g.setTipo("Lancero");
                      band = true;
                  }
                  else if ( v == 2 ){
                      g.setTipo("Paladin");
                      band = true;
                  }
                  else if ( v == 3 ){
                      g.setTipo("Arquero");
                      band = true;
                  }
                  else if ( v == 4 ){
                      g.setTipo("Caballero");
                      band = true;
                  } else {
                      cout << "Ese tipo de guerrero no existe, intenta de nuevo" << endl << endl;
                  }

            }
            return i;

        }
};
#endif