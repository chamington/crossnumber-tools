# crossnumber-tools
 Tools for working on chalkdust magazine's crossnumber puzzles

### init.cpp
 This reads a board.csv file, which should contain each placement (such as 1A, 2D, 14A, 12D, etc) with the digits next to them, and creates a folder with files that contain each possible answer

### parsing.h
 Mainly I/O tool, but has a function for printing the set and protection against the program deleting a set of size 1 (which should not happen)

### permutations.cpp 
 Multiplies the number of possible answers for each placement. Not really useful but cool to see and it's what I used to show it was completed
 
### submission.cpp
 Sums up the across answers, which is what is used to submit your answer
 
### crosscomp/crosscomp.h
 Tool for filtering possibilities that cannot co-exist given the nature of the numbers being crossed. I wrote a main for this that was specified for crossnumber14. Having it parse a csv that contains the placements and digit where they cross probably would have been better for a generic open source code, but having already submitted my answer, I don't really have much motivation to do so lol
