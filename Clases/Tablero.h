#pragma once
#include <vector>
using namespace std;

class Tablero {
private:
    vector<vector<char>> tablero;

public:
    // Constructor
    Tablero();

    // Mostrar el tablero
    void imprimir() const;

    // Validar si un movimiento es válido
    bool esMovimientoValido(int fila, int columna) const;

    // Realizar un movimiento
    void hacerMovimiento(int fila, int columna, char jugador);

    // Verificar si un jugador ha ganado
    bool verificarVictoria(char jugador) const;

    // Verificar si el tablero está lleno
    bool estaLleno() const;
};
