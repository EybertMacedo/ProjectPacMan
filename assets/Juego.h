class Juego {
protected:
    Laberinto laberinto;
    Personaje personajes;
    Interfaz interfaz;
    ManejadorEventos manejadorEventos;

public:
    virtual void iniciarJuego() = 0; // Método virtual puro para iniciar el juego
    virtual void actualizarEstado() = 0; // Método virtual puro para actualizar el estado del juego
    virtual bool condicionFinJuego() = 0; // Método virtual puro para verificar la condición de finalización del juego
};
