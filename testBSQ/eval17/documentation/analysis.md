

# Analysis

1. While loop iterates argv[1] 
			-> store obstructions in a list of lists each containing 2 ints representing location 
			obs_temp = **{{0, 3}, {0, 7}, {0, 9}}**
2. on each line break, append pointer to the finished list representing one row -> into an array of pointers
- in essence nesting the resulting arrays in one array ->
        obs = {{0, 3}, {0, 7}, {0, 9}}, **{1, 1}, {1, 4}}**

3. When iteration terminates at '\0' we have all of the obs.

4. Find the potential square up-left corners. **pot**

1	Choose the squares that are are (x+1, y+1) from obstacles

2	choose  the ones that are at a northwest crossroad from straight lines from the red squares
			(but for each line –none after if we encounter an obstacle on the normal path which is closer or as far
			to the path than how far the path has travelled since its beginning)
			(also line stops if it hits an obstacle)
	These are the only possible spots for the upper left corner
	of the biggest square

		There’s still room to optimize this by somehow checking for some of the exceptional squares
3	and the ones that hit a wall to the north or south of the already chosen squares
4	And the first square of the grid
			
5	And every square directly under or to the right of an obstacle


5. Iterate through **pot**s and find the first **obs** with 

6. 

