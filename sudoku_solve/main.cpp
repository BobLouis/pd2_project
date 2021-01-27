#include <cstdio>
#include "sudoku.h"

int main(){
    //input function
    sudoku s;
    int grid[N][N];
    s.scan(grid);
    if(s.solver(grid)) {
        s.print(grid);
    }else{
        printf("can't solve");
    }
    return 0;
}





