//
// Created by 洪緯宸 on 2021/1/26.
//

#ifndef SODOKU_SUDOKU_H
#define SODOKU_SUDOKU_H
#define UNASSIGHED 0
#define N 9

class sudoku {
public:
    bool solver(int grid[N][N]);
    void print(int grid[N][N]);
    void scan(int grid[N][N]);
    int result();
    void print_unique();

private:
    int count=0;
    int uni_solve[N][N];
    bool isSafe(int grid[N][N],int row,int col,int num);
    bool findEntry(int grid[N][N],int& row,int& col);
    bool checkRow(int grid[N][N],int row,int num);
    bool checkCol(int grid[N][N],int col,int num);
    bool checkSection(int grid[N][N],int row,int col,int num);
};


#endif //SODOKU_SUDOKU_H
