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
		void cambiarVelocidad(float nuevaVelocidad);
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

void Vehiculo::cambiarVelocidad(float nuevaVelocidad){
	if(nuevaVelocidad>0){
		velocimetro=nuevaVelocidad;
	}else{
		cout << "No se pudo cambiar la velocidad\n";
	}
}

int main (){
	return 0;
}
