# Hex-playing AI

A simple, yet powerful, Hex simulator.


### Installing

Download source code by typing:

```
git clone https://github.com/cMrzrs/Hex-playing-AI.git
```


### Compilation

Give the ``` make ``` command while in the directory *~/Hex-playing-AI/*


## Running 

Type:

```
cd build

./hex_game
```
Be sure to read the guide below on how to play the game through the command line. =)


### Clean

While being in *~/Hex-playing-AI/* directory, delete all objects files and executable by typing:   

```
make clean
```


### Some info about the board game: Hex

Hex is a strategy board game for two players, black and white, played on a hexagonal grid, usually the size of 11x11. 
White plays first. 
Players alternate placing markers on unoccupied spaces in an attempt to link their opposite sides of the board in an 
unbroken chain. 
The first played to do so, wins. There are no draws in Hex.

More about Hex can be found here: https://en.wikipedia.org/wiki/Hex_(board_game)


## How to play & available commands

### Command line
You can give the following commands in the command line:

-n <size> : Sets the size of the grid. If no option is given, the default size is 11. Acceptable size values vary in the range [4,26].

-d <difficulty> : Sets the difficulty of the game. The default difficulty is 1.

-b : Sets human as the black player. Human's default color is white.

-s : Enables the swap rule. The swap rule is disabled by default. [RULES](https://en.wikipedia.org/wiki/Hex_(board_game)#Rules). 

An example command to begin a game of Hex is: ./hex -n 7 -d 5 -b -s


### During gameplay
You can give the following commands while the game is running:

• newgame  \[white|black\[swapoff|swapon \[\<size>]]]

Starts a new game based on the parameters given. The 1st parameter sets the player's color, the 2nd whether the swap rule 
is on/off and the 3rd the size of the game. 
Note that there should always be either all or none of the parameters. 

• play <move>

User performs said <move>. 
Note that acceptable moves are of the format "CN" where C is a Capital letter and N a number. F.i. D4 is an acceptable move, whereas d4 isn't. 

• cont

AI makes a move.

• level <difficulty>

Sets the difficulty level to <difficulty>.

• swap

If the swap rule is on, performs the swap move for the user.

• save <statefile>
  
Saves the current state of the game in the file <statefile>.

• load <statefile>
  
Loads the state of the game saved in the file <statefile>.

• showstate

Prints the current game state.

• quit

Exits the program.


Important note: As of the current release, every command related to the game's difficulty will not have any actual effect to the game. 
That's because it was designed to participate in a competition, thus there was no need for difficulties other than the maximum. 
This issue will be fixed in later updates. :]

Unimportant note: UNDO and SUGGEST commands will be added in later versions.


## About
- Based on a project assigned by [prof. Stamatopoulos](http://cgi.di.uoa.gr/~takis/Welcome.html), dept. of Informatics and Telecommunications, NKUA.
- Won the department's local competition.


## Authors
- [Charalampos Maraziaris](https://github.com/cMrzrs)
- [Konstantinos Tsikouris](https://github.com/superlink2013)
