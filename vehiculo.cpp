#include <iostream>
#include <string>
using namespace std;

class Vehiculo{
	protected:
		string numeroPlaca;
		string color;
		string marca;
		float velocimetro;
		
	public:
		Vehiculo();
		void mostrarDatos();
		float cambiarVelocidad(float nuevaVelocidad);
};

Vehiculo::Vehiculo(){
	numeroPlaca="No registrada";
	color="No registrado";
	marca="No registrado";
	velocimetro=0;
}

void Vehiculo::mostrarDatos(){
	cout << "Numero de Placa: " << numeroPlaca << "\n";
	cout << "Color: " << color << "\n";
	cout << "Marca: " << marca << "\n";
	cout << "Velocimetro: " << velocimetro << "\n";
}

float Vehiculo::cambiarVelocidad(float nuevaVelocidad){
	if(nuevaVelocidad>0){
		velocimetro=nuevaVelocidad;
		return velocimetro;
	}else{
		cout << "No se pudo cambiar la velocidad\n";
	}
}

//Clase Derivada Automovil
class Automovil:public Vehiculo{
	private:
		int CantidadPuertas;
		int CantidadPasajeros;
		
	public:
		Automovil();
		void mostrarAutomovil();
		void subirPasajeros(int suben);
		void bajarPasajeros(int bajan);
};

Automovil::Automovil():Vehiculo(){
	CantidadPuertas=2;
	CantidadPasajeros=0;
}

void Automovil::mostrarAutomovil(){
	mostrarDatos();
	cout << "Cantidad de Puertas: " << CantidadPuertas << endl;
	cout << "Cantidad de Pasajeros: " << CantidadPasajeros << endl;
}

void Automovil::subirPasajeros(int suben){
	if(suben>0){
		CantidadPasajeros=+suben;
	}else{
		cout << "No se pudo actualizar los pasajeros al subir...\n";
		cout << endl;
	}
}

void Automovil::bajarPasajeros(int bajan){
	if(bajan>=0 && bajan<=CantidadPasajeros){
		CantidadPasajeros-=bajan;
	}else{
		cout << "No se pudo actualizar los pasajeros al bajar...\n";
		cout << endl;
	}
}

int main (){
	float nuevaVelocidad;
	int suben;
	int bajan;
	
	Vehiculo Toyota;
	Toyota.mostrarDatos();
	cin.ignore();
	
	cout << "Ingrese la nueva velocidad: ";
	cin >> nuevaVelocidad;
	Toyota.cambiarVelocidad(nuevaVelocidad);
	cin.ignore();
	
	Toyota.mostrarDatos();
	cin.ignore();
		
	
	Automovil a;
	a.mostrarAutomovil();
	cin.ignore();
	
	cout << "Ingrese la cantidad de pasajeros que suben: ";
	cin >> suben;
	a.subirPasajeros(suben);
	cin.ignore();
	
	cout << "Ingrese la cantidad de pasajeros que bajan: ";
	cin >> bajan;
	a.bajarPasajeros(bajan);
	cout << endl;
	cin.ignore();
	
	a.mostrarAutomovil();
	cin.ignore();
	
	return 0;
}
