# Mapia_Game

Mapia_Game is an interactive game project that appears to simulate a strategic guessing game. The game includes multiple characters and features, offering an engaging experience for the players.

The project includes source files written in C. You need a C compiler like `gcc` to build the project.

## File Structure
```plaintext
Mapia_Game
├── CDotcom
│   ├── DArrayList.c          # Dynamic Array List Implementation (C Source)
│   ├── DArrayList.h          # Dynamic Array List Implementation (Header)
│   ├── DotCom.c              # DotCom Game Logic (C Source)
│   ├── DotCom.h              # DotCom Game Logic (Header)
│   ├── DotComBust.c          # Main Game Functions (C Source)
│   ├── DotComBust.h          # Main Game Functions (Header)
│   ├── GameHelper.c          # Helper Functions for Game Logic (C Source)
│   ├── GameHelper.h          # Helper Functions for Game Logic (Header)
│   ├── SArrayList.c          # Static Array List Implementation (C Source)
│   ├── SArrayList.h          # Static Array List Implementation (Header)
│   └── game_menu.c           # Game Menu Implementation (C Source)
└── Project Files
    ├── CDotcom.sln           # Solution File
    ├── CDotcom.VC.db         # Database File
    └── CDotcom.sdf           # SQL Server Compact Database File
```

## Game Mechanics
### Characters and Initialization:
The game involves initializing several characters (DotCom), which are managed through dynamic memory allocation. Each character is given a specific name based on the game state.

### Game Play:
The main gameplay involves a series of guesses. The game reads saved data if available and continues until the player completes the required actions

### Saving and Loading:
The game supports saving the current state to a file (savedata.txt) and loading from it, allowing players to resume from where they left off.

## Additional Functions
### Display Grid:
The game includes a function to print a visual grid representing the game state.

### Top Rank:
The game keeps track of top ranks and displays them.

### Work and Guess Count:
Functions to display the current character’s work and the number of guesses.
