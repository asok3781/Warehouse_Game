/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/* Aaron Song, ason720, 492902386 */

#include "project.h"

/*
This function takes the minutes of the time to seconds and adds it to the seconds of the time, 
then finds the absolute difference between the two times to find the time worked
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB) 
{
	int worktime;
	worktime = (minuteB * 60 + secondB) - (minuteA * 60 + secondA); /*finding the difference between the times*/
	if (worktime < 0) { /*making difference positive if it is negative*/
		worktime = worktime * -1;
	}
	return worktime;
}

/*
This function finds the largest prime number below a specified maximum input by dividing the numbers below the maximum, 
from large to small, and seeing if they divide by any number apart from itself and 1 (i.e. from 2 to number - 1)
*/
int WarehouseAddress(int maximum)
{
	int i, j, isprime, prime;
	for (i = maximum - 1; i >= 2; i--) { /*going through each number below the maximum from largest to smallest*/
		isprime = 1; /*set boolean variable to true for each*/
		for (j = 2; j < i; j++) {
			if (i % j == 0) { /*if the number divides by any number apart from 1 and itself, set boolean variable to false*/
				isprime = 0;
			}
		}
		if (isprime) { /*if number is prime stop the for loop and set variable to the prime number*/
			prime = i;
			break;
		}
	}
	return prime;
}

/*
This function shifts every character in a char array to the left 1, and moves the first value to the end of the array,
by finding the new index of the character from the  remainder of the character index in the array + 1, 
when divided by the length and swapping the values of the character index and the index calculated from the reminader.
*/
void Advertise(char *words)
{
	int length = strlen(words); 
	for (int i = 0; i < length - 1; i++) { /*run for the whole character array*/
		int temp = words[i]; /*store character that is to be shifted to the left*/
		words[i] = words[i + 1 % length]; /*find the new index by finding the remainder of the character index + 1 and swap character values*/
		words[(i + 1) % length] = temp;
	}
}

/*
This function finds the lowest unique bid from an array of values. A unique value is first found to be used as a starting point. 
If a unique value is not found then -1 is returned. Otherwise, after a unique value is found, every unique value is found and compared
the unique value found to find the smallest unique value.
*/
int WinningBid(int *values, int length)
{
	int i, j, count, single = -1, winner;
	for (i = 0; i < length; i++) {
		count = 0;
		for (j = 0; j < length; j++) {
			if (values[i] == values[j]) {
				count++; /*count the amount of times a value appears in a given array*/
			}
		}
		if (count == 1) { /*value should only appear once if it is unique*/
			single = i; /*set a variable to be the position of the first unique value*/
			break;
		}
	}
	if (single == -1) {
		return -1; /*if a unique value is not found return -1*/
	}
	else {
		winner = values[single]; /*set a variable to be the first unique value*/
		for (i = 0; i < length; i++) {
			count = 0;
			for (j = 0; j < length; j++) {
				if (values[i] == values[j]) {
					count++; /*count the amount of times a value appears in a given array*/
				}
			}
			if (count == 1) { 
				if (winner > values[i]) { /*find unique values and compare to to find the smallest unique value*/
					winner = values[i]; 
				}
			}
		}
	}
	return winner;
}

