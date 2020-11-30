#include "videogame.h"

void Videogame::setNombreU( const string &n ){
    nombre = n;
}
string Videogame::getNombreU(){
    return nombre;
}

size_t Videogame::Total(){
    return civilizaciones.size();
}

bool Videogame::vacio() const {
    return civilizaciones.size() == 0;
}

void Videogame::mostrar(){

    cout << endl;
    cout << left;
    cout << setw(12) << "Nombre";
    cout << setw(12) << "X";
    cout << setw(12) << "Y";
    cout << setw(12) << "Puntuación";
    cout << endl << endl;
    for ( size_t i = 0 ; i < civilizaciones.size() ; i++ ){

        Civilizacion &c = civilizaciones[i];
        cout << c;
        cout << endl;

    }


}

void Videogame::push_back( const Civilizacion &c ){
    
    civilizaciones.push_back(c);

}

void Videogame::insert( const Civilizacion &c, size_t p ){

    civilizaciones.insert( civilizaciones.begin()+p, c );

}

void Videogame::crear( const Civilizacion &c, size_t n ){

    civilizaciones = vector<Civilizacion>( n, c );

}

void Videogame::front() const {
    cout << endl << "\t| Primera Civilización |" << endl << endl;
    cout << left;
    cout << setw(12) << "Nombre";
    cout << setw(12) << "X";
    cout << setw(12) << "Y";
    cout << setw(12) << "Puntuación";
    cout << endl << endl;
    cout << civilizaciones.front();
}

void Videogame::back() const {
    cout << endl << "\t| Última Civilización |" << endl << endl;
    cout << left;
    cout << setw(12) << "Nombre";
    cout << setw(12) << "X";
    cout << setw(12) << "Y";
    cout << setw(12) << "Puntuación";
    cout << endl << endl;
    cout << civilizaciones.back();
}

void Videogame::ordenarNombre(){
    sort( civilizaciones.begin(), civilizaciones.end() );
}

void Videogame::ordenarX(){
    sort( civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c, Civilizacion c01){ return c.getX() < c01.getX(); } );
}

void Videogame::ordenarY(){
    sort( civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c, Civilizacion c01){ return c.getY() < c01.getY(); } );
}

void Videogame::ordenarPunt(){
    sort( civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c, Civilizacion c01){ return c.getPuntuacion() > c01.getPuntuacion(); } );
}


void Videogame::erase( const string &nombre ){

    for ( auto i = civilizaciones.begin() ; i != civilizaciones.end() ; i++ ){

        Civilizacion &c = *i;
        if ( nombre == c.getNombre() ){

            civilizaciones.erase(i);
            break;

        }

    }

}

Civilizacion* Videogame::modificar( Civilizacion &c ){

    int op;
    string temp;
    float x, y, punt;
    cout << endl << "Civilización encontrada, qué quieres modificar?" << endl;
    cout << endl;
    cout << left;
    cout << setw(12) << "1) Nombre";
    cout << setw(12) << "2) X";
    cout << setw(12) << "3) Y";
    cout << setw(12) << "4) Puntuación";
    cout << endl;
    cout << "   " << c;
    cin >> op; cin.ignore();
    switch ( op ){
        case 1:
            cout << "\t| Nombre | "<< endl;
            getline(cin, temp);
            c.setNombre(temp);
            cout << "Civilización actualizada" << endl;
            break;
        case 2:
            cout << "\t| X | "<< endl;
            cin >> x; cin.ignore();
            c.setX(x);
            cout << "Civilización actualizada" << endl;
            break;
        case 3:
            cout << "\t| Y | "<< endl;
            cin >> y; cin.ignore();
            c.setY(y);
            cout << "Civilización actualizada" << endl;
            break;
        case 4:
            cout << "\t| Puntuación | "<< endl;            
            cin >> punt; cin.ignore();
            c.setPuntuacion(punt);
            cout << "Civilización actualizada" << endl;
            break;

        default: cout << "Opción no válida, intenta de nuevo" << endl;
            break;
    }

}

Civilizacion* Videogame::buscar( const Civilizacion &c ){

    auto i = find( civilizaciones.begin(), civilizaciones.end(), c );
    if ( i == civilizaciones.end() ){
        return nullptr;
    } else {
        return &(*i);
    }

}