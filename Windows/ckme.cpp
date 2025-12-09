#include <iostream>
#include <algorithm> // Para convertir a minúsculas

using namespace std;

int main()
{
    string texto;

    while (true) {
        cout << "Enter the password: ";
        getline(cin, texto);

        // Convertimos la entrada a minúsculas
        transform(texto.begin(), texto.end(), texto.begin(), ::tolower);

        if (texto == "wed") {
            cout << "Well done! Correct password" << endl;
            break; // Sale del bucle cuando la contraseña es correcta
        } else {
            cout << "Nope, try again" << endl;
        }
    }

    // Pausar la ejecución
    cout << "Press Enter to exit...";
    cin.get(); // Captura la pausa para que el usuario vea el mensaje antes de salir

    return 0;
}

