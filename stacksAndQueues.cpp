#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    const int SIZE = 3; //Size used for both arrays

    stack<char> stackChar; //Creating a stack of chars
    queue<char> queueChar; //Creating a queue of chars
    string stringArray[SIZE] = {"cat", "MOM", "Dog"}; //Declare and initialize the array of strings
    char charArray[SIZE]; //Declare the array of chars

    for(int i = 0; i < SIZE; i++)
    {
        transform(stringArray[i].begin(), stringArray[i].end(), stringArray[i].begin(), ::tolower); //Transform the strings to lower case
        if(stringArray[i] == string(stringArray[i].rbegin(), stringArray[i].rend())) //Reads the string to see if it's a palindrome
        {
            cout << stringArray[i] << " is a palindrome!";
        }

        for(int j = 0; j < SIZE; j++)
        {
            charArray[i] = stringArray[i][j]; //Assign each character into the character array
            stackChar.push(charArray[i]); //Push the characters into the stack
            queueChar.push(charArray[i]); //Push the characters into the queue
        }
    }

    return 0;
}