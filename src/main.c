// Cristobal Chinolla
// Lab 1 tokenizer
// Main File UI

#include <stdio.h>
#include <stdlib.h>
#include "history.c"
#include "tokenizer.c"
#define MAX_LENGTH 32 // MAX STRING SIZE ENTERED BY A USER


// FUNCTION DECLARATIONS
int strcmp(char *str1, char *str2);
int str_to_num(char *str);
// ------------------------------------------------------------------------------

int main()
{
  List *history = init_history(); // INITIALIZES HISTORY
  char **tokens // INITIALIZES TOKENS
  char str[MAX_LENGTH]
  char c;
  int i, index = 0; // i IS FOR INDEX OF str, index IS FOR get history function

  printf("\tWELCOME");
  printf("\n--------------------------------------\n");
  printf("COMMANDS: \"q\" TO EXIT\n");
  printf("                  \"history\" TO VIEW HISTORY\n");
  printf("                  \"!n\" PRINT (n) INDEX HISTORY\n");
  printf("ENTER A STRING TO BE TOKENIZED \n");
  while (strcmp(str,"q") != 0) // while str is not the same a 'q'
  {
    printf("\n> ");
    i = 0;
    while ( (c = getchar()) != '\n') // store char one by one into str until newline character is detected (enter)
    {
      str[i] = c;
      i++;
    }

    str[i] = '\0';                   // places a null character into the last index of str

    if(strcmp(str,"q") == 0) // if user enters 'q' to exit
    {
      goto done;
    }
    else if (strcmp("history",str) == 0) // if user enters 'history' to view history
    {
       print_history(history);
    }
    else if (str[0] == '!') // if user enters '!n'
    {
      index  = str_to_num(str+1);          // If string begins with !, get string of item
      printf("%s", get_history(history,index)); // with id of the number that follows !
      printf("%d\n",index);
    }
    else
    {
      tokens = tokenize(str);  // tokenize the string entered
      print_tokens(tokens);   // prints tokens
      free_tokens(tokens);
      add_history(history,copy_str(str,i)); // adds str to history of tokenized strings
    }
  }
 done:
  free_history(history);  // frees history
  return 0;
}

// Compares the value of two strings.
int strcmp(char *str1, char *str2)
{
  int i;
  for (i = 0; str1[i] == str2[i]; i++) { // Compares each character while they are the same
    if ( str1[i] == '\0') return 0; // If loops reaches null terminal character, the strings are
  }                                //  equal.
  return str1[i] - str2[i]; // Returns positive number if str1 > str2, otherwise negative.
}

// Converts a string number to an integer
int str_to_num(char *str)
{
  int number = 0;
  int i = 0;
  while (str[i] != '\0') {           // For each digit in string multiply by 10
    number = number * 10;
    number = number + (str[i]-'0');  // Gets the numeric value of the character and adds
    i++;
  }
  return number;
}
