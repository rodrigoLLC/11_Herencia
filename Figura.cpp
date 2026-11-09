
#include <iostream>
#include <string>
using namespace std;

class Figura {
    protected:
        string color;

    public:
        Figura(string col);
};

Figura::Figura(string col) {
    color = col;
}

class Circulo : public Figura {
    private:
        float radio;

    public:
        Circulo(string col, float r);
        void mostrarCirculo();
        float calcularArea();
        float calcularPerimetro();
};

Circulo::Circulo(string col, float r) : Figura(col) {
    radio = r;
}

void Circulo::mostrarCirculo() {
    cout << "Color: " << color << endl;
    cout << "Radio: " << radio << endl;
}

float Circulo::calcularArea() {
    return 3.1416 * radio * radio;
}

float Circulo::calcularPerimetro() {
    return 2 * 3.1416 * radio;
}

class Rectangulo : public Figura {
    private:
        float base;
        float altura;

    public:
        Rectangulo(string col, float b, float h);
        void mostrarRectangulo();
        float calcularArea();
};

Rectangulo::Rectangulo(string col, float b, float h) : Figura(col) {
    base = b;
    altura = h;
}

void Rectangulo::mostrarRectangulo() {
    cout << "Color: " << color << endl;
    cout << "Base: " << base << endl;
    cout << "Altura: " << altura << endl;
}

float Rectangulo::calcularArea() {
    return base * altura;
}

class Triangulo : public Figura {
    private:
        float base;
        float altura;
        string tipo;

    public:
        Triangulo(string col, float b, float h, string t);
        void mostrarTriangulo();
        float calcularArea();
};

Triangulo::Triangulo(string col, float b, float h, string t) : Figura(col) {
    base = b;
    altura = h;
    tipo = t;
}

void Triangulo::mostrarTriangulo() {
    cout << "Color: " << color << endl;
    cout << "Base: " << base << endl;
    cout << "Altura: " << altura << endl;
    cout << "Tipo: " << tipo << endl;
}

float Triangulo::calcularArea() {
    return (base * altura) / 2;
}

int main() {

    Circulo c("Rojo", 5);

    cout << "========== CIRCULO ==========\n";
    c.mostrarCirculo();
    cout << "Area: " << c.calcularArea() << endl;
    cout << "Perimetro: " << c.calcularPerimetro() << endl;

    Rectangulo r("Azul", 8, 4);

    cout << "\n========== RECTANGULO ==========\n";
    r.mostrarRectangulo();
    cout << "Area: " << r.calcularArea() << endl;

    Triangulo t("Verde", 6, 4, "Isosceles");

    cout << "\n========== TRIANGULO ==========\n";
    t.mostrarTriangulo();
    cout << "Area: " << t.calcularArea() << endl;

    return 0;
}


