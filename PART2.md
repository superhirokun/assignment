# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtu.be/OHFaf16AavY).

## Minimum Requirements

### Completed

List all the features completed.

1. Game board
2. Game objects
3. Game attribute
4. Alien movement & attack
5. zombie movement & attack
6. Multiple Zombies
7. Game control
8. Game flow(somewhat)

### To Do

1. File save and load
2. Fix the changing arrow's direaction
3. Fix the arrows when it near the border

## Contributions

Yap Choo Kath Moon

1. Randomly generate game board based on user input.
2. Randomly generate the game object
3. Added alien to the centre of the board
4. randomize the zombies stats
5. moving the alien on the board based on user input
6. and let the alien move continueuosly
7. randomized the zombies spawn location and placing them on the board
8. checking if the alien hit the rock or border and stoping it when it did
9. append the intialized zombies states into a 2d vector so that it can be used later
10. make the zombies move toward the alien
11. create healthpack that heal alien
12. create the rock object where when the alien it break the rock and become other game
13. create the pod object to damage the zombies
14. create the game menu
15. create the arrow object but it is very buggy
16. create a function that change the direaction of the arrows but it does not work
17. create a game flow that may or may not work(have yet to test it)
18. create a function that change the trail '.' into other game objects

Fu ke yun

1. Trying to do the game object but failed and can't be implement into the program.
2. Trying to do the turn-based system but failed and can't be implement into the program.
3. Trying to do the File saving and loading feature but failed and can't be implement into the program.
4. Do the game menu outside the program and didn't implement it into the program

## Problems Encountered & Solutions

1. arrow causes the program to crash/ fixing it require a checking feature to check if it the x or y becomes negative or the if the alien hit the border.
2. changing arrow direactions/ fixing it requires rewriting the entire function since at the current stage it simply does not work
3. overlaping of zombies and alien in speacific condiation, thou in most situation this problem does not occur but this may occur when the alien use the arrow object/ fixing it need to reexamine the code speacially after the alien use the arrow.
4. alien going pass the border after using the arrow/ fixing it requires the rewriting some part of arrow function.
