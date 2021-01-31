#include "sudoku.h"
#include <iostream>
#define N 9
using namespace std;

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
                s.changeNum(grid,x,y);
                break;
            case 2:
                cin>>x>>y;
                s.changeRow(grid,x,y);
                break;
            case 3:
                cin>>x>>y;
                s.changeCol(grid,x,y);
                break;
            case 4:
                cin>>x;
                for(int i=0;i<(x%4);++i){
                    s.counterRotate(grid);
                }
                break;
            case 5:
                cin>>x;
                if(!x){
                    s.upDownFlip(grid);
                }else if(x==1){
                    s.leftRightFlip(grid);
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

