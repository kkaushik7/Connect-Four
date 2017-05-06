#pragma once

# include <iostream>
# include <string>

using namespace std;

class connectFour {
public:
	int player_active;                         // The player who is currently active
	bool game_over;                            // Logical Variable to know if game ended or not
	char board[6][7];                          // The game board
	int player_preference;                     // The column where every player wants to put his coin in
	int available_slot[7] = { 5,5,5,5,5,5,5 }; // Contains the available slot for every column
	string player_one_name, player_two_name;
	int player_one_score, player_two_score;
	int num_players;

	// Game Constants
	const char empty = ' ';       // Empty State in the Grid
	const char player_one = '*';  // Player 1's symbol
	const char player_two = 'o';  // Player 2's symbol

	// Member functions
	connectFour();                 // Constructor
	void welcome_screen();         // The Welcome Screen
	void initialize_board();       // Initialize an empty game board
	void display_board();          // Display the board after every move
	void reset_game();             // Reset the gamer after every round
	int computer_response();      // Get the computer response
	void update_available_slots(); // Update the available slots array
	void update_board();           // Update the board after every move
	bool check_horizontal();       // Check for 4 consecutive elements horizontally
	bool check_vertical();         // Check for 4 consecutive elements horizontally
	bool check_inclined();         // Check for 4 consecutive elements diagonally
	bool is_game_over();           // Check if game is over or needs to be continued
};
