#include "civilizacion.h"
#include "videogame.h"

enum Opciones{
    opc_salir,
    opc_agregar,
    opc_eliminar,
    opc_clasificar,
    opc_buscar,
    opc_modificar,
    opc_mostrar,
};

void men( Civilizacion &c ){

    int op;
    int punt = 0;
    while ( true ){
        cout << opc_salir <<") Salir" << endl
            << opc_agregar << ") Agregar aldeano" << endl
           << opc_eliminar << ") Eliminar aldeano" << endl
          << opc_clasificar << ") Clasificar aldeanos" << endl 
         << opc_buscar << ") Buscar aldeano" << endl
        << opc_modificar << ") Modificar aldeano" << endl
        << opc_mostrar << ") Mostrar aldeano" << endl;
        cin >> op; cin.ignore();
        if ( op == 0 ){
            break;
        }
        else if ( op == 1 ){

            Aldeano a;
            string opc;
            while (true){
                cout << endl<<"\t\t| Agregar Aldeano |" << endl << "0) Salir" << endl 
                    << "1) Agregar Inicio" << endl
                   << "2) Agregar Final" << endl;
                getline(cin, opc); 
                if ( opc == "0" ){
                    break;
                }
                else if ( opc == "1" ){
                    cin >> a;
                    punt += 100;
                    c.agregarInicio(a);
                }
                else if ( opc == "2" ){
                    cin >> a;
                    punt += 100;
                    c.agregarFinal(a);
                } else {
                    cout << "Opción no válida, intenta de nuevo" << endl;
                }
            }
        }
        else if ( op == 2 ){

            Aldeano a;
            string opc;
            while (true){
                cout << endl<<"\t\t| Eliminar Aldeano |" << endl << "0) Salir" << endl
                    << "1) Eliminar por Nombre" << endl
                   << "2) Eliminar por Salud" << endl 
                  << "3) Eliminar por Edad" << endl;
                getline(cin, opc); 
                if ( opc == "0" ){
                    break;
                }
                else if ( opc == "1" ){

                    string nombre;
                    cout << "Nombre del aldeano: ";
                    getline(cin, nombre); cin.ignore();
                    c.eliminarNombre(nombre);

                }
                else if ( opc == "2" ){

                    int salud;
                    cout << "Salud del aldeano: ";
                    cin >> salud; cin.ignore();
                    c.eliminarSalud(salud);

                } 
                else if ( opc == "3" ){

                    c.eliminarEdad();

                } else {
                    cout << "Opción no válida, intenta de nuevo" << endl;
                }
            }

        }
        else if ( op == 3 ){

            string opc;
            while ( true ){

                cout << endl << "\t\t| Clasificar aldeanos |" << endl << "0) Salir" << endl
                    << "1) Clasificar por nombre" << endl
                   << "2) Clasificar por edad" << endl 
                  << "3) Clasificar por salud" << endl;
                  getline(cin, opc);
                if ( opc == "0" ){
                    break;
                } 
                else if ( opc == "1" ){
                    c.clasificarNombre();
                }
                else if ( opc == "2" ){
                    c.clasificarEdad();
                }
                else if ( opc == "3" ){
                    c.clasificarSalud();
                } else {
                    cout << "Opción no válida, intenta de nuevo" << endl;
                }

            }

        }
        else if ( op == 4 ){

            Aldeano a;
            string nombre;
            cout << endl <<"\t\t| Buscar aldeano |" << endl;
            getline(cin, nombre);
            a.setNombre(nombre);
            Aldeano *ptr = c.buscar(a);
            if ( ptr == nullptr ){
                cout << "Aldeano no encontrado, se dio a la fuga" << endl << endl;
            } else {

                cout << "Aldeano encontrado" << endl; cout << left;
                cout << setw(16) << "Nombre"
                    << setw(12) << "Edad"
                   << setw(12) << "Genero"
                  << setw(16) << "Salud" << endl;
                cout << *ptr << endl << endl;

            }

        }
        else if ( op == 5 ){

            Aldeano a;
            string temp, nombre;
            int n;
            float m;
            cout << endl << "\t\t| Modificar aldeano |" << endl;
            getline(cin, nombre);
            a.setNombre(nombre);
            Aldeano *ptr = c.buscar(a);
            if ( ptr == nullptr ){
                cout << "Aldeano no encontrado, se dio a la fuga" << endl << endl;
            } else {

                int opt;
                cout << "Aldeano encontrado" << endl; cout << left << endl;
                cout << "¿Qué quieres modificar?" << endl<< endl;
                cout << setw(16) << "1) Nombre"
                    << setw(12) << "2) Edad"
                   << setw(12) << "3) Genero"
                  << setw(16) << "4) Salud" << endl;
                cout << "  " << *ptr << endl << endl;
                cin >> opt; cin.ignore();
                switch ( opt ){
                    case 1:
                        cout << "\t| Nombre |" << endl<< endl;
                        getline(cin, temp);
                        ptr->setNombre(temp); 
                        cout << "Aldeano actualizado" << endl<< endl;
                        break;
                    case 2:
                        cout << "\t| Edad |" << endl<< endl;
                        cin >> n; cin.ignore();
                        ptr->setEdad(n);
                        cout << "Aldeano actualizado" << endl<< endl;
                        break;
                    case 3:
                        cout << "\t| Genero |" << endl<< endl;
                        getline(cin, temp);
                        ptr->setGenero(temp);
                        cout << "Aldeano actualizado" << endl<< endl;
                        break;
                    case 4:
                        cout << "\t| Salud |" << endl<< endl;
                        cin >> m; cin.ignore();
                        ptr->setSalud(m);
                        cout << "Aldeano actualizado" << endl<< endl;
                        break;

                    default: cout << "Opción no válida, intenta de nuevo" << endl << endl;
                        break;
                }

            }
        }
        else if ( op == 6 ){
            c.mostrar();
        } else {
            cout << "Opción no válida, intenta de nuevo" << endl;
        }

    }

}