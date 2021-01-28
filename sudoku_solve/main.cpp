#include <cstdio>
#include "sudoku.h"
#include <iostream>
using namespace std;

int main(){
    //input function
    sudoku s;
    int grid[N][N];
    s.scan(grid);
    s.solver(grid);
    if(!s.result()){
        cout<<"no result"<<endl;
    }else if(s.result()==1){
        cout<<"unique result"<<endl;
        s.print_unique();
    }else{
        cout<<s.result()<<" kinds of solve"<<endl;
    }

    return 0;
}





