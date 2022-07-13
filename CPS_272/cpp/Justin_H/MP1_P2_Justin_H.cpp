#include <iostream>
#include <string>
#include <tuple>
#include <vector>
/*
A stack can be used to recognize certain types of patterns.Consider the pattern STRING1#STRING2, where neither string contains "#".The STRING2 must be the reverse of STRING1.Write a program that reads strings until the user enters an empty string.The program should indicate whether each string matches the pattern.
Run:
Input a string : 1 & A#A & 1
1 & A#A & 1 matches the pattern

Input a string : 1 & A#1 & A
1 & A#1 & A does not match the pattern

Input a string : madamimadam#madamimadam
madamimadam#madamimadam matches the pattern

Input a string :
*/

int getBaseHandler() {
    std::string tempString;
    std::cout << "Please enter a base: "; 
    std::getline(std::cin, tempString);
    return stoi(tempString);
}

int  getDecimalHandler() {
    std::string tempString;
    std::cout << "Please enter a decimal: ";
    std::getline(std::cin, tempString);
    return stoi(tempString);
}

std::vector<int> processBase(int func_inputBase, int func_inputInt) {
    std::vector<int> tempArray (2,0);
        tempArray.at(0) = func_inputInt / func_inputBase;
        tempArray.at(1) = func_inputInt % func_inputBase;
    return tempArray;
}

bool checkInput(int func_inputBase, int func_inputDecimal) {
    if (func_inputBase == 0 && func_inputDecimal == 0) {
        return false; 
    }
    return true;
}

void exitApp() {
    std::cout << "0, 0 detected for input, exiting application" << std::endl;
}

std::vector<int> doBaseCalculationLoop(int func_inputBase, int func_inputDecimal) {
    std::vector<int> tempArray;
    std::vector<int> result;

    while (true) {
        if (func_inputDecimal > 0) {
            tempArray = processBase(func_inputBase, func_inputDecimal);
            func_inputDecimal = tempArray[0]; 
            result.push_back(tempArray[1]);
        }
        else {
            break;
        }
    }
    return result;
}

void main()
{

    int base{};
    int decimal{};
    std::tuple<int, int> tempTuple = std::make_tuple(0,0); 
    while (true) {
        base = getBaseHandler();
        decimal = getDecimalHandler(); 
        if (checkInput(base, decimal)) {
            std::cout << "ANSWER : "; 
            for(auto element : doBaseCalculationLoop(base, decimal)) {
                std::cout << element; 
            }
            std::cout << std::endl << "Calculations done, please reverse string - I didn't care enough" << std::endl;
        }
        else {
            break;
        }
    }
    exitApp(); 
    system("pause");

} 