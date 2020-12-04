#include "guerrero.h"
#include "civilizacion.h"
#include "videogame.h"

enum Opciones{
    opc_salir,
    opc_agregar,
    opc_mostrar,
    opc_buscar,
    opc_eliminar,
};

void menuB( Civilizacion &c ){

    int op;
    while ( true ){

        cout << opc_salir <<") Salir" << endl
            << opc_agregar << ") Agregar barco" << endl
           << opc_mostrar << ") Mostrar barco" << endl
          << opc_buscar << ") Buscar barco" << endl 
         << opc_eliminar << ") Eliminar" << endl;
        cin >> op; cin.ignore();
        if ( op == 0 ){
            break;
        }
        else if ( op == 1 ){
            Barco *b = new Barco();
            cin >> b;
            c.agregarBarco(b);
        }
        else if ( op == 2 ){
            c.mostrarBarco();
        }
        else if ( op == 3 ){
            string s;
            cout << "\t\t| Buscar barco |" << endl << endl
                << "ID a buscar: ";
            getline(cin,s);
            c.buscarBarco(s);
        }
        else if ( op == 4 ){

            int opc;
            cout << "\t\t| Eliminar barco |" << endl << endl
                << "1) Eliminar por ID" << endl
               << "2) Eliminar por combustible" << endl
              << "Opción: ";
            cin >> opc; cin.ignore(); cout << endl;
            if ( opc == 1 ){
                string s;
                cout << "ID a borrar: ";
                getline(cin,s); cout << endl;
                c.eliminarBarcoId(s);
            } 
            else if ( opc == 2 ){
                double n;
                cout << "Combustible: ";
                cin >> n; cin.ignore();
                c.eliminarBarcoCombustible(n);
            }

        } else {
            cout << "Opción no válida, intenta de nuevo" << endl;
        }

    }

}