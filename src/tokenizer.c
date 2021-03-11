// Cristobal Chinolla
// Comp Arch I || Lab 1: Tokenizer
#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

// returns 1 if a space character, 0 if not
int space_char(char c)
{
  if ( (c == '\t' || c == ' ') && c != '\0')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// returns 1 if c is a non space character, 0 if space character
int non_space_char(char c)
{
  if ( (c !=  '\t' && c != ' ') && c != '\0')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// returns a pointer to the start of the first word in a string.
char *word_start(char *s)
{
  int i = 0;
  while (space_char(s[i]))
  {
    i++;
  }
  return &s[i];
}

// Returns a pointer to the end of the given word.
char *word_terminator(char *word)
{
  word = word_start(word);   // uses word start to get rid of all empty space before the word
  int i = 0;
  while (non_space_char(word[i])) i++; // moves through the word until space char is found
  return &word[i]; // returns address of the words index of the space char
}

// Returns the number of words within a string
int count_words(char *c)
{
  int i = 0;
  int count = 0;

  // loops through string counting the times a space character follows a nonspace character.
  while (c != word_terminator(c))
  {
    c = word_terminator(c);
    count++;
  }
  return count;
}

char *copy_str(char *inputString, short len)
{
  char *outputString = malloc( (len + 1)  * sizeof(char)); // Allocates the right amount of space
  int i = 0;
  while ( i <= len) {
    outputString[i] = inputString[i]; // Assigns the ith position of new string the value of the ith
    i++;                 // value of incoming string.
  }
  return outputString;
}

char **tokenize(char *str)
{
  int i;
  int totalIndex = count_words(str);    //total indexes in string
  char **tokens = malloc( (totalIndex+1) * sizeof(char *) );// Allocates a char pointer for each word in string + 1
  char *wordStart = word_start(str); // Start of first word
  char *wordEnd = word_terminator(str); // End of first word

  for (i = 0; i < totalIndex; i++)
  {  // Uses pointer arithmetic to find length of word
    tokens[i] = copy_str(wordStart,wordEnd-wordStart);
    wordStart = word_start(wordEnd); //start of next word
    wordEnd = word_terminator(wordStart); //end of next word
  }
  tokens[i] = NULL; // sets last pointer to null;
  return tokens;
}
void print_tokens(char **tokens)
{
  int index = 0;
  while (tokens[index] != NULL) { // Loops through tokens until NULL
    printf("%s\n", tokens[index]); // prints each token;
    index++;
  }
}
void free_tokens(char **tokens)
{
  int index = 0;
  while (tokens[index] != NULL) { // Loops through tokens until NULL
    free(tokens[index]); // frees the allocated memory of the string pointed to by tokens[i]
    index++;
  }
  free(tokens); // free the allocated memory for the pointers
}
