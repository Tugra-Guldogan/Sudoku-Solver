#include <iostream>
#include <chrono>
#include <ctime>  

#define log(thing) (std::cout<<thing<<std::endl)
#define number 9

int board[9][9] = {
{0, 2, 0, 0, 0, 4, 3, 0, 0},
{9, 0, 0, 0, 2, 0, 0, 0, 8},
{0, 0, 0, 6, 0, 9, 0, 5, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 1},
{0, 7, 2, 5, 0, 3, 6, 8, 0},
{6, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 8, 0, 2, 0, 5, 0, 0, 0},
{1, 0, 0, 0, 9, 0, 0, 0, 3},
{0, 0, 9, 8, 0, 0, 0, 6, 0}};


void print(){
    for (int row = 0; row < number; row++)
    {
        if (row%3==0)
            log("---------------------------");
        for (int col = 0; col < number; col++)
        {
            if(col == 0)
                std::cout<<"| ";
            if (col %3==0 && col != 0)
                std::cout<<" | "; 
            if(col == 8)
                std::cout<<board[row][col]<<" | "<<std::endl;
            else{
                std::cout<<board[row][col]<<" ";
            }
        }    
    }
}

int empty(int &row, int &col){ // make a reference to row and col variable
    for (row = 0; row < number; row++) // set them to zero then increase them
        for (col = 0; col < number; col++)
            if (board[row][col] == 0) // if that place is equal to 0 then return true and row and col variables are now equal to that empty place
                return true;
   return false;
}

bool isDuplicated(int row, int col, int num){
    for (int i = 0; i < number; i++)
    {
        if (board[i][col] == num) //checking if number exists in row
            return true;
        if (board[row][i] == num) // checking if number exists in column 
            return true;
    }
    for (int rowPlus = 0; rowPlus < 3; rowPlus++)
        for (int colPlus = 0; colPlus < 3; colPlus++)
            if (board[(row-row%3) + rowPlus][(col-col%3) + colPlus] == num) //find which box contains our col and row then check if num is in the box
                return true;

    return false;
}

bool isFinished(){
    int row,col;
    if(!empty(row,col)) // if its not empty then sudoku is solved
        return true;
    for (int i = 1; i <= 9; i++)
    {
        if (!isDuplicated(row,col,i)) // if its not already there
        {
            board[row][col] = i; // change 0 to i value
            if (isFinished()) // run the function again untill all 0 are gone and if its true finish program
                return true;  
            board[row][col] = 0; // if its not true then set it back to 0
        }
    }
    return false;
}


int main(){
    auto start = std::chrono::system_clock::now();
    isFinished();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> duration = end-start;
    print();
    log("");
    std::cout<<"Finished in  "<<duration.count()<<"  seconds";
    

}


// Here is the brute force protected sudoku try it!


/*
int board[9][9] = {
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 3, 0, 8, 5},
{0, 0, 1, 0, 2, 0, 0, 0, 0},
{0, 0, 0, 5, 0, 7, 0, 0, 0},
{0, 0, 4, 0, 0, 0, 1, 0, 0},
{0, 9, 0, 0, 0, 0, 0, 0, 0},
{5, 0, 0, 0, 0, 0, 0, 7, 3},
{0, 0, 2, 0, 1, 0, 0, 0, 0},
{0, 0, 0, 0, 4, 0, 0, 0, 9}};
*/
