#include <iostream>
#include <cstring>
using namespace std;
//function prototype
bool createArray(int* &arr, int size);
bool createArray(float* &arr, int size);
void printArray(const int* arr, int size);
void printArray(const float* arr, int size);
float* arraymerge(const int* arr1, const float* arr2, int size1, int size2, int& mergedSize);
char* readString(int maxLength = 150);
void printStrings(char** strings, int size);
int partition(char** strings, int low, int high);
void quickSort(char** strings, int low, int high);
void freeMemory(char** strings, int size);
void mainoption1();
void mainoption2();

//main function
int main()
{
    int option;
    cout << "Enter 1 to merge two arrays of integers and floats" << endl;
    cout << "Enter 2 to sort an array of strings" << endl;
    cin >> option;
    cin.ignore();
    if (option == 1)
    {
        mainoption1();
    }
    else if (option == 2)
    {
        mainoption2();
    }
    else
    {
        cout << "Invalid option" << endl;
    }
    return 0;
}


//function definition
bool createArray(int* &arr, int size)
{
    if(size <= 0)
    {
        return false;
    }
    arr = new int[size];
    cout<<"Enter"<<size<<"integers"<<endl;
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    return true;
}
bool createArray(float* &arr, int size)
{
    if (size <= 0)
    {
        return false;
    }
    arr = new float[size];
    cout<<"Enter"<<size<<"floats"<<endl;
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    return true;
}
void printArray(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void printArray(const float *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
float* arraymerge(const int* arr1, const float* arr2, int size1, int size2, int& mergedSize)
{
    float* temp = new float[size1 + size2];
    int x = 0, y = 0, z = 0;


    while (x < size1 && y < size2)
    {
        if (arr1[x] < arr2[y])
        {
            if (z == 0 || temp[z - 1] != arr1[x])
            {
                temp[z] = arr1[x];
                z++;
            }
            x++;
        }
        else if (arr1[x] > arr2[y])
        {
            if (z == 0 || temp[z - 1] != arr2[y])
            {
                temp[z] = arr2[y];
                z++;
            }
            y++;
        }
        else
        {

            if (z == 0 || temp[z - 1] != arr1[x])
            {
                temp[z] = arr1[x];
                z++;
            }
            x++;
            y++;
        }
    }


    while (x < size1)
    {
        if (z == 0 || temp[z - 1] != arr1[x])
        {
            temp[z] = arr1[x];
            z++;
        }
        x++;
    }


    while (y < size2)
    {
        if (z == 0 || temp[z - 1] != arr2[y])
        {
            temp[z] = arr2[y];
            z++;
        }
        y++;
    }


    mergedSize = z;


    float* result = new float[mergedSize];
    for (int i = 0; i < mergedSize; i++)
    {
        result[i] = temp[i];
    }

    delete[] temp;
    return result;
}
void mainoption1() {
    cout << "hello dear user" << endl;
    cout << "Enter the size of the integer array" << endl;
    int size;
    cin >> size;
    int* arr1;
    if (createArray(arr1, size))
    {
        cout << "Array created successfully" << endl;
    }
    else
    {
        cout << "Array creation failed" << endl;
    }

    cout << "Enter the size of the float array" << endl;
    int size2;
    cin >> size2;
    float* arr2;
    if (createArray(arr2, size2))
    {
        cout << "Array created successfully" << endl;
    }
    else
    {
        cout << "Array creation failed" << endl;
        delete[] arr1;
    }

    cout << "The integer array is" << endl;
    printArray(arr1, size);
    cout << "The float array is" << endl;
    printArray(arr2, size2);

    int mergedSize;
    float* arr3 = arraymerge(arr1, arr2, size, size2, mergedSize);

    cout << "The merged array is" << endl;
    printArray(arr3, mergedSize);


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}
void mainoption2() {

    int numStrings;

    // Prompt the user to enter the number of strings
    cout << "Enter the number of strings: ";
    cin >> numStrings;
    cin.ignore(); // Clear the newline character left by cin

    // Dynamically allocate memory for the array of string pointers
    char** stringArray = new char*[numStrings];

    // Read strings from the user
    for (int i = 0; i < numStrings; i++) {
        stringArray[i] = readString();
    }

    // Print the original array of strings
    cout << "\nOriginal ";
    printStrings(stringArray, numStrings);

    // Sort the array of strings using Quick Sort
    quickSort(stringArray, 0, numStrings - 1);

    // Print the sorted array of strings
    cout << "\nSorted ";
    printStrings(stringArray, numStrings);

    // Free allocated memory
    freeMemory(stringArray, numStrings);

}
char* readString(int maxLength) {
    char* str = new char[maxLength + 1]; // Allocate memory for the string
    cout << "Enter a string (up to " << maxLength << " characters): ";
    cin.getline(str, maxLength + 1); // Read input
    return str;
}
void printStrings(char** strings, int size) {
    cout << "Strings:" << endl;
    for (int i = 0; i < size; i++) {
        cout << strings[i] << endl;
    }
}
int partition(char** strings, int low, int high) {
    char* pivot = strings[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(strings[j], pivot) < 0) {
            i++;
            swap(strings[i], strings[j]);
        }
    }
    swap(strings[i + 1], strings[high]);
    return i + 1;
}
void quickSort(char** strings, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(strings, low, high);
        quickSort(strings, low, pivotIndex - 1);
        quickSort(strings, pivotIndex + 1, high);
    }
}
void freeMemory(char** strings, int size) {
    for (int i = 0; i < size; i++) {
        delete[] strings[i];
    }
    delete[] strings;
}








