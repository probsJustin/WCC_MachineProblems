#include <iostream>
#include <string>

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


bool checkIfStringHasDelimiter(std::string func_inputString, char delimiter) {
    if (func_inputString.find(delimiter) != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

std::string getFirstString(std::string func_inputString, char delimiter) {
   return func_inputString.substr(0, func_inputString.find(delimiter));
}

std::string getSecondString(std::string func_inputString, char delimiter) {
    return func_inputString.substr(func_inputString.find(delimiter) + 1, func_inputString.size());
}

std::string reverseString(std::string func_inputString) {
    std::string tempString = "";
    for (int i = func_inputString.size() - 1; i >= 0; --i) {
        tempString += func_inputString[i]; 
    }
    return tempString;
}

void notPalindrome() {
    std::cout << "is not a palindrome" << std::endl;
}

void isPalindrome() {
    std::cout << "is a palindrome" << std::endl;
}

std::string inputHandler() {
    std::string tempString;
    std::cout << "Please enter a plaindrame following this format [racecar#racecar]: "; 
    std::getline(std::cin, tempString);
    return tempString; 
}
void main()
{
    std::cout << "Starting palindrome app...." << std::endl;
    while (true) {
        std::string userInput = inputHandler();
        if (checkIfStringHasDelimiter(userInput, '#') && userInput != "") {
                std::string firstPart = getFirstString(userInput, '#');
                std::string secondPart = getSecondString(userInput, '#');
                if (firstPart == reverseString(secondPart)) {
                    isPalindrome();
                }
                else {
                    notPalindrome();
                }
        }
        else {
            break; 
        }
    }
    std::cout << "No input detected, exiting program" << std::endl;
    system("pause");
}




