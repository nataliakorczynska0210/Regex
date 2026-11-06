#include <iostream>
#include <string>
#include "regrex.h"

using namespace std;
// !!!Inicjuje program, pobiera dane wejściowe i uruchamia proces dopasowywania wzorca.
int main() {
    cout << "Sprawdzanie wyrazen regularnych (wpisz 'exit' aby zakonczyc)\n\n";

    while (true) {
        string pattern, text;
        // Etap 1: Pobieranie wzorca
        cout << "Podaj wyrazenie regularne: ";
        if (!getline(std::cin, pattern) || pattern == "exit") break;

        try {
            // Etap 2: Tworzenie automatu
            regex re(pattern); // Wykorzystuje konstruktor regex::regex żeby przetworzyć wzorzec i przygotować automat do dopasowywania.
            // Etap 3: Pobieranie tekstu 
            std::cout << "Podaj tekst: ";
            if (!getline(std::cin, text)) break;
            // Etap 4: Weryfikacja
            bool czy_pasuje = re.matches(text); // Wykorzystuje funkcję matches() z pliku podstawy_regrex.cpp
            string wynik = czy_pasuje ? "PASUJE " : "NIE PASUJE";

            cout << "-> " << wynik << "\n\n";
            
        } catch (const std::exception& e) {
            cout << "Niepoprawne wyrazenie : " << e.what() << "\n\n";
        }
    }
    // !!!Funkcja ta istnieje aby stanowić główny interfejs
    cout << "Zakonczono testy.\n";
    return 0;
}
