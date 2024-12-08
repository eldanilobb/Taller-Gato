#include <iostream>
#include <vector>
#include "Tablero.h"

using namespace std;

    // Constructor
    Tablero :: Tablero() : tablero(3, vector<char>(3, ' ')) {}

    // Mostrar el tablero
    void Tablero :: imprimir() const {
        cout << "  0 1 2\n";
        for (int i = 0; i < 3; i++) {
            cout << i << " ";
            for (int j = 0; j < 3; j++) {
                cout << tablero[i][j];
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "  -----\n";
        }
    }

    // Validar si un movimiento es válido
    bool Tablero ::  esMovimientoValido(int fila, int columna) const {
        return fila >= 0 && fila < 3 && columna >= 0 && columna < 3 && tablero[fila][columna] == ' ';
    }

    // Realizar un movimiento
    void Tablero :: hacerMovimiento(int fila, int columna, char jugador) {
        if (esMovimientoValido(fila, columna)) {
            tablero[fila][columna] = jugador;
        }
    }

    // Verificar si un jugador ha ganado
    bool Tablero :: verificarVictoria(char jugador) const {
        // Verificar filas y columnas
        for (int i = 0; i < 3; i++) {
            if ((tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) ||
                (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)) {
                return true;
            }
        }
        // Verificar diagonales
        if ((tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) ||
            (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)) {
            return true;
        }
        return false;
    }

    // Verificar si el tablero está lleno
    bool Tablero :: estaLleno() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == ' ') return false;
            }
        }
        return true;
    }