/*
This function designs a box, and marks the centre of the box with Xs, given a width and height, returning the box design in a string. 
A box is first drawn to the specified with and height and then the position of the Xs are calculated. 1, 2, or 4 Xs are drawn depending
if the height of the box is even or odd. The position of the Xs is calculated by finding the position of the Xs, 1 row before it and then finding
the required positions to get to the middle of the box. The position of the end of the line before the line of the Xs is found by multiplying 
half of the height of the box minus 1 and the width of the box + 1, to account for the new line characters used to form the box. 
The middle of the box is then the position calculated + half the width (or width -1, depending if 2 Xs are to be drawn).
*/
void BoxDesign(char *design, int width, int height)
{
	int i, j, count = 0, xpos;
		for (i = 0; i < width; i++) {
			design[count] = '*'; /*draw first line of box*/
			count++;
		}
		design[count] = '\n';
		if (height >= 2) { /*for the case where no bottom line is needed, i.e. when height is 1*/
			if (width > 1) {
				for (j = 0; j < height - 2; j++) {
					count++;
					design[count] = '*'; /*drawing the sides of the box*/
					count++;
					for (i = 0; i < width - 2; i++) {
						design[count] = ' ';
						count++;
					}
					design[count] = '*';
					count++;
					design[count] = '\n';
				}
				count++;
			}
			else { /*for the case where width is one, no second column is needed*/
				for (j = 0; j < height - 2; j++) {
					count++;
					design[count] = '*';
					count++;
					design[count] = '\n';
				}
				count++;
			}
			for (i = 0; i < width; i++) {
				design[count] = '*'; /*draw last line of box*/
				count++;
			}
			design[count] = '\n';
		}
		if (height > 2 && width > 2) { /*for the cases where no Xs are drawn*/
			if (height % 2 == 0) { /*if the height is even 2 Xs are drawn on top of each other*/
				if (width % 2 == 0) { /*if the width is even 2 Xs are drawn side by side*/
					xpos = (height / 2 - 1) * (width + 1) + (width / 2 - 1); /*calcuation for position of Xs*/
					design[xpos] = 'X';
					design[xpos + 1] = 'X';
					xpos += (width + 1);
					design[xpos] = 'X';
					design[xpos + 1] = 'X';
				}
				else if (width % 2 == 1) {
					xpos = (height / 2 - 1) * (width + 1) + (width / 2);
					design[xpos] = 'X';
					xpos += (width + 1);
					design[xpos] = 'X';
				}
			}
			else if (height % 2 == 1) {
				if (width % 2 == 0) {
					xpos = (height / 2) * (width + 1) + (width / 2 - 1);
					design[xpos] = 'X';
					design[xpos + 1] = 'X';
				}
				else if (width % 2 == 1) {
					xpos = (height / 2) * (width + 1) + (width / 2);
					design[xpos] = 'X';
				}
			}
		}
}

/*
This function finds a route for a worker to a box, given an array with a worker value and and box value. 
The position of the worker and the box is first found, then the a route is found, first moving left or right, then up or down.
The required left to right distance is found by finding the difference between the column positions of the worker and box.
The up down distance is foudn by finding the difference between the row positions. The route is then drawn from the worker to the box in the array.
*/
void WorkerRoute(int warehouse[10][10])
{
	int i, j, workerrow, workercol, boxrow, boxcol, colshift, rowshift;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == 1) { /*finding positions of worker and box*/
				workerrow = i;
				workercol = j;
			}
			if (warehouse[i][j] == 2) {
				boxrow = i;
				boxcol = j;
			}
		}
	}
	colshift = boxcol - workercol; /*calculating distance left to right between worker and box*/
	rowshift = workerrow - boxrow; /*finding up down distance between worker and box*/
	if (rowshift == 0) { /*for the case that there is no shift in up down position*/
		if (colshift > 0) {
			for (i = workercol + 1; i <= workercol + colshift - 1; i++) { /*drawing left to right route*/
				warehouse[workerrow][i] = 3;
			}
		}
		else if (colshift < 0) {
			for (i = workercol - 1; i >= workercol + colshift + 1; i--) {
				warehouse[workerrow][i] = 3;
			}
		}
	}
	else {
		if (colshift > 0) {
			for (i = workercol + 1; i <= workercol + colshift; i++) { /*drawing left to right route*/
				warehouse[workerrow][i] = 3;
			}
		}
		else if (colshift < 0) {
			for (i = workercol - 1; i >= workercol + colshift; i--) {
				warehouse[workerrow][i] = 3;
			}
		}
		if (rowshift < 0) {
			for (i = workerrow + 1; i < workerrow - rowshift; i++) { /*drawing up down route*/
				warehouse[i][boxcol] = 3;
			}
		}
		else if (rowshift > 0) {
			for (i = workerrow - 1; i > workerrow - rowshift; i--) {
				warehouse[i][boxcol] = 3;
			}
		}
	}

}

