/*
 * Name: Chris hattan
 * Date Submitted: 11/21
 * Lab Section: 002
 * Assignment Name: lab 9
 */

#include <iostream>
#include <vector>
#include <stdbool.h> 
#include <stdio.h> 

using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n){
  
  for (int i = 0; i < col; ++i){//checks row
    if (board[row][i] == 1){
      return false;
    }
  }
  for(int i = row, j = col; i >= 0 && j >=0; i--, j--){
    if (board[i][j] == 1){//checks upper diagonal
      return false;
    }
  }
  for(int i = row, j = col; j >= 0 && i < n; i++, j--){
    if(board[i][j] == 1){//checks lower diagonal
      return false;
    }
  }
  return true;
}

bool findQueens(vector<vector<int>> &board, int col ,int *ways, int n){
  bool output = false;
  if (col == n){
    (*ways)++;
    return true;
  }
  
  for (int i = 0; i < n; i++){
    if(isSafe(board,i,col,n)){//if its safe recurses 
      board[i][col] = 1;
      output = findQueens(board,col + 1, ways,n);
      board[i][col] = 0;//resets the board 
    }
  }
  return output;
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
  vector<vector<int>> board(n, (vector<int> (n, 0)));
  
  int ways = 0;

  findQueens(board, 0, &ways, n);

  return ways;
}
