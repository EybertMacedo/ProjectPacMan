#include "motorSonido.h"

MotorSonido::MotorSonido() {
    instanciaEfecto = nullptr;
}

MotorSonido::~MotorSonido() {
    liberarRecursos();
}

bool MotorSonido::inicializar() {
    if (!al_init()) {                       // Inicializa Allegro
        return false;
    }

    if (!al_install_audio()) {              // Instala el sistema de audio de Allegro
        return false;
    }

    if (!al_init_acodec_addon()) {          // Inicializa los códecs de audio de Allegro
        return false;
    }

    if (!al_reserve_samples(1)) {           // Reserva un canal de audio para reproducir efectos de sonido
        return false;
    }

    return true;
}

void MotorSonido::reproducirEfecto(const char* rutaArchivo) {
    liberarRecursos();

    ALLEGRO_SAMPLE* efecto = cargarEfecto(rutaArchivo);
    if (efecto == nullptr) {
        return;
    }

    instanciaEfecto = al_create_sample_instance(efecto);     // Crea una instancia del efecto de sonido
    al_play_sample_instance(instanciaEfecto);                // Reproduce la instancia del efecto de sonido
}

void MotorSonido::liberarRecursos() {
    if (instanciaEfecto != nullptr) {
        al_stop_sample_instance(instanciaEfecto);             // Detiene la reproducción de la instancia del efecto de sonido
        al_destroy_sample_instance(instanciaEfecto);          // Libera la instancia del efecto de sonido
        instanciaEfecto = nullptr;
    }
}

ALLEGRO_SAMPLE* MotorSonido::cargarEfecto(const char* rutaArchivo) {
    ALLEGRO_SAMPLE* efecto = al_load_sample(rutaArchivo);     // Carga el archivo de efecto de sonido
    if (efecto == nullptr) {
        // Error al cargar el efecto
    }

    return efecto;
}

int main() {
    MotorSonido motorSonido;
    if (!motorSonido.inicializar()) {
        // Error al inicializar el motor de sonido
        return 1;
    }

    motorSonido.reproducirEfecto("efecto.wav");               // Reproduce el efecto de sonido

    // Falta rellenar

    motorSonido.liberarRecursos();

    return 0;
}