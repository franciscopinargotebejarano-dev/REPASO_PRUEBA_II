#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct YouTuber {
    string nombreCanal;
    string categoria;
    double suscriptores;          
    double gananciaPorMillon;     
};

void mostrarReporte(YouTuber M[3][3]) {
    double totalSuscriptores = 0;
    double totalGanancias = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            totalSuscriptores += M[i][j].suscriptores;
            totalGanancias += (M[i][j].suscriptores * M[i][j].gananciaPorMillon);
        }
    }

    cout << "\n===== REPORTE FINAL =====\n";
    cout << "Total de suscriptores (millones): " << totalSuscriptores << endl;
    cout << "Total de ganancias mensuales (USD): $" << totalGanancias << endl;
}

void buscarPorCategoria(YouTuber M[3][3]) {
    string cat;
    cout << "Ingrese categoría a buscar (entretenimiento, videojuegos, comedia): ";
    cin >> cat;

    cout << "\n--- Resultados encontrados ---\n";

    bool encontrado = false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (M[i][j].categoria == cat) {
                encontrado = true;

                cout << "\nCanal: " << M[i][j].nombreCanal << endl;
                cout << "Posición en matriz: Fila " << i << " - Columna " << j << endl;
                cout << "Suscriptores (millones): " << M[i][j].suscriptores << endl;
                cout << "Ganancia mensual (USD): $" << (M[i][j].suscriptores * M[i][j].gananciaPorMillon) << endl;
            }
        }
    }

    if (!encontrado) {
        cout << "No se encontraron youtubers en esa categoría.\n";
    }
}

int main() {
    srand(time(NULL));

    YouTuber M[3][3] = {
        { {"PewDiePie", "videojuegos", 111.0, (rand()%5001 + 3000)},
          {"MrBeast", "entretenimiento", 250.0, (rand()%5001 + 3000)},
          {"Fernanfloo", "videojuegos", 45.0, (rand()%5001 + 3000)} },

        { {"ElRubius", "videojuegos", 40.0, (rand()%5001 + 3000)},
          {"DrossRotzank", "entretenimiento", 22.0, (rand()%5001 + 3000)},
          {"LuisitoComunica", "entretenimiento", 41.0, (rand()%5001 + 3000)} },

        { {"AuronPlay", "comedia", 29.0, (rand()%5001 + 3000)},
          {"HolaSoyGerman", "comedia", 48.0, (rand()%5001 + 3000)},
          {"Yuya", "entretenimiento", 25.0, (rand()%5001 + 3000)} }
    };

    int opcion;

    do {
        cout << "\n=========== MENU ===========\n";
        cout << "1. Buscar YouTubers por categoría\n";
        cout << "2. Mostrar reporte total\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                buscarPorCategoria(M);
                break;

            case 2:
                mostrarReporte(M);
                break;

            case 3:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opción inválida.\n";
        }

    } while (opcion != 3);

    return 0;
}

