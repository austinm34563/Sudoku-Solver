/*
 * Sudoku.h
 *
 *  Created on: Jun 12, 2020
 *      Author: austinm
 */

#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <vector>
#include <iostream>
using namespace std;

struct My2DArray{
	int grid[9][9];
};
class Sudoku{
private:
	int board[9][9];
	vector<My2DArray> solutions;

public:
	Sudoku(int b[9][9]){

		//initilizes the board based on what has been fed to the object
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				board[i][j] = b[i][j];
			}
		}
	}
	void showSolutions(){

		//if the solutions vector is size 0, tell that there are no solutons
		if(solutions.size() == 0){
			cout<<"No solutions exists."<<endl;
			return;
		}

		//traverse through the vector and show all solutions
		for(int k = 0; k < solutions.size(); k++){
			cout<<"Solution #"<<k+1<<": "<<endl;
			for(int i = 0; i < 9; i++){
				for(int j = 0; j < 9; j++){
					cout<<solutions[k].grid[i][j]<<"\t";
				}
				cout<<endl;
			}
			cout<<endl;
		}
	}

	void solveSudoku(){

		//traverse through the board
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){

				//check if the current position on the board
				//is an empty slot
				if(board[i][j] == 0){

					//check digits 1 through 9 that work
					for(int n = 1; n < 10; n++){

						//check if the combination is possible
						if(isPossible(i,j,n)){


							//if it's possible, put the digit in the empty slot
							board[i][j] = n;

							//recurse back to solving the puzzle
							solveSudoku();

							//back track
							board[i][j] = 0;
						}
					}
					return;
				}
			}
		}

		//use this to access all the possible solutions
		My2DArray s;

		//store all the possible solutions
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				s.grid[i][j] = board[i][j];
			}
		}

		//push the solutions to the vector
		solutions.push_back(s);
	}

	bool isPossible(int row, int col, int num){

		//check if any nums match in the row/col
		for(int i = 0; i < 9; i++){
			if(board[row][i] == num){
				return false;
			}
			if(board[i][col] == num){
				return false;
			}
		}

		//calculate the starting position for each
		//3X3 sub matrix within the grid
		int subRow = (row/3) * 3;
		int subCol = (col/3) * 3;

		//check the sub 3X3 matricies
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(board[subRow + i][subCol + j] == num)
					return false;
			}
		}

		//if it passes all three conditions, it's possible
		return true;
	}
};


#endif /* SUDOKU_H_ */
