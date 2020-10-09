/*
 * main.cpp
 *
 *  Created on: Jun 12, 2020
 *      Author: austinm
 */


#include "Sudoku.h"

int main(){

	//initilized sudoku puzzle
	int grid[9][9] = {{4,0,0,0,0,0,0,0,0},
					  {0,0,0,0,0,9,0,0,0},
					  {0,0,0,0,0,0,7,8,5},
					  {0,0,7,0,4,8,0,5,0},
					  {0,0,1,3,0,0,0,0,0},
					  {0,0,6,0,7,0,0,0,0},
					  {8,6,0,0,0,0,9,0,3},
					  {7,0,0,0,0,5,0,6,2},
					  {0,0,3,7,0,0,0,0,0}};

	//create sudoke object
	Sudoku s(grid);

	//solve the sudoku
	s.solveSudoku();

	//show the avaible solutions
	s.showSolutions();
}
