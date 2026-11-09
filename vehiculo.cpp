#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
    protected:
        string numeroPlaca;
        string color;
        string marca;
        float velocimetro;

    public:
        Vehiculo();
        Vehiculo(string placa, string col, string mar, float vel);
        void mostrarDatos();
        float cambiarVelocidad(float nuevaVelocidad);
};

Vehiculo::Vehiculo() {
    numeroPlaca = "No registrada";
    color = "No registrado";
    marca = "No registrado";
    velocimetro = 0;
}

Vehiculo::Vehiculo(string placa, string col, string mar, float vel) {
    numeroPlaca = placa;
    color = col;
    marca = mar;
    velocimetro = vel;
}

void Vehiculo::mostrarDatos() {
    cout << "Numero de Placa: " << numeroPlaca << "\n";
    cout << "Color: " << color << "\n";
    cout << "Marca: " << marca << "\n";
    cout << "Velocimetro: " << velocimetro << " km/h\n";
}

float Vehiculo::cambiarVelocidad(float nuevaVelocidad) {
    if (nuevaVelocidad >= 0) {
        velocimetro = nuevaVelocidad;
        cout << "Velocidad actualizada correctamente...\n";
    } else {
        cout << "No se pudo cambiar la velocidad...\n";
    }

    return velocimetro;
}

class Automovil : public Vehiculo {
    private:
        int CantidadPuertas;
        int CantidadPasajeros;

    public:
        Automovil();
        Automovil(string placa, string col, string mar,
                  float vel, int puertas, int pasajeros);
        void mostrarAutomovil();
        void subirPasajeros(int suben);
        void bajarPasajeros(int bajan);
};

Automovil::Automovil() : Vehiculo() {
    CantidadPuertas = 2;
    CantidadPasajeros = 0;
}

Automovil::Automovil(string placa, string col, string mar,
                     float vel, int puertas, int pasajeros)
    : Vehiculo(placa, col, mar, vel) {
    CantidadPuertas = puertas;
    CantidadPasajeros = pasajeros;
}

void Automovil::mostrarAutomovil() {
    mostrarDatos();
    cout << "Cantidad de Puertas: " << CantidadPuertas << endl;
    cout << "Cantidad de Pasajeros: " << CantidadPasajeros << endl;
}

void Automovil::subirPasajeros(int suben) {
    if (suben > 0) {
        CantidadPasajeros += suben;
        cout << "Pasajeros subidos correctamente...\n";
    } else {
        cout << "Cantidad de pasajeros no valida...\n";
    }
}

void Automovil::bajarPasajeros(int bajan) {
    if (bajan > 0 && bajan <= CantidadPasajeros) {
        CantidadPasajeros -= bajan;
        cout << "Pasajeros bajados correctamente...\n";
    } else {
        cout << "No se pudo actualizar los pasajeros al bajar...\n";
    }
}

class Camion : public Vehiculo {
    private:
        float carga;

    public:
        Camion();
        Camion(string placa, string col, string mar,
               float vel, float nuevaCarga);
        void mostrarCamion();
        float cambiarCarga(float nuevaCarga);
};

Camion::Camion() : Vehiculo() {
    carga = 20;
}

Camion::Camion(string placa, string col, string mar,
               float vel, float nuevaCarga)
    : Vehiculo(placa, col, mar, vel) {
    carga = nuevaCarga;
}

void Camion::mostrarCamion() {
    mostrarDatos();
    cout << "Carga: " << carga << " Kg\n";
}

float Camion::cambiarCarga(float nuevaCarga) {
    if (nuevaCarga >= 0) {
        carga = nuevaCarga;
        cout << "Carga actualizada correctamente...\n";
    } else {
        cout << "Nueva carga no valida...\n";
    }

    return carga;
}

int main() {
    float nuevaVelocidad;
    float nuevaCarga;
    int suben;
    int bajan;

    cout << "========== AUTOMOVIL ==========\n";

    Automovil a("ABC-123", "Rojo", "Toyota", 80, 4, 2);

    cout << "\nDatos iniciales del Automovil:\n";
    a.mostrarAutomovil();

    cout << "\nIngrese la nueva velocidad: ";
    cin >> nuevaVelocidad;
    a.cambiarVelocidad(nuevaVelocidad);

    cout << "\nIngrese la cantidad de pasajeros que suben: ";
    cin >> suben;
    a.subirPasajeros(suben);

    cout << "\nIngrese la cantidad de pasajeros que bajan: ";
    cin >> bajan;
    a.bajarPasajeros(bajan);

    cout << "\nDatos finales del Automovil:\n";
    a.mostrarAutomovil();

    cout << "\n========== CAMION ==========\n";

    Camion c("XYZ-456", "Azul", "Volvo", 60, 5000);

    cout << "\nDatos iniciales del Camion:\n";
    c.mostrarCamion();

    cout << "\nIngrese la nueva velocidad: ";
    cin >> nuevaVelocidad;
    c.cambiarVelocidad(nuevaVelocidad);

    cout << "\nIngrese la nueva carga (Kg): ";
    cin >> nuevaCarga;
    c.cambiarCarga(nuevaCarga);

    cout << "\nDatos finales del Camion:\n";
    c.mostrarCamion();

    return 0;
}

