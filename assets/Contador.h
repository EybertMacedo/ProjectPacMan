#include <iostream>

class Contador {
public:
    Contador(int vidasIniciales) : vidas(vidasIniciales), puntaje(0) {}

    void incrementarPuntaje(int puntos) {
        puntaje += puntos;
    }

    void decrementarVida() {
        vidas--;
    }

    int getPuntaje() const {
        return puntaje;
    }

    int getVidas() const {
        return vidas;
    }

    void mostrarInformacion() const {
        std::cout << "Puntaje: " << puntaje << " | Vidas: " << vidas << std::endl;
    }

private:
    int vidas;
    int puntaje;
};

int main() {
    // Inicialización del juego y otras configuraciones necesarias

    Contador contador(3); // Inicialización con 3 vidas

    // Lógica del juego...

    contador.incrementarPuntaje(10); // Ejemplo de incremento del puntaje
    contador.decrementarVida(); // Ejemplo de decremento de vida

    contador.mostrarInformacion(); // Muestra la información del contador (puntaje y vidas)
   

    return 0;
}
