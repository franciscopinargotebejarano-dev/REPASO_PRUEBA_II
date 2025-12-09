#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Corredor {
    int numero;
    string nombre;
    string categoria;
    float tiempoMinutos;
};

// ------------------------------------------------------
// FUNCION 1: INSCRIBIR CORREDOR
// ------------------------------------------------------
Corredor inscribirCorredor() {
    Corredor nuevo;
    cout << "\n--- Inscripción de nuevo corredor ---\n";

    // Generar número random entre 100 y 500
    nuevo.numero = rand() % 401 + 100; 

    cout << "Número asignado: " << nuevo.numero << endl;

    cout << "Ingrese nombre del corredor: ";
    cin.ignore();
    getline(cin, nuevo.nombre);

    cout << "Seleccione categoría (Élite / Amateur / Senior): ";
    getline(cin, nuevo.categoria);

    nuevo.tiempoMinutos = 0; // aún no registra tiempo
    cout << "Corredor inscrito correctamente.\n";

    return nuevo;
}

// ------------------------------------------------------
// FUNCION 2: VER INSCRITOS
// ------------------------------------------------------
void verInscritos(const vector<Corredor> &corredores) {
    cout << "\n--- Lista de inscritos ---\n";

    if (corredores.empty()) {
        cout << "No existen corredores registrados.\n";
        return;
    }

    for (const auto &c : corredores) {
        cout << "Número: " << c.numero << endl;
        cout << "Nombre: " << c.nombre << endl;
        cout << "Categoría: " << c.categoria << endl;
        cout << "Tiempo registrado: ";
        if (c.tiempoMinutos == 0)
            cout << "Sin registro\n";
        else
            cout << c.tiempoMinutos << " minutos\n";

        cout << "-----------------------------\n";
    }
}

// ------------------------------------------------------
// FUNCION 3: REGISTRAR TIEMPO DE LLEGADA
// ------------------------------------------------------
void registrarTiempo(vector<Corredor> &corredores) {
    if (corredores.empty()) {
        cout << "No hay corredores para actualizar.\n";
        return;
    }

    int num;
    cout << "Ingrese el número del corredor: ";
    cin >> num;

    bool encontrado = false;

    for (auto &c : corredores) {
        if (c.numero == num) {
            encontrado = true;
            cout << "Ingrese el tiempo en minutos: ";
            cin >> c.tiempoMinutos;
            cout << "Tiempo registrado exitosamente.\n";
            break;
        }
    }

    if (!encontrado)
        cout << "No existe un corredor con ese número.\n";
}

// ------------------------------------------------------
// FUNCION OPCIONAL: DAR DE BAJA
// ------------------------------------------------------
void darDeBaja(vector<Corredor> &corredores) {
    if (corredores.empty()) {
        cout << "No hay corredores para dar de baja.\n";
        return;
    }

    int num;
    cout << "Ingrese el número del corredor a eliminar: ";
    cin >> num;

    for (size_t i = 0; i < corredores.size(); i++) {
        if (corredores[i].numero == num) {
            corredores.erase(corredores.begin() + i);
            cout << "Corredor eliminado exitosamente.\n";
            return;
        }
    }

    cout << "Corredor no encontrado.\n";
}

// ------------------------------------------------------
// MAIN COMPLETO
// ------------------------------------------------------
int main() {
    setlocale(LC_ALL, "es_MX.UTF-8");
    srand(time(NULL));

    vector<Corredor> listaCorredores;
    int opcion = 0;

    do {
        cout << "\n==== Sistema de Registro 'Quito Ruta de las Iglesias 10K' ====\n";
        cout << "1. Inscribir Corredor\n";
        cout << "2. Ver Lista de Inscritos\n";
        cout << "3. Registrar Tiempo de Llegada\n";
        cout << "4. Dar de Baja a Corredor\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            listaCorredores.push_back(inscribirCorredor());
        }
        else if (opcion == 2) {
            verInscritos(listaCorredores);
        }
        else if (opcion == 3) {
            registrarTiempo(listaCorredores);
        }
        else if (opcion == 4) {
            darDeBaja(listaCorredores);
        }
        else if (opcion == 5) {
            cout << "Saliendo del sistema...\n";
        }
        else {
            cout << "Opción no válida.\n";
        }

    } while (opcion != 5);

    return 0;
}

