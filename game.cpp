# include <iostream>
# include "gameGrid.h"

using namespace std;

// Initialize the game board
void connectFour::initialize_board() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			board[i][j] = empty;
		}
	}
}

// The constructor
connectFour::connectFour() {
	player_active = 1;
	game_over = false;
	initialize_board(); // Initialize the board
	player_preference = -1; // The column where every player wants to put his coin in
}

// Display the board
void connectFour::display_board() {
	cout << "CONNECT FOUR - Connect four characters horizontally, vertically or diagonally to win!!" << endl;
	cout << '\t';
	for (int k = 1; k <= 7; k++)
		cout << k << '\t';
	cout << endl;
	for (int i = 0; i < 6; i++) {
		cout << 1+i << '\t';
		for (int j = 0; j < 7; j++) {
			cout << board[i][j] << '\t';
		}
		cout << '\n'<<endl;
	}
}

// Update the slot available to be filled in every column
void connectFour::update_available_slots() {
	--available_slot[player_preference-1];	
}

// Update the board after every move
void connectFour::update_board(){
	int col = player_preference - 1;
	int row = available_slot[col];
	if (player_active == 1)
		board[row][col] = player_one;
	else
		board[row][col] = player_two;
}

// Check for 4 consecutive elements horizontally
bool connectFour::check_horizontal() {
	int j = player_preference - 1;    //current row
	int i = available_slot[j] + 1;    //current column
	char check;
	if (player_active == 1) {
		check = player_one;
	}
	else {
		check = player_two;
	}
	// Search Right
	if (j <= 3) {
		if (board[i][j] == check && board[i][j+1] == check && board[i][j+2] == check && board[i][j+3] == check)
			return true;
	}
	// Search Left
	if (j >= 3) {
		if (board[i][j] == check && board[i][j-1] == check && board[i][j-2] == check && board[i][j-3] == check)
			return true;
	}
	return false;
}

// Check for 4 consecutive elements vertically
bool connectFour::check_vertical() {
	int j = player_preference - 1;  //current row
	int i = available_slot[j] + 1;  //current column
	char check;
	if (player_active == 1) {
		check = player_one;
	}
	else {
		check = player_two;
	}
	// Search Up
	if (i >= 3) {
		if (board[i][j] == check && board[i-1][j] == check && board[i-2][j] == check && board[i-3][j] == check)
			return true;
	}
	// Search Down
	if (i <= 2) {
		if (board[i][j] == check && board[i+1][j] == check && board[i+2][j] == check && board[i+3][j] == check)
			return true;
	}
	return false;
}

// Check for 4 consecutive elements diagonally
bool connectFour::check_inclined() {
	int j = player_preference - 1;   //current row
	int i = available_slot[j] + 1;   //current column
	char check;
	if (player_active == 1) {
		check = player_one;
	}
	else {
		check = player_two;
	}
	if (i >= 3 && j <= 3) { // Check Northeast
		if (board[i][j] == check && board[i-1][j+1] == check && board[i-2][j+2] == check && board[i-3][j+3] == check)
			return true;
	}

	if (i >= 3 && j >= 3) { // Check Northwest
		if (board[i][j] == check && board[i - 1][j - 1] == check && board[i - 2][j - 2] == check && board[i - 3][j - 3] == check)
			return true;
	}

	if (i <= 2 && j <= 3) { // Check Southeast
		if (board[i][j] == check && board[i + 1][j + 1] == check && board[i + 2][j + 2] == check && board[i + 3][j + 3] == check)
			return true;
	}

	if (i <= 2 && j >= 3) { // Check Southwest
		if (board[i][j] == check && board[i + 1][j - 1] == check && board[i + 2][j - 2] == check && board[i + 3][j - 3] == check)
			return true;
	}
	return false;
}


// Check if the game is over or not
bool connectFour::is_game_over() {
	if (check_horizontal() == true || check_vertical() == true || check_inclined() == true) {
		return true;
	}
	else {
		return false;
	}
}



