#include <iostream>
#include <stack>

//Returns bool true if contains one of ({[< false otherwise
bool IsOpen(char character) {
    if(character == '(' || character == '{'
       || character == '[' || character == '<') {
        return true;
    }
    else {
        return false;
    }
}

//Returns bool true if contains one of )}]> false otherwise
bool IsClose(char character) {
    if(character == ')' || character == '}'
       || character == ']' || character == '>') {
        return true;
    }
    else {
        return false;
    }
}

//Returns bool true if operators match, false otherwise
bool AreMatched(char openingChar, char charToCheck) {
    if(openingChar == '(' && charToCheck == ')') {return true;}
    else if(openingChar == '{' && charToCheck == '}') {return true;}
    else if(openingChar == '[' && charToCheck == ']') {return true;}
    else if(openingChar == '<' && charToCheck == '>') {return true;}
    else {return false;}
}


int main(int argc, char* argv[]) {
    bool balanced = true;
    std::stack<char> charStack;

    std::string userString = argv[1];
    size_t stringLength = userString.size();
    int endIndex = stringLength;

    //Process for checking if the string is balanced
    for(int stringIndex = 0; balanced && stringIndex != endIndex; ++stringIndex) {
        if (IsOpen(userString.at(stringIndex))) {
            charStack.push(userString.at(stringIndex));
        }
        else if (IsClose(userString.at(stringIndex))) {
            if(charStack.size() == 0) {
                balanced = false;
            }
            else if(AreMatched(charStack.top(), userString.at(stringIndex))) {
                charStack.pop();
            }
            else {
                balanced = false;
            }
        }
    }

        if(!charStack.empty()) {
            balanced = false;
        }
        else {
        }

    if(balanced) {
        std::cout << "true";
    }
    else {
        std::cout << "false";
    }

    return 0;
}

//Extra text 1