#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function for checking if a given number is prime.
int isPrime(int number) {
    if (number == 2) {
        return 1;
    }
    if (number < 2 || number % 2 == 0) {
        return 0;
    }
    int divisor;
    for (divisor = 2; divisor <= sqrt(number); divisor++) {
        if (number % divisor == 0) {
            return 0;
        }
    }
    return 1;
}

// Function for reading the list of numbers from the console.
void readListOfNumbers(int listOfNumbers[], int* listLength) {
    char currentCharacter; // currentCharacter - the character next to the decimal number currently read.

    // Read the console input till the end of the current line (\n - new line was found).
    printf("The list of numbers: ");
    do {
        scanf("%d%c", &listOfNumbers[*listLength], &currentCharacter);
        *listLength += 1;
    } while (currentCharacter != '\n');
}

/* Function for finding the longest contiguous sub-sequence such that the difference of any
   two consecutive elements is a prime number. */
void longestSequenceOfPrimePairs(int listOfNumbers[], int listLength, int* startIndex, int* maxLength) {
    int currentIndex = 0, currentLength = 0;
    int listIndex; // listIndex - index variable for iterating the 'listOfNumbers' array.
    for (listIndex = 0; listIndex < listLength; listIndex++) {
        int difference = abs(listOfNumbers[listIndex + 1] - listOfNumbers[listIndex]);
        if (isPrime(difference)) {
            currentLength++;
            if (currentLength == 1) {
                currentIndex = listIndex;
            }
        } else {
            if (currentLength > *maxLength) {
                *maxLength = currentLength;
                *startIndex = currentIndex;
            }
            currentLength = 0;
        }
    }
}

// Function for printing to the console the sub-sequence found earlier.
void printSequenceOfNumbers(int listOfNumbers[], int startIndex, int maxLength) {
    int listIndex; // listIndex - index variable for iterating the 'listOfNumbers' array.
    for (listIndex = startIndex; listIndex < startIndex + maxLength + 1; listIndex++) {
        printf("%d ", listOfNumbers[listIndex]);
    }
}

int main() {
    int listOfNumbers[100]; // listOfNumbers[100] - a list of integers of fixed dimension (100 numbers).
    int listLength = 0; // listLength - a counter variable that keeps the number of integers stored in 'listOfNumbers'.

    readListOfNumbers(listOfNumbers, &listLength);

    int startIndex = 0, maxLength = 0; // these two variables will delimit the found sub-sequence.
    longestSequenceOfPrimePairs(listOfNumbers, listLength, &startIndex, &maxLength);

    printSequenceOfNumbers(listOfNumbers, startIndex, maxLength);

    return 0;
}