/*
This function makes moves a worker (or worker and box), given a move of w, a, s, or d for up, left, down, and right. When given a move, the values of the array are changed to represent the move. 
For each move there are 12 possibilites where a move is valid: a worker moving into a space, a worker moving onto a target, a worker pushing a box into an empty space, a worker pushing a box onto a target,
a worker pushing a box off a target into a space, a worker pushing a box off a target onto another target, and these 6 possibilites for if the worker was on a target. A unique value has been used to represent a worker on a target
and a box on a target as if the box is moved off the target, the target is to be displayed. The changing of values is done through if statements, running through each possibility for each move. 
The function will return one when the all targets have boxes on them and when a worker is on a target.
*/
int MakeMove(int warehouse[10][10], char move)
{
	int i, j, workerrow, workercol, jobfinished = 1;
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				if (warehouse[i][j] == WORKER||warehouse[i][j] == WORKER_ON_TARGET) {
					workerrow = i;
					workercol = j;
				}
			}
		}
		if (move == 'w') {
			if (warehouse[workerrow][workercol] == WORKER) { /*value changes for a worker moving into a space*/
				if (warehouse[workerrow - 1][workercol] == SPACE) {
					warehouse[workerrow - 1][workercol] = WORKER;
					warehouse[workerrow][workercol] = SPACE;
				}
				else if (warehouse[workerrow - 1][workercol] == TARGET) { /*value changes for a worker moving onto a target*/
					warehouse[workerrow - 1][workercol] = WORKER_ON_TARGET;
					warehouse[workerrow][workercol] = SPACE;
				}
				else if (warehouse[workerrow - 1][workercol] == BOX) { /*value changes for a worker pushing a box*/
					if (warehouse[workerrow - 2][workercol] == SPACE) { /*into a space*/
						warehouse[workerrow - 2][workercol] = BOX;
						warehouse[workerrow - 1][workercol] = WORKER;
						warehouse[workerrow][workercol] = SPACE;
					}if (warehouse[workerrow - 2][workercol] == TARGET) { /*onto a target*/
						warehouse[workerrow - 2][workercol] = BOX_ON_TARGET;
						warehouse[workerrow - 1][workercol] = WORKER;
						warehouse[workerrow][workercol] = SPACE;
					}
				}
				else if (warehouse[workerrow - 1][workercol] == BOX_ON_TARGET) { /*value changes for a worker pushing a box off a target*/
					if (warehouse[workerrow - 2][workercol] == SPACE) {
						warehouse[workerrow - 2][workercol] = BOX;
						warehouse[workerrow - 1][workercol] = WORKER_ON_TARGET;
						warehouse[workerrow][workercol] = SPACE;
					}
					else if (warehouse[workerrow - 2][workercol] == TARGET) { /*value changes for a worker pushing a box off a target onto another target*/
						warehouse[workerrow - 2][workercol] = BOX_ON_TARGET;
						warehouse[workerrow - 1][workercol] = WORKER_ON_TARGET;
						warehouse[workerrow][workercol] = SPACE;
					}
				}
			}
			else if (warehouse[workerrow][workercol] == WORKER_ON_TARGET) { /*6 possibilites repeated for if the worker was on a target*/
				if (warehouse[workerrow - 1][workercol] == SPACE) {
					warehouse[workerrow - 1][workercol] = WORKER;
					warehouse[workerrow][workercol] = TARGET;
				}
				else if (warehouse[workerrow - 1][workercol] == TARGET) {
					warehouse[workerrow - 1][workercol] = WORKER_ON_TARGET;
					warehouse[workerrow][workercol] = TARGET;
				}
				else if (warehouse[workerrow - 1][workercol] == BOX) {
					if (warehouse[workerrow - 2][workercol] == SPACE) {
						warehouse[workerrow - 2][workercol] = BOX;
						warehouse[workerrow - 1][workercol] = WORKER;
						warehouse[workerrow][workercol] = TARGET;
					}if (warehouse[workerrow - 2][workercol] == TARGET) {
						warehouse[workerrow - 2][workercol] = BOX_ON_TARGET;
						warehouse[workerrow - 1][workercol] = WORKER;
						warehouse[workerrow][workercol] = TARGET;
					}
				}
				else if (warehouse[workerrow - 1][workercol] == BOX_ON_TARGET) {
					if (warehouse[workerrow - 2][workercol] == SPACE) {
						warehouse[workerrow - 2][workercol] = BOX;
						warehouse[workerrow - 1][workercol] = WORKER_ON_TARGET;
						warehouse[workerrow][workercol] = TARGET;
					}
					else if (warehouse[workerrow - 2][workercol] == TARGET) {
						warehouse[workerrow - 2][workercol] = BOX_ON_TARGET;
						warehouse[workerrow - 1][workercol] = WORKER_ON_TARGET;
						warehouse[workerrow][workercol] = TARGET;
					}
				}
			}
		}
		else if (move == 's') { /*all 12 possibilites are repeated for each move*/
			if (warehouse[workerrow][workercol] == WORKER) {
				if (warehouse[workerrow + 1][workercol] == SPACE) {
					warehouse[workerrow + 1][workercol] = WORKER;
					warehouse[workerrow][workercol] = SPACE;
				}
				else if (warehouse[workerrow + 1][workercol] == TARGET) {
					warehouse[workerrow + 1][workercol] = WORKER_ON_TARGET;
					warehouse[workerrow][workercol] = SPACE;
				}
				else if (warehouse[workerrow + 1][workercol] == BOX) {
					if (warehouse[workerrow + 2][workercol] == SPACE) {
						warehouse[workerrow + 2][workercol] = BOX;
						warehouse[workerrow + 1][workercol] = WORKER;
						warehouse[workerrow][workercol] = SPACE;
					}if (warehouse[workerrow + 2][workercol] == TARGET) {
						warehouse[workerrow + 2][workercol] = BOX_ON_TARGET;
						warehouse[workerrow + 1][workercol] = WORKER;
						warehouse[workerrow][workercol] = SPACE;
					}
				}
				else if (warehouse[workerrow + 1][workercol] == BOX_ON_TARGET) {
					if (warehouse[workerrow + 2][workercol] == SPACE) {
						warehouse[workerrow + 2][workercol] = BOX;
						warehouse[workerrow + 1][workercol] = WORKER_ON_TARGET;
						warehouse[workerrow][workercol] = SPACE;
					}
					else if (warehouse[workerrow + 2][workercol] == TARGET) {
						warehouse[workerrow + 2][workercol] = BOX_ON_TARGET;
						warehouse[workerrow + 1][workercol] = WORKER_ON_TARGET;
						warehouse[workerrow][workercol] = SPACE;
					}
				}
			}
			else if (warehouse[workerrow][workercol] == WORKER_ON_TARGET) {
				if (warehouse[workerrow + 1][workercol] == SPACE) {
					warehouse[workerrow + 1][workercol] = WORKER;
					warehouse[workerrow][workercol] = TARGET;
				}
				else if (warehouse[workerrow + 1][workercol] == TARGET) {
					warehouse[workerrow + 1][workercol] = WORKER_ON_TARGET;
					warehouse[workerrow][workercol] = TARGET;
				}
				else if (warehouse[workerrow + 1][workercol] == BOX) {
					if (warehouse[workerrow + 2][workercol] == SPACE) {
						warehouse[workerrow + 2][workercol] = BOX;
						warehouse[workerrow + 1][workercol] = WORKER;
						warehouse[workerrow][workercol] = TARGET;
					}if (warehouse[workerrow + 2][workercol] == TARGET) {
						warehouse[workerrow + 2][workercol] = BOX_ON_TARGET;
						warehouse[workerrow + 1][workercol] = WORKER;
						warehouse[workerrow][workercol] = TARGET;
					}
				}
				else if (warehouse[workerrow + 1][workercol] == BOX_ON_TARGET) {
					if (warehouse[workerrow + 2][workercol] == SPACE) {
						warehouse[workerrow + 2][workercol] = BOX;
						warehouse[workerrow + 1][workercol] = WORKER_ON_TARGET;
						warehouse[workerrow][workercol] = TARGET;
					}
					else if (warehouse[workerrow + 2][workercol] == TARGET) {
						warehouse[workerrow + 2][workercol] = BOX_ON_TARGET;
						warehouse[workerrow + 1][workercol] = WORKER_ON_TARGET;
						warehouse[workerrow][workercol] = TARGET;
					}
				}
			}
		}
		else if (move == 'a') {
			if (warehouse[workerrow][workercol] == WORKER) {
				if (warehouse[workerrow][workercol - 1] == SPACE) {
					warehouse[workerrow][workercol - 1] = WORKER;
					warehouse[workerrow][workercol] = SPACE;
				}
				else if (warehouse[workerrow][workercol - 1] == TARGET) {
					warehouse[workerrow][workercol - 1] = WORKER_ON_TARGET;
					warehouse[workerrow][workercol] = SPACE;
				}
				else if (warehouse[workerrow][workercol - 1] == BOX) {
					if (warehouse[workerrow][workercol - 2] == SPACE) {
						warehouse[workerrow][workercol - 2] = BOX;
						warehouse[workerrow][workercol - 1] = WORKER;
						warehouse[workerrow][workercol] = SPACE;
					}
					else if (warehouse[workerrow][workercol - 2] == TARGET) {
						warehouse[workerrow][workercol - 2] = BOX_ON_TARGET;
						warehouse[workerrow][workercol - 1] = WORKER;
						warehouse[workerrow][workercol] = SPACE;
					}
				}
				else if (warehouse[workerrow][workercol - 1] == BOX_ON_TARGET) {
					if (warehouse[workerrow][workercol - 2] == SPACE) {
						warehouse[workerrow][workercol - 2] = BOX;
						warehouse[workerrow][workercol - 1] = WORKER_ON_TARGET;
						warehouse[workerrow][workercol] = SPACE;
					}
					else if (warehouse[workerrow][workercol - 2] == TARGET) {
						warehouse[workerrow][workercol - 2] = BOX_ON_TARGET;
						warehouse[workerrow][workercol - 1] = WORKER_ON_TARGET;
						warehouse[workerrow][workercol] = SPACE;
					}
				}
			}
			else if (warehouse[workerrow][workercol] == WORKER_ON_TARGET) {
				if (warehouse[workerrow][workercol - 1] == SPACE) {
					warehouse[workerrow][workercol - 1] = WORKER;
					warehouse[workerrow][workercol] = TARGET;
				}
				else if (warehouse[workerrow][workercol - 1] == TARGET) {
					warehouse[workerrow][workercol - 1] = WORKER_ON_TARGET;
					warehouse[workerrow][workercol] = TARGET;
				}
				else if (warehouse[workerrow][workercol - 1] == BOX) {
					if (warehouse[workerrow][workercol - 2] == SPACE) {
						warehouse[workerrow][workercol - 2] = BOX;
						warehouse[workerrow][workercol - 1] = WORKER;
						warehouse[workerrow][workercol] = TARGET;
					}
					else if (warehouse[workerrow][workercol - 2] == TARGET) {
						warehouse[workerrow][workercol - 2] = BOX_ON_TARGET;
						warehouse[workerrow][workercol - 1] = WORKER;
						warehouse[workerrow][workercol] = TARGET;
					}
				}
				else if (warehouse[workerrow][workercol - 1] == BOX_ON_TARGET) {
					if (warehouse[workerrow][workercol - 2] == SPACE) {
						warehouse[workerrow][workercol - 2] = BOX;
						warehouse[workerrow][workercol - 1] = WORKER_ON_TARGET;
						warehouse[workerrow][workercol] = TARGET;
					}
					else if (warehouse[workerrow][workercol - 2] == TARGET) {
						warehouse[workerrow][workercol - 2] = BOX_ON_TARGET;
						warehouse[workerrow][workercol - 1] = WORKER_ON_TARGET;
						warehouse[workerrow][workercol] = TARGET;
					}
				}
			}
		}
		else if (move == 'd') {
		if (warehouse[workerrow][workercol] == WORKER) {
			if (warehouse[workerrow][workercol + 1] == SPACE) {
				warehouse[workerrow][workercol + 1] = WORKER;
				warehouse[workerrow][workercol] = SPACE;
			}
			else if (warehouse[workerrow][workercol + 1] == TARGET) {
				warehouse[workerrow][workercol + 1] = WORKER_ON_TARGET;
				warehouse[workerrow][workercol] = SPACE;
			}
			else if (warehouse[workerrow][workercol + 1] == BOX) {
				if (warehouse[workerrow][workercol + 2] == SPACE) {
					warehouse[workerrow][workercol + 2] = BOX;
					warehouse[workerrow][workercol + 1] = WORKER;
					warehouse[workerrow][workercol] = SPACE;
				}
				else if (warehouse[workerrow][workercol + 2] == TARGET) {
					warehouse[workerrow][workercol + 2] = BOX_ON_TARGET;
					warehouse[workerrow][workercol + 1] = WORKER;
					warehouse[workerrow][workercol] = SPACE;
				}
			}
			else if (warehouse[workerrow][workercol + 1] == BOX_ON_TARGET) {
				if (warehouse[workerrow][workercol + 2] == SPACE) {
					warehouse[workerrow][workercol + 2] = BOX;
					warehouse[workerrow][workercol + 1] = WORKER_ON_TARGET;
					warehouse[workerrow][workercol] = SPACE;
				}
				else if (warehouse[workerrow][workercol + 2] == TARGET) {
					warehouse[workerrow][workercol + 2] = BOX_ON_TARGET;
					warehouse[workerrow][workercol + 1] = WORKER_ON_TARGET;
					warehouse[workerrow][workercol] = SPACE;
				}
			}
		}
		else if (warehouse[workerrow][workercol] == WORKER_ON_TARGET) {
			if (warehouse[workerrow][workercol + 1] == SPACE) {
				warehouse[workerrow][workercol + 1] = WORKER;
				warehouse[workerrow][workercol] = TARGET;
			}
			else if (warehouse[workerrow][workercol + 1] == TARGET) {
				warehouse[workerrow][workercol + 1] = WORKER_ON_TARGET;
				warehouse[workerrow][workercol] = TARGET;
			}
			else if (warehouse[workerrow][workercol + 1] == BOX) {
				if (warehouse[workerrow][workercol + 2] == SPACE) {
					warehouse[workerrow][workercol + 2] = BOX;
					warehouse[workerrow][workercol + 1] = WORKER;
					warehouse[workerrow][workercol] = TARGET;
				}
				else if (warehouse[workerrow][workercol + 2] == TARGET) {
					warehouse[workerrow][workercol + 2] = BOX_ON_TARGET;
					warehouse[workerrow][workercol + 1] = WORKER;
					warehouse[workerrow][workercol] = TARGET;
				}
			}
			else if (warehouse[workerrow][workercol + 1] == BOX_ON_TARGET) {
				if (warehouse[workerrow][workercol + 2] == SPACE) {
					warehouse[workerrow][workercol + 2] = BOX;
					warehouse[workerrow][workercol + 1] = WORKER_ON_TARGET;
					warehouse[workerrow][workercol] = TARGET;
				}
				else if (warehouse[workerrow][workercol + 2] == TARGET) {
					warehouse[workerrow][workercol + 2] = BOX_ON_TARGET;
					warehouse[workerrow][workercol + 1] = WORKER_ON_TARGET;
					warehouse[workerrow][workercol] = TARGET;
				}
			}
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == TARGET || warehouse[i][j] == WORKER) { /*checking if any targets have no boxes on them and if a worker is not on a target*/
				jobfinished = 0; /*set boolean variable*/
			}
		}
	}if (jobfinished == 1) { /*if all targets have boxes on them and the worker is also on a target, return 1*/
		return 1;
	}
	return 0;
}

