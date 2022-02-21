# CS50 Final Project
#### Video Demo:  <URL https://youtu.be/z9auDTCAd6M>

## Tic-Tac-Toe Game


This game has always been my favourite since childhood and I am soo proud that I am able to create it on my own. It took me roughly 1 week to create it and I am very proud of it.

## Description

Tic-tac-toe is played on a three-by-three grid by two players, who alternately place the marks X and O in one of the nine spaces in the grid.

When considering only the state of the board, there are only 138 terminal board positions. A combinatorics study of the game shows that when "X" makes the first move every time, the game outcomes are as follows:

91 distinct positions are won by (X),
44 distinct positions are won by (O) and
3 distinct positions are drawn.

## Summary & Technology used:

1. Python Programming Language

2. Used a class to have all the methods in one place. It can easily be a reusable bundle in some other code as well.

3. Defined different functions for each responsibility, even if it is a small task. It helps to maintain the code with ease.


### Steps taken when creating the game:

1. Create a board using a 2-dimensional array and initialize each element as empty.
2. I can represent empty using any symbol you like. Here, we are going to use a hyphen.'-'.
3. Write a function to check whether the board is filled or not.
4. Iterate over the board and return false if the board contains an empty sign or else return true.
5. Write a function to check whether a player has won or not.
7. Check for all the rows, columns, and two diagonals.
8. Write a function to show the board as I will show the board multiple times to the users while they are playing.
9. Write a function to start the game.
10. Select the first turn of the player randomly.
11. Write an infinite loop that breaks when the game is over (either win or draw).
12. Show the board to the user to select the spot for the next move.
13. Ask the user to enter the row and column number.
14. Update the spot with the respective player sign.
15. Check whether the current player won the game or not.
16. If the current player won the game, then print a winning message and break the infinite loop.
17. Next, check whether the board is filled or not.
18. If the board is filled, then print the draw message and break the infinite loop.
19. Finally, show the user the final view of the board.



## Usage

# starting the game


```python

tic_tac_toe = TicTacToe()
tic_tac_toe.start()


    def __init__(self):
        self.board = []


   def create_board(self):
        for i in range(3):
            row = []
            for j in range(3):
                row.append('-')
            self.board.append(row)

    def get_random_first_player(self):
        return random.randint(0, 1)

    def fix_spot(self, row, col, player):
        self.board[row][col] = player

    def is_player_win(self, player):
        win = None

    def is_board_filled(self):
        for row in self.board:
            for item in row:
                if item == '-':
                    return False
        return True

   def swap_player_turn(self, player):
        return 'X' if player == 'O' else 'O'

    def show_board(self):
        for row in self.board:
            for item in row:
                print(item, end=" ")
            print()

   def start(self):
        self.create_board()
```

# THANK YOU AND HOPE YOU ENJOY THE GAME

