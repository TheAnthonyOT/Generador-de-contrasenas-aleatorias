#include <iostream>
#include <ctime>
#include <string>

using namespace std;

void generarContrasena(int longitud, bool incluirMayusculas, bool incluirMinusculas, bool incluirSimbolos);
void MenudeGeneracion();
int main() {
MenudeGeneracion();

    return 0;
}

void MenudeGeneracion(){
    char respuesta;
    bool generarOtra = true;

    while (generarOtra) {
        // Solicitar la longitud de la contraseña al usuario
        int longitud;

        do {
            cout << "Ingrese la longitud de la contrasena (maximo 15 caracteres): ";
            cin >> longitud;

            // Verificar que la longitud sea válida
            if (longitud <= 0 || longitud > 15) {
                cout << "La longitud de la contrasena debe ser mayor que 0 y no debe exceder los 15 caracteres." << endl;
            }

        } while (longitud <= 0 || longitud > 15);

        // Permitir al usuario elegir los tipos de caracteres
        char incluirMayusculas, incluirMinusculas, incluirSimbolos;

        do {
            cout << "¿Incluir mayusculas? (S/N): ";
            cin >> incluirMayusculas;

            // Verificar si la respuesta es válida
            if (incluirMayusculas != 'S' && incluirMayusculas != 's' && incluirMayusculas != 'N' && incluirMayusculas != 'n') {
                cout << "Por favor, ingrese una opcion valida (S/N)." << endl;
            }
        } while (incluirMayusculas != 'S' && incluirMayusculas != 's' && incluirMayusculas != 'N' && incluirMayusculas != 'n');

        do {
            cout << "¿Incluir minusculas? (S/N): ";
            cin >> incluirMinusculas;

            // Verificar si la respuesta es válida
            if (incluirMinusculas != 'S' && incluirMinusculas != 's' && incluirMinusculas != 'N' && incluirMinusculas != 'n') {
                cout << "Por favor, ingrese una opcion valida (S/N)." << endl;
            }
        } while (incluirMinusculas != 'S' && incluirMinusculas != 's' && incluirMinusculas != 'N' && incluirMinusculas != 'n');

        do {
            cout << "¿Incluir simbolos? (S/N): ";
            cin >> incluirSimbolos;

            // Verificar si la respuesta es válida
            if (incluirSimbolos != 'S' && incluirSimbolos != 's' && incluirSimbolos != 'N' && incluirSimbolos != 'n') {
                cout << "Por favor, ingrese una opcion valida (S/N)." << endl;
            }
        } while (incluirSimbolos != 'S' && incluirSimbolos != 's' && incluirSimbolos != 'N' && incluirSimbolos != 'n');

        // Llamar a la función para generar la contraseña
        generarContrasena(longitud, (incluirMayusculas == 'S' || incluirMayusculas == 's'),
                                   (incluirMinusculas == 'S' || incluirMinusculas == 's'),
                                   (incluirSimbolos == 'S' || incluirSimbolos == 's'));

        // Preguntar al usuario si desea generar otra contraseña
        do {
            cout << "¿Generar otra contrasena? (S/N): ";
            cin >> respuesta;

            // Verificar si la respuesta es válida
            if (respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n') {
                cout << "Por favor, ingrese una opcion valida (S/N)." << endl;
            }
        } while (respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n');

        generarOtra = (respuesta == 'S' || respuesta == 's');
    }

    cout << "¡Gracias por usar el generador de contrasenas!" << endl;
    }




// Definición de la función para generar la contraseña
void generarContrasena(int longitud, bool incluirMayusculas, bool incluirMinusculas, bool incluirSimbolos) {
    string mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string minusculas = "abcdefghijklmnopqrstuvwxyz";
    string simbolos = "!@#$%^&*()_-+=<>?";
    string caracteresPermitidos;

    // Construir la cadena de caracteres permitidos según las preferencias del usuario
    if (incluirMayusculas) {
        caracteresPermitidos += mayusculas;
    }
    if (incluirMinusculas) {
        caracteresPermitidos += minusculas;
    }
    if (incluirSimbolos) {
        caracteresPermitidos += simbolos;
    }

    // Verificar si se ha seleccionado al menos un tipo de caracter
    if (caracteresPermitidos.empty()) {
        cout << "Error: Debes seleccionar al menos un tipo de caracter para generar la contrasena." << endl;
        return;
    }

    const int numCaracteres = caracteresPermitidos.length();

    // Inicializar la semilla para la generación de números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    // Generar la contraseña
    string contrasena;
    for (int i = 0; i < longitud; ++i) {
        int indice = rand() % numCaracteres;
        contrasena.push_back(caracteresPermitidos[indice]);
    }

    // Mostrar la contraseña generada
    cout << "Contrasena generada: " << contrasena << endl;
}
