#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm> //This is needed for the transform function
using namespace std;

int main()
{
    //Declaring and opening text files
    ifstream infile("dynamicCharacterArrayInput.txt");
    ofstream outfile("dynamicCharacterArrayOutput.txt");

    char *a = NULL; //Declare a pointer variable and initialize it to NULL
    int arraySize; //Declare an integer value that will hold the number for the array components
    string arrayString; //Declare a string value that will hold the string for the array components
    infile >> arrayString; //Retrieves the string to be used in the array from the text file

    cout << "Please note, the string size has an upper bound of 50 characters \n";
    cout << "Please enter an integer for the size of the array: ";
    cin >> arraySize; //Initialize the size of the array to the user's integer

    a = new char[arraySize]; //Create a new array of user's size

    for(int i = 0; i < arraySize; i++)
    {
        transform(arrayString.begin(), arrayString.end(), arrayString.begin(), ::toupper);
        a[i] = arrayString[i]; //Initialize all array values to a character of the arrayString
        outfile << a[i] << " "; //Output all array values ***Lines 27-28 are redundant, as the output could be done from arrayString[i]***
    }

    delete [] a; //Delete the array to free memory
    a = NULL; //Clear to prevent using an invalid memory reference

    //Close both files - Good Housekeeping
    infile.close();
    outfile.close();

    return 0;
}
