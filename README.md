Lab06
=====
- Elliott Plack
- 12 OCT 2013
- COSC 501 @ Towson University

## Problem
Two functions: One computes factorials between 1 and 8, the other draws triangles with asterisks * based on user input.

## Algorithm
Use a switch case to give the user the option to pick which function to do. 

### Factorials
Input in the main with logic checks to decide if the input is valid and within the range. Calculate the result in a separate function with the formula `x *= i` in a for loop. Set the initial value equal to a temporary variable that will control how many times the loop should run. return result back to the main and output.

###Triangles
Input in the main the number of triangles and the number of stars to have on the last row. Validate inputs in the main and send the results to the triangle drawing function, which will be a void function. in the void triangles function, do two nested loops, one for the number of triangles, and one for the number of stars. The first loop will have a check to see if it should ask how many stars before repeating.
