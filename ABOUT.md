# BIN_GAME

## General options of the game
 - `BOARDS_SIZE` Size of game board;

    It's a linear option (it's equal to one side of the board).
    The default is 10.

 - `SCORE` Sum of all the numbers on the board at the moment;
 - `MOVES_NUMBER` Current number of moves

## Game modes

 - Win mode
 - Time mode
 - Score mode

### Defeat (for all the game modes)

```
You can't make any move:
there are no NEIGHBORING EQUAL numbers on the board
```

### Win mode

Before playing in this mode you need to specify a special
option named WIN_NUMBER. It's just a score you need to
win.


#### Victory condition

```
SCORE >= WIN_NUMBER
```

### Time mode

You need to specify TIME_NUMBER (min) before the beginning
of the game in this mode. You will play within the
specified time.

#### Victory condition

```
Do not lose the game for the specified time
```

### Score mode

The game continues until losing.

#### Victory condition

```
You can't win in this mode
```
