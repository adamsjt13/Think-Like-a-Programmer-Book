#include <iostream>

using std::cin;
using std::cout;

void problemOne(int numRows);
void problemTwo(int numRows);
void problemThree(int numRows);

int main() {

    cout << "Problem 1:\n";
    problemOne(4);
    cout << "\n\n";

    cout << "Problem 2:\n";
    problemTwo(8);
    cout << "\n\n";

    cout << "Problem 3:\n";
    problemThree(8);
    return 0;
}

void problemOne(int numRows){

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
    
    int hashNum;
    int leftSpaceNum;
    int innerSpaceNum;
    int numTopHalfRows;

    numTopHalfRows = numRows / 2;

    for (int row = 1; row <= numRows; row++){
        
        if (row <= numTopHalfRows){
            hashNum = row * 2;
            leftSpaceNum = row - 1;
            innerSpaceNum = numRows - (((row % numTopHalfRows) - 1) * 2);
        }
        else {
            hashNum = numRows - ((row - (numTopHalfRows + 1)) * 2);
            leftSpaceNum = numRows - row;
            innerSpaceNum = (((row % numTopHalfRows) - 1) * 2);
        }
        
        for (int leftSpace = 0; leftSpace < leftSpaceNum; leftSpace++){
                cout << " ";
        }
        for (int hash = 0; hash < hashNum; hash++){
            cout << "#"
            if ((hash + 1) == (hashNum / 2)){
                for (int innerSpace = 0; innerSpace < innerSpaceNum; innerSpace++){
                cout << " ";
                }
            }
        }
        cout << "\n";
    }

}