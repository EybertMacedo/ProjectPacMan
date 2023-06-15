class Personaje {
protected:
    int posX;  // Posición X del personaje en el laberinto
    int posY;  // Posición Y del personaje en el laberinto

public:
    Personaje(int x, int y) : posX(x), posY(y) {}

    virtual void mover() = 0;  // Método virtual puro para el movimiento del personaje

    // Otros métodos y atributos comunes a todos los personajes
};
