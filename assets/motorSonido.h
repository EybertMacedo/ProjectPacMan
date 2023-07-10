#include <allegro5/allegro.h>              // Incluye la biblioteca Allegro 5
#include <allegro5/allegro_audio.h>        // Incluye la biblioteca de audio de Allegro 5
#include <allegro5/allegro_acodec.h>       // Incluye la biblioteca de códecs de audio de Allegro 5

class MotorSonido {
public:
    MotorSonido();
    ~MotorSonido();

    bool inicializar();
    void reproducirEfecto(const char* rutaArchivo);
    void liberarRecursos();

private:
    ALLEGRO_SAMPLE* cargarEfecto(const char* rutaArchivo);

    ALLEGRO_SAMPLE_INSTANCE* instanciaEfecto;
};

