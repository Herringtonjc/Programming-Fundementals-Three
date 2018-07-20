//Creating and reading a random access file.
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct studentType

{
    char firstName[15];
    char lastName[15];
    int ID;
    double GPA;
};

void printStudentData(const studentType& student);

int main ()
{
    studentType st;
    ifstream inFile;
    ofstream outFile;

long studentsize = sizeof(st);

    //Open the input file, which is a text file
    inFile.open("studentData.txt");
    if(!inFile)
    {
        cout << "The input file does not exist. "
            << "The program terminates!!!!" << endl;
        return 1;
    }

    //Open a binary output file
    outFile.open("student.dat", ios::binary);
    inFile >> st.ID >> st.firstName
            >> st.lastName >> st.GPA;

    while(inFile)
    {
        outFile.seekp((st.ID - 1) * studentsize, ios::beg);
        outFile.write(reinterpret_cast<const char *> (&st), sizeof (st));
        inFile >> st.ID >> st.firstName >> st.lastName >> st.GPA;
    };

    inFile.close ();
    inFile.clear();
    outFile.close();

    cout << left << setw(3) << "ID"
    << setw(16) << "First Name"
    << setw(16) << "Last Name"
    << setw(12) << "Current GPA" << endl;
    cout << fixed << showpoint << setprecision(2);

    //Open the input file, which is a binary file
    inFile.open("student.dat", ios::binary);

    if (!inFile)
    {
    cout << "The input file does not exist. "
    << "The program terminates!!!!" << endl;

    return 1;
    }

    inFile.seekg(0, ios::end); //Seek to the end of the binary file
    int fileSize = inFile.tellg()/studentsize; //Number of records in the binary file

    int byteSize = -sizeof(st); //The size of each structure
    int counter = 0;
    do
    {
        inFile.seekg(byteSize, inFile.end); //Seek to the end of the file, and offset the size of one structure
        inFile.read(reinterpret_cast<char *>(&st), sizeof(st)); //Read in the data from the last record
        counter++;
        byteSize += -sizeof(st); //Change the offset by one record size
        if(st.ID != 0) //Only print the record information if the ID is not zero
        {
            printStudentData(st);
        }

    } while(counter < fileSize); //Continue the loop until reading the entire file
   return 0;
}

void printStudentData(const studentType& student)
{
   cout << left << setw(3) << student.ID
        << setw (16) << student. firstName
        << setw(16) << student.lastName
        << right << setw(10)<< student.GPA
        << endl;
}
