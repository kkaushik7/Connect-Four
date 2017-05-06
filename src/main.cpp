# include <iostream>
# include<stdlib.h>
# include <windows.h>
# include "gameGrid.h"

using namespace std;

int main() {
	connectFour game;
	char continueGame = 'y';
	system("cls");
	game.welcome_screen();
	game.display_board();
	
	do {
		// Reset Defaults
		game.reset_game();
		// Start the game
		game.player_active = 1;
		int which_player = 0;
		game.game_over = false;
		bool is_stalemate = false; // Handle exceptions
		do {
			which_player++;
			system("cls");
			game.display_board();

			// Determine whose turn it is
			if (which_player % 2 == 1)
				game.player_active = 1;
			else
				game.player_active = 2;
			bool within7 = true;
			while (within7) {
				if (game.player_active == 1) {
					cout << game.player_one_name << " to play. Enter preference : ";
					cin >> game.player_preference;
				}	
				else if (game.player_two_name != "Computer") {
					cout << game.player_two_name << " to play. Enter preference : ";
					cin >> game.player_preference;
				}
				else {
					game.player_preference = game.computer_response();
					cout << "Computer's turn to play. Playing : " << game.player_preference;
					Sleep(500);
				}
				// Ask which column the player wants to put his disc in
				cout << endl;
				if (game.player_preference <= 7 && game.available_slot[game.player_preference-1] != -1)
					within7 = false;
				else
					cout << "Please enter a number between 1 and 7 (or) in a column with available slots" << endl;
			}
			// Update the game after this move is made
			game.update_board();
			game.update_available_slots();
			system("cls");
			game.display_board();
			// Check if the game is over or not
			game.game_over = game.is_game_over();
			if (which_player == 42 && game.game_over != true)
				is_stalemate = true;
		} while (!game.game_over && !is_stalemate);

		// Update the score of who won
		if (game.player_active == 1 && !is_stalemate)
			game.player_one_score++;
		else if (game.player_active == 2 && !is_stalemate)
			game.player_two_score++;

		system("cls");
		game.display_board();

		// Get the game results
		if (!is_stalemate) {
			// Victory message
			if (game.player_active==1)
				cout << endl << endl << game.player_one_name << " Won !!! Congratulations!!! :) " << endl << endl;
			else
				cout << endl << endl << game.player_two_name << " Won !!! Congratulations!!! :) " << endl << endl;
		}
		else {
			// Stalemate message
			cout << endl << endl << "THE GAME IS A STALEMATE!! :(" << endl;
		}
		
		cout << "Continue Game (y/n)?  :  "; cin >> continueGame; cout << endl;
	} while (continueGame == 'y');

	if (game.player_one_score + game.player_two_score >= 2) {
		if (game.player_one_score > game.player_two_score)
			cout << game.player_one_name << " won the series! " << endl << endl;
		else if (game.player_two_score > game.player_one_score)
			cout << game.player_two_name << " won the series! " << endl << endl;
		else
			cout << "The series was a tie!" << endl << endl;
	}
	return 0;
		
}

