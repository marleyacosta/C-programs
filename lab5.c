/*********************************************************************
 * Program Description: This program counts the number of one(1) bits and zero (0) bits in the binary version of the number
 * Name: Maurely Acosta
 * Panther ID: 3914479
 * Certification: I hereby certify that this work is my own and none of it is the work of any other person.
 * ********************************************************************/

 #include <stdio.h>
 #include <stdlib.h>

long binaryConverter(int decimal);
int * bitCounter(long binaryNumber);

int main(){

  int proceed = 1;
  int number;
  int *p;

  while(proceed){


    printf("Enter an integer number: ");
    scanf("%d", &number);

    long binaryNum = binaryConverter(number);

    printf("num: %ld\n", binaryNum);
    p = bitCounter(binaryNum);
    printf("one: %d and zero: %d \n", *(p + 0), *(p + 1));

    printf("Want to enter another integer number? Enter (1) to continue or (0) to stop.\n");
    scanf("%d", &proceed);

  }

  return 0;
}

// This method converts a decimal number to a binary.
long binaryConverter(int decimal){

  int remainder;

  long binary = 0, i = 1;

  while( decimal != 0 ){

    remainder = decimal % 2;
    decimal = decimal / 2;
    binary = binary + ( remainder * i );
    i = i * 10;
  }
  return binary;
}

/* This method returns an array of size 2 that contains the zero
 and one count of a binary number
*/
int *  bitCounter(long binaryNumber){
  int oneCount;
  int zeroCount;
  static int r[2];

  while( binaryNumber ){

    int count = binaryNumber % 10;

    if(count){
      oneCount++;
    }
    else{
      zeroCount++;
    }
    binaryNumber /= 10;
  }
  r[0] = oneCount;
  r[1] = zeroCount;
  return r;
}
