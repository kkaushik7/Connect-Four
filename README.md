Implementation of the [Connect Four](https://en.wikipedia.org/wiki/Connect_Four) game in C++    

Team Members    
-----     
    
  *Kaushik Krishnan     
  *Tarun Giri     
  *Kailash Sridhar    
  
*Note*: This code works only in a Windows Operating System as it uses the header file *<Windows.h>*    


Rules of the game    
-----     
This is a two player game. Players turns dropping colored discs from the top into a seven-column, six-row vertically suspended grid. The pieces fall straight down, occupying the next available space within the column. The objective of the game is to be the first to form a horizontal, vertical, or diagonal line of four of one's own discs. Here instead of discs, we use '*' for player 1 and 'o' for player 2.

gameGrid.h    
------      
This header file contains the definition of the game class *connectFour*    

game.cpp    
------      
This file contains the function definitions for the class *connectFour*    


main.cpp    
------      
This code contains the algorithm for the code


When you start the game, there will be a welcome screen. The game can be played by a single player or 2 players. If single, computer plays the role of the 2nd player