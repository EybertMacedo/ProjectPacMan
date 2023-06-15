#include <allegro5/allegro.h>
#include <allegro5/allegro_event.h>

class EventHandler {
public:
    EventHandler() {
        // Registra los eventos necesarios
        al_register_event_source(eventQueue, al_get_keyboard_event_source());
    }

    void processEvents() {
        ALLEGRO_EVENT event;

        while (al_get_next_event(eventQueue, &event)) {
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                handleKeyDownEvent(event.keyboard.keycode);
            } else if (event.type == ALLEGRO_EVENT_KEY_UP) {
                handleKeyUpEvent(event.keyboard.keycode);
            }
        }
    }

private:
    ALLEGRO_EVENT_QUEUE* eventQueue; // Cola de eventos

    void handleKeyDownEvent(int keycode) {
        switch (keycode) {
            case ALLEGRO_KEY_UP:
                // Lógica para el movimiento hacia arriba
                break;
            case ALLEGRO_KEY_DOWN:
                // Lógica para el movimiento hacia abajo
                break;
            case ALLEGRO_KEY_LEFT:
                // Lógica para el movimiento hacia la izquierda
                break;
            case ALLEGRO_KEY_RIGHT:
                // Lógica para el movimiento hacia la derecha
                break;
            // Otros casos de teclas necesarios
        }
    }

    void handleKeyUpEvent(int keycode) {
        // Lógica para manejar el evento de soltar una tecla (si es necesario)
    }
};

int main() {
    // Inicialización de Allegro y otras configuraciones necesarias

    EventHandler eventHandler;

    while (true) {
        eventHandler.processEvents();

        // Lógica de actualización del juego y renderizado
    }

    // Liberación de recursos y finalización del juego
    return 0;
}
