#include <iostream>

using std::cin;
using std::cout;

void problemOne(int numRows);
void problemTwo(int numRows);
void problemThree(int numRows);

int main() {

    int userRows;

    cout << "Problem 1:\n";
    cout << "Please enter integer between 4 and 64 for number of rows for inverted triangle:\n";
    cin >> userRows;
    cout << "\n";
    while (userRows < 4 || userRows > 64 || cin.fail()){
        cout << "Invalid input. Must be an integer between 4 and 64!\n\n";
        cout << "Please enter integer between 4 and 64 for number of rows for inverted triangle:\n";
        cin >> userRows;
        cout << "\n";
    }
    problemOne(userRows);
    cout << "\n\n";

    cout << "Problem 2:\n";
    cout << "Please enter integer between 4 and 64 for number of rows for diamond:\n";
    cin >> userRows;
    cout << "\n";
    while (userRows < 4 || userRows > 64 || cin.fail()){
        cout << "Invalid input. Must be an integer between 4 and 64!\n\n";
        cout << "Please enter integer between 4 and 64 for number of rows for diamond:\n";
        cin >> userRows;
        cout << "\n";
    }
    problemTwo(userRows);
    cout << "\n\n";

    cout << "Problem 3:\n";
    cout << "Please enter even integer between 4 and 64 for number of rows for X:\n";
    cin >> userRows;
    cout << "\n";
    while (userRows < 4 || userRows > 64 || cin.fail() || userRows % 2 == 1){
        cout << "Invalid input. Must be an even integer between 4 and 64!\n\n";
        cout << "Please enter even integer between 4 and 64 for number of rows for X:\n";
        cin >> userRows;
        cout << "\n";
    }
    problemThree(userRows);
    return 0;
}

void problemOne(int numRows){
    /* 
        Creates an inverted triangle of even numbered hash marks like below:
        ########
         ######
          ####
           ##
        
        arguments:
        numRows -- how many rows should the inverted triangle be
    */
    int hashNum;
    
    for (int row = 1; row <= numRows; row++){
        hashNum = ((numRows * 2) + 2) - (row * 2);
        for (int space = 0; space < row; space++){
                cout << " ";
        }
        for (int hash = 0; hash < hashNum; hash++){
            cout << "#";
        }
        cout << "\n";
    }

}

void problemTwo(int numRows){
    /* 
        Creates an diamond of even numbered hash marks like below:
           ##
          ####
         ######
        ########
        ########
         ######
          ####
           ##
        
        arguments:
        numRows -- how many rows should the inverted triangle be
    */
    int hashNum;
    int spaceNum;
    int numTopHalfRows;

    numTopHalfRows = numRows / 2;

    for (int row = 1; row <= numRows; row++){
        
        if (row <= numTopHalfRows){
            hashNum = row * 2;
            spaceNum = numTopHalfRows - row;
        }
        else {
            hashNum = numRows - ((row - (numTopHalfRows + 1)) * 2);
            spaceNum = row % (numTopHalfRows + 1);
        }
        
        for (int space = 0; space < spaceNum; space++){
                cout << " ";
        }
        for (int hash = 0; hash < hashNum; hash++){
            cout << "#";
        }
        cout << "\n";
    }

}

void problemThree(int numRows){
        /* 
        Creates a X like symbol of even numbered hash marks like below:
       #            #
        ##        ##
         ###    ###
          ########
          ########
         ###   ###
        ##       ##
       #           #
        arguments:
        numRows -- how many rows should the X be
    */
    int hashNum;
    int leftSpaceNum;
    int innerSpaceNum;
    int numTopHalfRows;

    numTopHalfRows = numRows / 2;

    for (int row = 1; row <= numRows; row++){
        
        if (row <= numTopHalfRows){
            hashNum = row * 2;
            leftSpaceNum = row - 1;
            innerSpaceNum = (numTopHalfRows - row) * 4;
        }
        else {
            hashNum = numRows - ((row - (numTopHalfRows + 1)) * 2);
            leftSpaceNum = numRows - row;
            innerSpaceNum = (row - numTopHalfRows - 1) * 4;
        }
        
        for (int leftSpace = 0; leftSpace < leftSpaceNum; leftSpace++){
                cout << " ";
        }
        for (int hash = 0; hash < hashNum; hash++){
            cout << "#";
            if ((hash + 1) == (hashNum / 2)){
                for (int innerSpace = 0; innerSpace < innerSpaceNum; innerSpace++){
                cout << " ";
                }
            }
        }
        cout << "\n";
    }

}