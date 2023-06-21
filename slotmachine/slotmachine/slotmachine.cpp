#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displaySlotMachine(const char* items[]) {
    cout << "-------------------------" << endl;
    cout << "| " << items[0] << " | " << items[1] << " | " << items[2] << " |" << endl;
    cout << "-------------------------" << endl;
}

bool checkWin(const char* items[], int userChoice) {
    return (items[0] == items[1] && items[1] == items[2] && items[2] == items[userChoice]);
}

int main() {
    const char* items[] = { "Cherry", "Seven", "Bell" };
    int userChoice, programChoice;
    char playAgain;

    // Rastgele sayı üretmek için zamanı kullan
    srand(static_cast<unsigned int>(time(0)));

    do {
        cout << "Welcome to the Slot Machine Game!" << endl;
        cout << "Choose one item from the following options:" << endl;
        cout << "1. Cherry" << endl;
        cout << "2. Seven" << endl;
        cout << "3. Bell" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> userChoice;

        // Geçersiz seçimleri kontrol et
        while (userChoice < 1 || userChoice > 3) {
            cout << "Invalid choice! Please enter a number between 1 and 3: ";
            cin >> userChoice;
        }

        programChoice = rand() % 3;  // Programın seçimini rastgele belirle

        displaySlotMachine(items);
        cout << "You chose: " << items[userChoice - 1] << endl;
        cout << "Program chose: " << items[programChoice] << endl;

        if (checkWin(items, userChoice - 1)) {
            cout << "Congratulations! You won!" << endl;
        }
        else {
            cout << "Sorry, you lost. Better luck next time!" << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        // Oyun yeniden başlatılsın mı kontrol et
        if (playAgain == 'y' || playAgain == 'Y') {
            cout << "------------------------" << endl;
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing the Slot Machine Game!" << endl;

    return 0;
}
