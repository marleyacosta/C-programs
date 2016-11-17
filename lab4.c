/*********************************************************************
 * Program Description: This program finds the largest and smallest words in a string input by the user or coming from a file.
 * Name: Maurely Acosta
 * Panther ID: 3914479
 * Certification: I hereby certify that this work is my own and none of it is the work of any other person.
 * ********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// The method headers.
void userInput();
void fileReader(char *file);

// adding this comment to test github desktop

const char * smallestWord(char *sentence);
const char * largestWord(char *sentence);

static char usage[] = "Usage: lab4 [filename]\n";

int main(int argc, char *argv[]) {

   if( argc == 1 ){ // if a file name was not given.

     userInput();
   }
   else if( argc == 2 ){ // if a file name was given.

     char *filename = argv[1];
     fileReader(filename);
   }
   else{ // else it's an error.
     fprintf(stderr, usage, argv[0]);
     exit(EXIT_FAILURE);
   }

   return 0;
}

// This user extracts user input.
void userInput(){

  char stringInput[100];
  char stringInputCopy[100];

  printf("Enter the string:\n");
  scanf(" %[^\n]", stringInput); // get the sentence entered by the user.
  strcpy(stringInputCopy, stringInput);

  const char * b = largestWord(stringInputCopy);
  const char * a = smallestWord(stringInput);

  printf("The smallest word is '%s' and the largest word is '%s'.\n", a, b );
}

// This function reads a file and extracts a sentence.
void fileReader(char *filename){

  FILE *fp = NULL;
  fp = fopen(filename, "r");

  if(!fp){ // check if such a file exist.

    fprintf(stderr, "ERROR: The file %s was not found.\n", filename);
  }

  char stringInput[100] ;
  char stringInputCopy[100];

  fgets(stringInput, sizeof(stringInput), fp);
  strtok(stringInput, "\n"); // remove new line from line extracted.
  strcpy(stringInputCopy, stringInput); // make a copy of stringInput

  const char * b = largestWord(stringInputCopy);
  const char * a = smallestWord(stringInput);

  printf("The smallest word is '%s' and the largest word is '%s'. \n", a, b);

  fclose(fp);
}

// This function calculates the samllest word in a sentence.
const char * smallestWord(char *sentence){

  char *  word;
  char *  smallest;
  smallest = strtok(sentence, " ");
  word = strtok(NULL, " ");

  while(word != NULL){ // while they are words to extract.

    if( strlen( smallest ) > strlen( word ) ){ // if the the current word is less than the current smallest.

      smallest = word; // make word the new smallest word in the string.
    }

    word = strtok(NULL, " "); // get the next word.
  }

  return smallest; // return the smallest word.
}

// This function calculates the largest word in a sentence.
const char * largestWord(char *sentence){

  char *  word;
  char *  largest;
  largest = strtok(sentence, " ");
  word = strtok(NULL, " ");

  while(word != NULL){  // while they are words to extract.

    if( strlen( largest ) < strlen( word ) ){ // if the the cu rrent word is biggest than the current largest word.

      largest = word; // make the current word the largest word.
    }
    word = strtok(NULL, " "); // get the next word in the string.
  }

  return largest;
}
