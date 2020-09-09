#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "F2.h"



//--------------Main program---------------\\

int main()
{

    char answer[100];
    int c1, n1, d1;
    int c2, n2, d2;
    int index = 0;

    c1 = 1;
    n1 = 1;
    d1 = 2;

    c2 = 2;
    n2 = 2;
    d2 = 3;

        //if the C string could hold at least the characteristic
    if(add(c1, n1, d1, c2, n2, d2, answer, 100))
    {
        while(answer[index] != '\0')
        {
            printf(answer[index]);
            index++;
        }
    }
    else
    {
        printf("Array size was not large enough");
    }




    return 0;
}


//-------------Functions---------------\\

//takes in two sets of mantissa and characteristic, a char array to store
//result in and the length of the array.

//c = characteristic
//n & d = numerator and denominator of characteristic
//Ex: 0.352 -> c = 0, n = 351 & d = 1000

//Note: result data will be lost if array is passed in anonymously
bool add(int c1, int n1, int d1,
         int c2, int n2, int d2,
         char result[], int len)
{
  //base case, not enough to store characteristic
  if(len <= 1)
  {
    return false;
  }

  int sizeNeeded = ((n1 + n2) / 10) + 1;
  int resultArrIndex = 0;
  int tempArrIndex = 0;
  int numLSD1;
  int numLSD2;
  int numResult;
  int tempResult[sizeNeeded];
  int charResult = c1 + c2;
  bool carry = false;



  result[resultArrIndex] = (char) charResult;
  resultArrIndex++;
  result[resultArrIndex] = '.';

  //loop while denominators are not zero, takes off the end of each
  //numerator, then adds them
  //update: divide denominators by 10
  while((d1 > 0 || d2 > 0) && tempArrIndex < len - 1)
  {

    numLSD1 = n1 % 10;
    numLSD2 = n2 % 10;

    numResult = numLSD1 + numLSD2;

    if(carry)
    {
      numResult++;
      carry = false;
    }

    if(numResult > 9)
    {
      numResult %= 10;
      carry = true;
    }

    tempResult[tempArrIndex] = numResult;

    tempArrIndex++;
    d1 /= 10;
    d2 /= 10;

    n1 /= 10;
    n2 /= 10;

  }

  while(resultArrIndex < len - 1)
  {

    result[resultArrIndex] = (char) tempResult[tempArrIndex];

    resultArrIndex++;
    tempArrIndex--;

  }

  result[resultArrIndex] = '\0';

  return true;

}

//takes in two sets of mantissa and characteristic, a char array to store
//result in and the length of the array.

//c = characteristic
//n & d = numerator and denominator of characteristic
//Ex: 0.352 -> c = 0, n = 351 & d = 1000

//Note: result will be lost if array is passed in anonymously
bool subtract(int c1, int n1, int d1,
              int c2, int n2, int d2,
              char result[], int len)
{
    //base case, not enough to store characteristic
    if(len <= 1)
    {
        return false;
    }
    
    // Initialize and Setup Variables
    int sizeNeeded = ((n1 + n2) / 10) + 1;
    int resultArrIndex = 0;
    int tempArrIndex = 0;
    int numLSD1;
    int numLSD2;
    int numResult;
    int tempResult[sizeNeeded];
    int charResult = c1 - c2;
    bool carry = false;

    result[resultArrIndex] = (char) charResult;
    resultArrIndex++;
    result[resultArrIndex] = '.';
    
    //loop while denominators are not zero, takes off the end of each
    //numerator, then subtracts them
    //update: divide denominators by 10
    
    while((d1 > 0 || d2 > 0) && tempArrIndex < len - 1)
    {

        numLSD1 = n1 % 10;
        numLSD2 = n2 % 10;

        numResult = numLSD1 - numLSD2;

        if(carry)
        {
            numResult++;
            carry = false;
        }

        if(numResult > 9)
        {
            numResult %= 10;
            carry = true;
        }

        tempResult[tempArrIndex] = numResult;

        tempArrIndex++;
        d1 /= 10;
        d2 /= 10;

        n1 /= 10;
        n2 /= 10;

    }

    
    // Pass result into resulting array
    while(resultArrIndex < len - 1)
    {

        result[resultArrIndex] = (char) tempResult[tempArrIndex];
        resultArrIndex++;
        tempArrIndex--;

    }

    // Add end char to end of array
    result[resultArrIndex] = '\0';

    return true;
}
