#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Clases/Tablero.h"
#include "Clases/IA.h"

using namespace std;

void jugar() {
    Tablero tablero;
    char jugadorActual = 'X';

    while (true) {
        tablero.imprimir();
        cout << "Turno del jugador " << jugadorActual << endl;
        cout << "Ingrese fila y columna (separados por un espacio): ";
        int fila, columna;
        cin >> fila >> columna;

        if (tablero.esMovimientoValido(fila, columna)) {
            tablero.hacerMovimiento(fila, columna, jugadorActual);

            if (tablero.verificarVictoria(jugadorActual)) {
                tablero.imprimir();
                cout << "¡Jugador " << jugadorActual << " gana!\n";
                break;
            } else if (tablero.estaLleno()) {
                tablero.imprimir();
                cout << "¡Es un empate!\n";
                break;
            }

            // Cambiar turno
            jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
        } else {
            cout << "Movimiento inválido. Intente nuevamente.\n";
        }
    }
}

// Función marcador de posición para jugar contra IA sin optimizar
void jugarContraIA_SinOptimizar() {
    
}


// Función marcador de posición para jugar contra IA optimizada
void jugarContraIA_Optimizada() {
    cout << "Modo de juego contra IA optimizada aún no implementado.\n";
}

// Función para mostrar el menú
void mostrarMenu() {
    cout << "=== Menú ===\n";
    cout << "1. Jugar entre dos jugadores\n";
    cout << "2. Jugar contra IA sin optimizar\n";
    cout << "3. Jugar contra IA optimizada\n";
    cout << "0. Salir\n";
    cout << "Elige una opción: ";
}


int main() {
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                jugar();
                break;
            case 2:
                jugarContraIA_SinOptimizar();
                break;
            case 3:
                jugarContraIA_Optimizada();
                break;
            case 0:
                cout << "Gracias por jugar. ¡Adiós!\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 0);

    return 0;
}

