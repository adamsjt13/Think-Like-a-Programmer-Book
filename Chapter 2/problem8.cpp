#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::floor;
using std::pow;

int convertToDecimal(int num_to_convert, int convert_from_base);

int main(){

    int num_to_convert;
    int convert_from_base;
    int converted_number;
    
    cout << "Please enter an integer to convert:" << endl;
    cin >> num_to_convert;
    while (cin.fail()){
        cout << "Invalid input! Please enter an integer to convert:" << endl;
        cin >> num_to_convert;
    } 
    cout << "Please enter the base, between 2 and 16, of the number:" << endl;
    cin >> convert_from_base;
    while (convert_from_base < 2 || convert_from_base > 16 || cin.fail()){
        cout << "Invalid input! Please enter the base, between 2 and 16, of the number:" << endl;
        cin >> convert_from_base;
    }

    try {
        cout << num_to_convert << " in base " << convert_from_base << " is "; 
        cout << convertToDecimal(num_to_convert,convert_from_base) << " in decimal!" << endl;
    return 0;
    }
        catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << endl;
        return -1;
    }
}

int convertToDecimal(int num_to_convert, int convert_from_base){

    int quotient = num_to_convert;
    int remainder;
    int digit_place = 0;
    int decimal_number = 0;

    while (quotient > 0){

        remainder = quotient % 10;
        
        if (remainder >= convert_from_base){
            throw std::invalid_argument("invalid!");
        }
        quotient = floor(quotient / 10);

        decimal_number += remainder * pow(convert_from_base, digit_place);
        digit_place++;

    }

    return decimal_number;

}

