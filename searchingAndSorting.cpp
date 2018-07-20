#include <iostream>

using namespace std;

void printArray(int arr[], int len);
void insertionSort(int arr[], int N);

int main() {
    int arrOne[] = {10, 7, 3, 1, 9, 7, 4, 3};
    int arrTwo[] = {6, 7, 5, 8, 6, 6, 8, 1};
    int arrThree[] = {1, 2, 7, 9, 3, 6, 9, 1};
    int lenOne = sizeof(arrOne) / sizeof(int);
    int lenTwo = sizeof(arrTwo) / sizeof(int);
    int lenThree = sizeof(arrThree) / sizeof(int);

    cout << "Initial Array One: ";
    printArray(arrOne, lenOne);
    cout << "Initial Array Two: ";
    printArray(arrTwo, lenTwo);
    cout << "Initial Array Three: ";
    printArray(arrThree, lenThree);

    insertionSort(arrOne, lenOne);
    insertionSort(arrTwo, lenTwo);
    insertionSort(arrThree, lenThree);

    cout << "After Insertion Sort One: ";
    printArray(arrOne, lenOne);
    cout << "After Insertion Sort Two: ";
    printArray(arrTwo, lenTwo);
    cout << "After Insertion Sort Three: ";
    printArray(arrThree, lenThree);
    return 0;
}

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

void insertionSort(int arr[], int N)
{
    for(int i = 1; i < N; i++)
    {
        int j = i - 1;
        int temp = arr[i];

        while(j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;;
        }

        arr[j + 1] = temp;
    }
}