#define BOARD_SIZE 9

class Solution {
public:
    bool isNumberAlreadyInRow(vector<vector<char>>& board, int row, char n)
    {
        int occurences = 0;
        for(int i = 0; i < BOARD_SIZE; i++)
            if (n == board[row][i]) occurences++; 

        return occurences != 1; 
    }
    bool isNumberAlreadyInColumn(vector<vector<char>>& board, int col, char n)
    {
        int occurences = 0;
        for(int i = 0; i < BOARD_SIZE; i++)
            if (n == board[i][col]) occurences++; 

        return occurences != 1;
    }
    bool isNumberAlreadyInSubBox(vector<vector<char>>& board, int row, int col, char n)
    {
        int occurences = 0;
        int subBoxRow = row - row % 3;
        int subBoxCol = col - col % 3;

        for(int i = subBoxRow; i < subBoxRow +3; i++)
            for(int j = subBoxCol; j < subBoxCol + 3; j++)
                if (n == board[i][j]) occurences++;

        return occurences != 1; 

    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < BOARD_SIZE; row++)
        {
            for(int col = 0; col < BOARD_SIZE; col++)
            {
                char currentN = board[row][col];
                if ('.' != currentN)
                {
                    if (isNumberAlreadyInRow(board, row, currentN)) return false;
                    if (isNumberAlreadyInColumn(board, col, currentN)) return false;
                    if (isNumberAlreadyInSubBox(board, row, col, currentN)) return false;
                }
            }
        }
        return true; 
    }
};
