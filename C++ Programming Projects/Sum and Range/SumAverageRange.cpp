/* C++SumAverageRange.cpp
CIS054 C/C++ Programming
Name: Huy Vu
Date: 9/22/2024
Inputs: enter 10 numbers
Output: sum of odd numbers, sum of even numbers
sum of all numbers, lowest and highest number
*/
 #include <iostream>
using namespace std;

const int NUMBER_COUNT = 10;

int main (int argc, char* argv[])
{
    int sumOfOddNumbers = 0;
    int sumOfEvenNumbers = 0;
    int sumOfAllNumbers = 0;
    int maxValue = 0;
    int minValue = 0;
    int number;
    int inputCounter = 1;
    
    while (inputCounter <= NUMBER_COUNT)
    {
        cout << "Enter a number: ";
        cin >> number;

        if (number %2 == 1)
            sumOfOddNumbers += number;
        else
            sumOfEvenNumbers += number;

        sumOfAllNumbers += number;

        if (inputCounter == 1)
        {
            minValue = number;
            maxValue = number;
        }
        else 
        {
            if (number < minValue)
            minValue = number;
            if (number > maxValue)
            maxValue = number;
        }
        inputCounter++;
    }

    cout << endl;
    cout << "Sum of odd numbers: " << sumOfOddNumbers << endl;
    cout << "Sum of even numbers: " << sumOfEvenNumbers << endl;
    cout << "Sum of all numbers: " << sumOfAllNumbers << endl;
    cout << "The lowest value is: " << minValue << endl;
    cout << "The highest value is: " << maxValue << endl;
    cout << endl;

    return 0;
}