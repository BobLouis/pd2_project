//
// Created by 洪緯宸 on 2021/1/26.
//

#include "sudoku.h"
#include <cstdio>

bool sudoku::solver(int grid[N][N]){
    int col , row;
    if(findEntry(grid,row,col)==false){
        return true;
    }
    for(int num=1;num<=N;++num){
        if(isSafe(grid,row,col,num)){
            grid[row][col]=num;
            if(solver(grid)){
                count++;
//                printf("%d\n",count);
//                for(int i=0;i<N;++i){
//                    for(int j=0;j<N;++j){
//                        printf("%d ",grid[i][j]);
//                    }
//                    printf("\n");
//                }
//                printf("\n");
                if(count==1){
                    for(int i=0;i<N;++i){
                        for(int j=0;j<N;++j){
                            uni_solve[i][j]=grid[i][j];
                        }
                    }
                }
                grid[row][col]=UNASSIGHED;

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

int sudoku::result() {
    return count;
}

void sudoku::print_unique(){
    print(uni_solve);
}

//transform
void sudoku::changeNum(int grid[N][N],int x,int y){
    int temp=10;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(grid[i][j]==x){
                grid[i][j]=temp;
            }
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(grid[i][j]==y){
                grid[i][j]=x;
            }
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(grid[i][j]==temp){
                grid[i][j]=y;
            }
        }
    }
}
void sudoku::changeRow(int grid[N][N],int x, int y){
    int xGrid[3][N];
    int yGrid[3][N];

    for(int i=0;i<3;++i){
        for(int j=0;j<N;++j){
            xGrid[i][j]=grid[3*x+i][j];
        }
    }
    for(int i=0;i<3;++i){
        for(int j=0;j<N;++j){
            yGrid[i][j]=grid[y*3+i][j];
            grid[y*3+i][j]=xGrid[i][j];
        }
    }
    for(int i=0;i<3;++i){
        for(int j=0;j<N;++j){
            grid[x*3+i][j]=yGrid[i][j];
        }
    }
}
void sudoku::changeCol(int grid[N][N],int x,int y){
    int xGrid[N][3];
    int yGrid[N][3];

    for(int i=0;i<3;++i){
        for(int j=0;j<N;++j){
            xGrid[j][i]=grid[j][3*x+i];
        }
    }
    for(int i=0;i<3;++i){
        for(int j=0;j<N;++j){
            yGrid[j][i]=grid[j][y*3+i];
            grid[j][y*3+i]=xGrid[j][i];
        }
    }
    for(int i=0;i<3;++i){
        for(int j=0;j<N;++j){
            grid[j][x*3+i]=yGrid[j][i];
        }
    }
}
void sudoku::counterRotate(int grid[N][N]){
    int newGrid[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;j++){
            newGrid[i][j]=grid[N-j-1][i];
        }
    }

    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            grid[i][j]=newGrid[i][j];
        }
    }
}
void sudoku::upDownFlip(int grid[N][N]){
    int newGrid[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            newGrid[i][j]=grid[N-i-1][j];
        }
    }

    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            grid[i][j]=newGrid[i][j];
        }
    }
}
void sudoku::leftRightFlip(int grid[N][N]){
    int newGrid[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            newGrid[i][j]=grid[i][N-j-1];
        }
    }

    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            grid[i][j]=newGrid[i][j];
        }
    }
}