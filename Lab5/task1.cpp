#include <iostream>
#include <ctime>
using namespace std;

class Game{
    int guess, tPlayers, cPlayer;

public:
    Game(int p) {
        srand((unsigned)time(0)); 
        guess = 1 + rand() % 100;
        cout<<guess<<endl;
        tPlayers = p;
        cPlayer = 1;
    }
    void start() {
        cout << "Guess a number between 1 and 100" << endl;
        playTurn();
    }
    void playTurn() {
        int pGuess;
        cout << "Player " << cPlayer << " 's turn: ";
        cin >> pGuess;

        if (pGuess == guess) {
            cout << "Yayyyyyyyyyyyyyyyy! Player " << cPlayer << " wins!!!!!!!!!!!\n";
            return;
        } else if (pGuess < guess) {
            cout << "Too low!!!"<< endl;
        } else {
            cout << "Too high!!!"<<endl;
        }

        cPlayer = (cPlayer % tPlayers) + 1;
        playTurn();
    }
};
int main() {
    Game guess(2);
    guess.start();
    return 0;
}
