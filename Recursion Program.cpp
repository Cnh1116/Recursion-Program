//
// Author: Carson Holland
//
// The program will prompt the user to enter an integer >= 5. 
// This represents the size of an array.
// The program then randomly populates the array with random 
// integers in a given range. Then, various recursive functions
// perform random tasks to the array or the specific elements of // the array.
#include <stdlib.h>
#include <iomanip>
#include<time.h>
#include <iostream>
using namespace std;

//Function Prototypes--------------------------------------------------------------------
void PopulateArray(int intArray[], int arraySize);
void ReverseArrayDisplay(int intArray[], int arraySize);
void DisplayIndexSquares(int counter, int arraySize);
void DisplayThirdVertically(int third, int r, int counter, int digits[]);
int SumOfFirst(int first, int r, int sum);
bool IsPrime(int last, int n);
//Main--------------------------------------------------------------------
int main()
{
    //Variable Declarations
    int arraySize;
    int digits[4];
    int counter = 1;
    const int ARRAY_MINIMUM = 5;

    //Start up output
    cout << "*** Welcome to My Recursion APP ***\n\n";
    cout << "Enter The array size. ( Must be >= 5 ) --> ";

    //User Input for array size
    cin >> arraySize;
    int intArray[arraySize];

    //If Array size is valid:
    if (arraySize >= ARRAY_MINIMUM)
    {
        //PA #5 DRIVER LOGIC ALL HERE--------------------------------------------
        PopulateArray(intArray, arraySize);

        cout << "\n\nThe Reversed Array is: ";
        ReverseArrayDisplay(intArray, arraySize);

        cout << "\n\nTable of square values from 1 to " << arraySize << " is: \n\n";
        cout << "N         N Squared\n";
        DisplayIndexSquares(counter, arraySize);

        cout << "\nThe Sum of the First number's digits: " << SumOfFirst(intArray[0], 0, 0);

        cout << "\n\n" << intArray[2] << " in Vertical lines: \n\n";
        DisplayThirdVertically(intArray[2], 0, 0, digits);

        cout << "\nIs " << intArray[arraySize-1] << " prime?: ";
        if(IsPrime(intArray[arraySize-1], 2))//2 Is the first divisibility Check
            cout << intArray[arraySize-1] << " is a prime number.";
        else
            cout << intArray[arraySize-1] << " is not a prime number.\n";
    }
    //If array size is not valid:
    else
    {
        cout << "\nInvalid array size. Size must >= 5.\n";
    }

    cout << "\n\n\n\nCarson Holland - Director \nTweak Programming Group - March 2022\n\n";
}

//Function Definitions
void PopulateArray(int intArray[], int arraySize)
{
    const int NUMBER_OF_VALUES = 6791;
    const int OFFSET = 105;

    cout << "\nThe generated array is: ";
    srand(time(NULL)); //Seeds the random number generator
    for(int i=0; i<arraySize; i++) //Loop SIZE iterations to populate the array
    {
        intArray[i] = rand() % NUMBER_OF_VALUES + OFFSET ; //Generates a Random Number from 105 - 6896
        cout << intArray[i] << " ";
    }
}
void ReverseArrayDisplay(int intArray[], int arraySize)
{
    if (arraySize == 0)
        return;
    else
    {
        cout << intArray[arraySize-1] << " ";
        ReverseArrayDisplay(intArray, arraySize-1);
    }
}
void DisplayIndexSquares(int counter, int arraySize)
{
    if (counter > arraySize)
        return;
    else
    {
        cout << counter << "         ";
        cout << (counter*counter) << "\n";
        DisplayIndexSquares(counter+1, arraySize);
    }
}
void DisplayThirdVertically(int third, int r, int counter, int digits[])
{
    if (third == 0)//Once the digits have been found, loops displays it in reverse
    {
        for (counter=counter-1; counter>=0; counter--)
        {
            cout << digits[counter] << "\n";
        }
        return;
    }

    else //This Algorithm Finds the digits of the number in reverse
    {
    r = third % 10;
    digits[counter] = r; //Digits stored in a temporary array
    third = third/10;
    DisplayThirdVertically(third, r, counter+1, digits);
    }
}
//First is the first number in the array. R is a variable used for extracting the digits. Sum is the sum of the digits
int SumOfFirst(int first, int r, int sum)
{
    if (first == 0)
        return sum;
    else
    {
        r = first % 10;
        sum += r;
        first = first/10;
        SumOfFirst(first, r, sum);
    }
}
//Last is the last number in the array. N is a counter variable used for divisibility check.
bool IsPrime(int last, int n)
{
    if (n == last)
        return true;
    else
    {
        if(last % n == 0)
            return false;
        IsPrime(last, n+1);
    }
}
