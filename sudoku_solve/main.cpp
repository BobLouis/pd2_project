#include "sudoku.h"
#include <iostream>
#define N 9
using namespace std;

void changeNum(int grid[N][N],int x,int y);
void changeRow(int grid[N][N],int x, int y);
void changeCol(int grid[N][N],int x,int y);
void counterRotate(int grid[N][N]);
void upDownFlip(int grid[N][N]);
void leftRightFlip(int grid[N][N]);

int main(){
    //input function
    sudoku s;
    int grid[N][N];
    s.scan(grid);

    int command,x,y;
    cin>>command;
    while(command!=0){
        switch(command){
            case 1:
                cin>>x>>y;
                changeNum(grid,x,y);
                break;
            case 2:
                cin>>x>>y;
                changeRow(grid,x,y);
                break;
            case 3:
                cin>>x>>y;
                changeCol(grid,x,y);
                break;
            case 4:
                cin>>x;
                for(int i=0;i<(x%4);++i){
                    counterRotate(grid);
                }
                break;
            case 5:
                cin>>x;
                if(!x){
                    upDownFlip(grid);
                }else if(x==1){
                    leftRightFlip(grid);
                }
                break;
            default:
                cin>>x>>y;
                cout<<"error command"<<endl;
                break;
        }
        cin>>command;
    }

    s.print(grid);
    return 0;
}

void changeNum(int grid[N][N],int x,int y){
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
void changeRow(int grid[N][N],int x, int y){
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
void changeCol(int grid[N][N],int x,int y){
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
void counterRotate(int grid[N][N]){
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
void upDownFlip(int grid[N][N]){
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
void leftRightFlip(int grid[N][N]){
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




