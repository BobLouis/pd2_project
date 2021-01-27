//
// Created by 洪緯宸 on 2021/1/26.
//

#include "sudoku.h"
#include <cstdio>
bool sudoku::solver(int grid[N][N]){
    int origin[N][N];

    int col , row;
    if(findEntry(grid,row,col)==false){
        return true;
    }
    for(int num=1;num<=N;++num){
        if(isSafe(grid,row,col,num)){
            grid[row][col]=num;
            if(solver(grid)){
                return true;
            }else{
                grid[row][col]=UNASSIGHED;
                //if the solver return false erase the new one
            }
        }
    }
    return false;
}



bool sudoku::findEntry(int grid[N][N],int&row,int&col){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(grid[i][j]==UNASSIGHED){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
//if safe return true
bool sudoku::checkRow(int grid[N][N],int row,int num){
    for(int col=0;col<N;++col){
        if(grid[row][col]==num){
            return false;
        }
    }
    return true;
}

bool sudoku::checkCol(int grid[N][N],int col,int num){
    for(int row=0;row<N;++row){
        if(grid[row][col]==num){
            return false;
        }
    }
    return true;
}

//start row col must be 0 3 6
bool sudoku::checkSection(int grid[N][N],int row,int col,int num){
    int startRow=row-row%3;
    int startCol=col-col%3;
    for(int row=startRow;row<startRow+3;++row){
        for(int col=startCol;col<startCol+3;++col){
            if(grid[row][col]==num){
                return false;
            }
        }
    }
    return true;
}

bool sudoku::isSafe(int grid[N][N],int row,int col,int num){
    return checkRow(grid,row,num)&&checkCol(grid,col,num)&&checkSection(grid,row,col,num);
}

void sudoku::print(int grid [N][N]){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void sudoku::scan(int grid[N][N]){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            scanf("%d",&grid[i][j]);
        }
    }
}
