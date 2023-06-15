class Interfaz {
public:
    virtual void metodo() = 0;
    virtual void otroMetodo() {
        // Implementación opcional
    }
    
    // Destructor virtual
    virtual ~Interfaz() {}
};

// Clase derivada que implementa la interfaz
class ClaseDerivada : public Interfaz {
public:
    void metodo() override {
        // Implementación del método
    }
};

int main() {

    Interfaz* miPuntero = new ClaseDerivada();
    
    // Llamar al método de la interfaz a través del puntero
    miPuntero->metodo();
    
    // Liberar memoria
    delete miPuntero;
    
    return 0;
}
