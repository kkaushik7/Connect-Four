# include <iostream>
# include<stdlib.h>
# include <windows.h>
# include "gameGrid.h"

using namespace std;

//Sleep(2000);
//system("cls");

int main() {
	connectFour game;
	system("cls");
	game.display_board();
	
	// Start the game
	game.player_active = 1;
	int which_player = 0;
	game.game_over = false;
	bool is_stalemate = false; // Handle exceptions

	do{
		which_player++;
		system("cls");
		game.display_board();
		
		// Determine whose turn it is
		if (which_player % 2 == 1)
			game.player_active = 1;
		else
			game.player_active = 2;
		cout << "Player " << game.player_active << " to play. Enter preference : ";
		// Ask which column the player wants to put his disc in
		cin >> game.player_preference;
		cout << endl;
		// Update the game after this move is made
		game.update_board();
		game.update_available_slots();
		system("cls");
		game.display_board();
		// Check if the game is over or not
		game.game_over = game.is_game_over();
		if (which_player == 42 && game.game_over != true)
			is_stalemate == true;
	} while (!game.game_over && !is_stalemate);

	// Get the game results
	if (!is_stalemate) {
		// Victory message
		cout << endl << endl << "PLAYER " << game.player_active << " WON !!! CONGRATULATIONS!!! :) " << endl << endl;
	}
	else {
		// Stalemate message
		cout << endl << endl << "THE GAME IS A STALEMATE!! :(" << endl;
	}
	return 0;
		
}

