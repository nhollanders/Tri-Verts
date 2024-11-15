#include <iostream>

using namespace std;

const int minNum = 1;
const int maxNum = 50;

void printChars(char c, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << c;
    }
}

void displayTriangle(int numberPar)
{
    int number = 1;
    int numbersPerRow = 1;

    int leftSpaces = numberPar * 2;
    int middleSpaces = 3;

    for (int i = 0; i < numberPar; i++)
    {
        printChars(' ', leftSpaces);
        leftSpaces--;
        
        for (int j = 0; j < numbersPerRow; j++)
        {
            cout << number;

            if (number > 9 && number < 100)
            {
                middleSpaces = 2;
            } else if (number > 99 && number < 1000)
            {
                middleSpaces = 1;
            } else if (number > 1000)
            {
                middleSpaces = 0;
            }

            printChars(' ', middleSpaces);
            number++;
        }
        cout << endl;
        numbersPerRow++;

        if (i < numberPar - 1)
        {
            printChars(' ', leftSpaces);
            
            for (int j = 0; j < numbersPerRow - 1; j++)
            {
                cout << "/ \\ ";
            }
            cout << endl;
            leftSpaces--;
        }
    }
}

int main()
{
    cout << "Enter a whole number between " << minNum << " and " << maxNum << ": ";
    string input;
    int number;
    getline(cin, input);

    try
    {
        number = stoi(input);
        if (number < minNum || number > maxNum)
        {
            throw;
        }
    }
    catch (...)
    {
        cout << "Invalid input!" << endl;
        return 0;
    }

    displayTriangle(number);

    return 0;
}