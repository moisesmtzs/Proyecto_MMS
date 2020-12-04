#include "civilizacion.h"

void Civilizacion::respaldarA( const Civilizacion &c ){
    
    ofstream aldea( getNombre() + ".txt", ios::out );
    if ( aldea.is_open() ){
        for ( auto i = aldeanos.begin() ; i != aldeanos.end(); i++ ){

            Aldeano &a = *i;
            aldea << a.getNombre() << endl;
            aldea << a.getEdad() << endl;
            aldea << a.getGenero() << endl;
            aldea << a.getSalud() << endl;

        }

    }
    aldea.close();

}

void Civilizacion::recuperarA( const Civilizacion &c ){

    ifstream aldea( getNombre() + ".txt" );
    if ( aldea.is_open() ){

        while ( !aldea.eof() ){

            Aldeano a;
            int edad, salud;
            string temp;
            getline(aldea,temp);
            if ( aldea.eof() ){
                break;
            }
            a.setNombre(temp);

            getline(aldea,temp);
            edad = stoi(temp);
            a.setEdad(edad);

            getline(aldea,temp);
            a.setGenero(temp);

            getline(aldea,temp);
            salud = stoi(temp);
            a.setSalud(salud);
            agregarFinal(a);

        }

    }
    aldea.close();

}

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

void Civilizacion::agregarBarco( Barco *b ){

    puerto.push_back(b);

}

void Civilizacion::mostrarBarco(){

    cout << endl << left;
    cout << setw(8) << "Id";
    cout << setw(12) << "Combustible";
    cout << setw(12) << "Velocidad";
    cout << setw(12) << "Armadura";
    cout << setw(12) << "Cantidad de Guerreros";
    cout << endl << endl;
    for ( auto &barcos: puerto ){
        cout << barcos << endl;
    }

}

void Civilizacion::buscarBarco( const string &id ){

    bool band = false;
    for ( auto i = puerto.begin(); i != puerto.end(); i++ ){

        Barco *b = *i;
        if ( id == b->getId() ){
            
            int op;
            band = true;
            cout << endl << "Barco encontrado" << endl << endl;
            cout << left;
            cout << setw(8) << "Id";
            cout << setw(12) << "Combustible";
            cout << setw(12) << "Velocidad";
            cout << setw(12) << "Armadura";
            cout << setw(12) << "Cantidad de Guerreros";
            cout << endl << endl;
            cout << b;
            cout << endl;
            while ( true ){

                cout << "1) Agregar Guerrero" << endl
                    << "2) Eliminar Guerrero" << endl
                   << "3) Mostrar último guerrero" << endl
                  << "4) Mostrar guerreros" << endl
                 << "0) Salir" << endl
                << "Elige una opción: "<< endl;
                cin >> op; cin.ignore();
                if ( op == 0 ){
                    break;
                }
                else if ( op == 1 ){
                    Guerrero g;
                    cin >> g;
                    b->agregarGuerrero(g);
                }   
                else if ( op == 2 ){
                    b->eliminarGuerrero();
                }   
                else if ( op == 3 ){
                    if ( b->getGuerreros() == 0 ){
                        cout << endl << "\t\t~~No hay más guerreros~~" << endl << endl;
                    } else {
                        b->tope();
                    }
                }   
                else if ( op == 4 ){
                    b->mostrarG();
                } else {
                    cout << "Opción no válida, intenta de nuevo "<< endl << endl;
                }   

            }

        }

    }
    if( band == false ){
        cout << "Barco hundido, sigue buscando" << endl; 
    }

}

void Civilizacion::eliminarBarcoId( const string &id ){
    
    for ( auto i = puerto.begin() ; i != puerto.end() ; i++ ){

        Barco *b = *i;
        if ( id == b->getId() ){
            puerto.erase(i);
            break;
        }

    }
}

void Civilizacion::eliminarBarcoCombustible( const double &c ){

    puerto.remove_if([c]( const Barco *b ){ return c >= b->getCombustible() ;} );

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
