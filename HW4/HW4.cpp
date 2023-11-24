#include <iostream>
using namespace std;

//son olarak puan hesaplaması yapan bir fonksiyon veya int getinfo içinde kod aşağıda düşündüğüm yeri  var
bool codecheck(string code) {
	if (code.length() != 4) {
		return false;
	}
	for (char letter : code) {
		if (letter != 'R' && letter != 'G' && letter != 'B' && letter != 'Y' && letter != 'P' && letter != 'M') {
			return false;
		}
	}
	for (int i = 0; i < code.length() - 1; i++) {				// son harfi iki kere kontrol etmeye gerek yok onun için length-1
		for (int j = i + 1; j < code.length(); j++) {
			if (code[i] == code[j]) {
				return false;
			}
		}
	}
	return true;
}

string feedbackcontrol(string secretcode, string guess) {
    string feedbackR, feedbackW;

    for (int i = 0; i < secretcode.length(); i++) {
        for (int j = 0; j < guess.length(); j++) {
            if (guess[j] == secretcode[i]) {
                if (i == j) {
                    feedbackR += "R";
                }
                else {
                    feedbackW += "W";
                }
            }
        }
    }
    return feedbackR + feedbackW;
}

void getinfo() {

	string player1, player2, secretcode, maker, breaker;
	cout << "Please enter the names of the players: ";
	cin >> player1 >> player2;
	cout << "Welcome " << player1 << " and " << player2 << endl<<endl;

	int totalrun = 0;
	while (totalrun <= 0 || totalrun % 2 != 0) {
		cout << "Please enter the number of runs: ";
		cin >> totalrun;

		if (totalrun <= 0 || totalrun % 2 != 0) {
			cout << "Invalid number of runs!" << endl;
		}
	}

	int player1Score = 0, player2Score = 0;
	bool breakerwins = false;
	
	//gameplay
	for (int run = 1; run <= totalrun; run++) {

		breakerwins = false;
		if (run % 2 == 1) {
			maker = player1;
			breaker = player2;
		}
		else {
			maker = player2;
			breaker = player1;
		}
	
		cout << endl << maker << ", it is your turn to select the secret!" << endl;
		cout << "Valid colors: R - Red, G - Green, B - Blue, P - Purple, Y - Yellow, M - Magenta" << endl;

		cout << maker << ", please enter your secret: ";
		cin >> secretcode;

		while (!codecheck(secretcode)) {
			cout << "Invalid secret!";
			cin >> secretcode;
			cout << endl;
			cout << maker << ", please enter your secret: ";
		}
		
		int chances = 6;
		string guess;
		cout << endl;
		while (chances > 0) {
			cout << breaker << ", please enter your guess: ";
			cin >> guess;

			if (!codecheck(guess)) {
				cout << "Invalid guess!" << endl;
			}
			else if (guess == secretcode) {
				cout << breaker << ", you won this run!" << endl;
				breakerwins = true;
				if (breaker == player1) {
					player1Score = player1Score + 1;
				}
				else {
					player2Score = player2Score + 1;
				}
				break;
				// burada break olmazsa while loopu sonsuz döner
			}
			else {
				string feedback;
				feedback = feedbackcontrol(secretcode, guess);
				chances = chances - 1;
				cout << feedback << endl;
				if (maker == player1) {
				player1Score = player1Score + 1;
				}
				else {
					player2Score = player2Score + 1;
				}
			}
		}
		if (chances == 0 || !breakerwins) {
			cout << breaker << ", you're out of chances, you lost this run!" << endl;
			if (maker == player1) {
				player2Score = player2Score + 1;
			}
			else {
				player1Score = player1Score + 1;
			}
		}
	}
	//gameplay end
	cout << endl << "The game has ended!" << endl;
		cout << player1 << ": " << player1Score << " - " << player2 << ": " << player2Score << endl<<endl;
		if (player1Score == player2Score) {
			cout << player1 << " and " << player2 << ", there is a tie!" << endl;
		}
		else if (player1Score > player2Score) {
			cout << "Congrats " << player1 << ", you have won the game!" << endl;
		}
		else {
			cout << "Congrats " << player2 << ", you have won the game!" << endl;
		}
}


int main(int argc, char const *argv[])
{
	getinfo();
	return 0;
}