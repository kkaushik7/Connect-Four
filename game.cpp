# include <iostream>
# include <windows.h>
# include <stdlib.h>
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
	player_one_score = 0;
	player_two_score = 0;
}

// The Welcome Screen
void connectFour::welcome_screen() {
	system("cls");
	cout << "\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "\t\t\t$$                                          $$" << endl;
	cout << "\t\t\t$$              CONNECT FOUR                $$" << endl;
	cout << "\t\t\t$$                                          $$" << endl;
	cout << "\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << endl << endl << endl;
	cout << "\tConnect four characters horizontally, vertically or diagonally to win the game" << endl << endl;
	cout << "\tAn implementation by Kaushik, Kailash and Tarun " << endl << endl;
	cout << "\tINSTRUCTIONS" << endl << endl;
	cout << " \t\t 1. Use keyboard to play" << endl;
	cout << " \t\t 2. Enter input using numbers 1-7" << endl;
	cout << " \t\t 3. Press 'y' at the end of each game to play a series of matches" << endl;
	cout << " \t\t 4. Press 'n' at the end of a game to end a series of matches" << endl;
	cout << " \t\t 5. Press Ctrl+C to exit the game at any point" << endl;
	cout << endl;
	cout << "How many players (1 or 2)? : "; cin >> num_players; cout << endl;
	if (num_players == 2) {
		cout << "Player 1 name : "; cin >> player_one_name; cout << endl;
		cout << "Player 2 name : "; cin >> player_two_name; cout << endl;
	}
	else {
		cout << "Player name : "; cin >> player_one_name; cout << endl;
		player_two_name = "Computer";
	}
}

// Reset the game after every round
void connectFour::reset_game() {
	for (int i = 0; i < 7; i++) {
		available_slot[i] = 5;
	}
	player_active = 1;
	game_over = false;
	initialize_board(); // Initialize the board
	player_preference = -1;
}

// Display the board
void connectFour::display_board() {
	cout << "\t\t\t$**********************$" << endl;
	cout << "\t\t\t$     CONNECT FOUR     $" << endl;
	cout << "\t\t\t$**********************$" << endl << endl;
	cout << "\t " << player_one_name << " : " << player_one_score << "\t\t\t";
	cout << player_two_name << " : " << player_two_score << endl << endl;
	cout << '\t';
	for (int k = 1; k <= 7; k++)
		cout << "  " << k << "  " << '\t';
	cout << endl;
	// The print line routine
	cout << '\t';
	for (int k = 1; k <= 7; k++)
		cout << "+---+" << '\t';
	cout << endl;
	for (int i = 0; i < 6; i++) {
		cout << 1 + i << '\t';
		for (int j = 0; j < 7; j++) {
			cout << "| " << board[i][j] << " |" << '\t';
		}
		cout << endl;
		// The print line routine
		cout << '\t';
		for (int k = 1; k <= 7; k++)
			cout << "+---+" << '\t';
		cout << endl;
	}
}
// Update the slot available to be filled in every column
void connectFour::update_available_slots() {
	--available_slot[player_preference-1];	
}

// Generate the computer response
int connectFour::computer_response() {
	bool correct = true;
	int resp;
	while (correct) {
		resp = rand() % 6 + 1;
		if (available_slot[resp] != -1) {
			return resp;
			correct = false;
		}
	}
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
	int j = player_preference - 1;    //current column
	int i = available_slot[j] + 1;    //current row
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



