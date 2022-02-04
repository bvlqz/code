#include <vector>
#include <iostream>
#include <string>

using namespace std; 

class Solution {
public:
    void printBoard(vector<vector<char>>& board){
        cout << endl;
        int rowCount = 0; 
        for (auto & row : board) {

            int numCount = 0; 
            for (auto & num : row)
            {
                cout << num; 
                
                numCount++;
                if (numCount % 3 == 0) cout << "   ";
            }
            cout << endl;
            
            rowCount++;
            if (rowCount % 3 == 0) cout << endl;
        }
    }

    bool isNumberAlreadyInRow(vector<vector<char>>& board, int row, char n)
    {
        for(int i = 0; i < 9; i++) if (n == board[row][i]) return true; 
        return false;
    }

    bool isNumberAlreadyInColumn(vector<vector<char>>& board, int col, char n)
    {
        for(int i = 0; i < 9; i++) if (n == board[i][col]) return true;

        return false;
    }

    bool isNumberAlreadyInSubBox(vector<vector<char>>& board, int row, int col, char n)
    {
        int subBoxRow = row - row % 3;
        int subBoxCol = col - col % 3;

        for(int i = subBoxRow; i < subBoxRow +3; i++)
            for(int j = subBoxCol; j < subBoxCol + 3; j++)
                if (n == board[i][j]) return true;

        return false; 

    }

    bool canNumBePlaced(vector<vector<char>>& board, int row, int col, char n)
    {
        if (isNumberAlreadyInRow(board, row, n)) return false;
        if (isNumberAlreadyInColumn(board, col, n)) return false;
        if (isNumberAlreadyInSubBox(board, row, col, n)) return false;
        return true;
    }

    bool solveRecursive(vector<vector<char>>& board)
    {
        printBoard(board);
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++) {
                if ('.' == board[i][j])
                {
                    for (int num = 1; num < 10; num++)
                    {
                        if (canNumBePlaced(board, i, j, '0' + num))
                        {
                            board[i][j] = '0' + num;
                            if (solveRecursive(board))
                            {
                                printBoard(board);
                                return true;
                            } else { 
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false; 
                }
            }
        }
        return true; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveRecursive(board);
    }
};

int main()
{
    std::cout << "Start" << std::endl;
    Solution s; 
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    s.solveSudoku(board);

    std::cout << "End" << std::endl;
}
