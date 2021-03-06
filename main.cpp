#include "videogame.h"
#include <stdexcept>

int main(){

    Videogame v;
    string op;
    while ( true ){
        
        cout << endl << "0) Salir" << endl;
        cout << "1) Agregar nombre" << endl;
        cout << "2) Agregar civilización" << endl;
        cout << "3) Insertar" << endl;
        cout << "4) Crear" << endl;
        cout << "5) Primera civilización" << endl;
        cout << "6) Última civilización" << endl;
        cout << "7) Ordenar" << endl;
        cout << "8) Eliminar civilización" << endl;
        cout << "9) Buscar" << endl;
        cout << "10) Modificar" << endl;
        cout << "11) Mostrar" << endl;
        getline(cin,op);
        cout << endl;
        if ( op == "0" ){
            break;
        }
        else if ( op == "1" ){
            string nombre;
            cout << "Nombre de usuario: ";
            getline(cin,nombre);
            v.setNombreU(nombre);
            cout << endl << "\t| " << v.getNombreU() << " |" << endl;
            
        }
        else if ( op == "2" ){

            Civilizacion c;
            cin >> c;
            v.push_back(c);

        }
        else if ( op == "3" ){

            Civilizacion c;
            cin >> c;
            cout << "N: ";
            size_t n;
            cin >> n; cin.ignore();
            if ( v.vacio() ){
                throw runtime_error("Trying insert a civilization on a empty list");
            }
            else if ( n > v.Total() ){
                throw runtime_error( "Trying to insert a civilization in a non valid position, try again" );
            }
            else if ( n == v.Total() ){
                v.push_back(c);
            } else {
                v.insert( c, n );
            }

        }
        else if ( op == "4" ){

            Civilizacion c;
            size_t n;
            cin >> c;
            cout << "n: "; cin >> n; cin.ignore();
            cout << "Creando civilización..." << endl;
            v.crear(c, n);

        }
        else if ( op == "5" ){
            if ( v.vacio() ){
                cout << "Aún no hay civilizaciones por aqui D:" << endl;
            } else {
                v.front();
            }
        }
        else if ( op == "6" ){
            if ( v.vacio() ){
                cout << "Aún no hay civilizaciones por aqui D:" << endl;
            } else {
                v.back();
            }
        }
        else if ( op == "7" ){

            int opt;
            cout << "1) Ordenar por Nombre" << endl;
            cout << "2) Ordenar por coordenada X" << endl;
            cout << "3) Ordenar por coordenada Y" << endl;
            cout << "4) Ordenar por puntuación" << endl;
            cin >> opt; 
            cin.ignore();
            switch (opt){
            case 1:
                v.ordenarNombre();
                break;
            case 2:
                v.ordenarX();
                break;
            case 3:
                v.ordenarY();
                break;
            case 4:
                v.ordenarPunt();
                break;
            default: cout << "Opción no válida, intenta de nuevo" << endl;
                break;
            }


        }
        else if ( op == "8" ){
            
            string c;
            cout << "\t| Civilización a eliminar |" << endl;
            getline(cin, c);
            v.erase(c);
            cout << "No existe más esa civilización" << endl;

        }
        else if ( op == "9" ){

            string c;
            Civilizacion c1;
            cout << "\t| Civilización a buscar |" << endl;
            getline(cin, c);
            c1.setNombre(c);
            Civilizacion *ptr = v.buscar(c1);
            if ( ptr == nullptr ){
                cout << "Civilización no encontrada" << endl;
            } else {
                cout << "Civilización encontrada" << endl;
                cout << endl;
                cout << left;
                cout << setw(12) << "Nombre";
                cout << setw(12) << "X";
                cout << setw(12) << "Y";
                cout << setw(12) << "Puntuación";
                cout << endl;
                cout << *ptr << endl;
            }

        }
        else if ( op == "10" ){

            Civilizacion c1;
            string c;
            cout << "\t| Civilización a modificar |" << endl;
            cout << endl << endl << "Nombre de la civilización: ";
            getline(cin, c); 
            c1.setNombre(c);
            Civilizacion *ptr = v.buscar(c1);
            if ( ptr == nullptr ){
                cout << "No existe esa civilización" << endl;
            } else {
                v.modificar(*ptr);
            }

        }
        else if ( op == "11" ){
            v.mostrar();

        } else {
            cout << "Opción no válida, intente de nuevo \n";
        }

    }

    return 0;
}