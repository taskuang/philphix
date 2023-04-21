/*
 * Include the provided hash table library.
 */
#include "hashtable.h"

/*
 * Include the header file.
 */
#include "philphix.h"

/*
 * Standard IO and file routines.
 */
#include <stdio.h>

/*
 * General utility routines (including malloc()).
 */
#include <stdlib.h>

/*
 * Character utility routines.
 */
#include <ctype.h>

/*
 * String utility routines.
 */
#include <string.h>

/*
 * This hash table stores the dictionary.
 */
HashTable *dictionary;

/*
 * The MAIN routine.  You can safely print debugging information
 * to standard error (stderr) as shown and it will be ignored in
 * the grading process.
 */
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Specify a dictionary\n");
    return 1;
  }
  /*
   * Allocate a hash table to store the dictionary.
   */
  fprintf(stderr, "Creating hashtable\n");
  dictionary = createHashTable(0x61C, &stringHash, &stringEquals);

  fprintf(stderr, "Loading dictionary %s\n", argv[1]);
  readDictionary(argv[1]);
  fprintf(stderr, "Dictionary loaded\n");

  fprintf(stderr, "Processing stdin\n");
  processInput();

  /*
   * The MAIN function in C should always return 0 as a way of telling
   * whatever program invoked this that everything went OK.
   */
  return 0;
}
/*
 * This should hash a string to a bucket index.  Void *s can be safely cast
 * to a char * (null terminated string)
 */
unsigned int stringHash(void *s) {
  // -- TODO --
  char *str = (char *)s;
  unsigned long hash = 5381;
  int c = 0;
  while ((c = *(str++))) {
    hash = hash * 33 + c;
  }
  return hash;
  /*
   * Source: Dan Bernstein's djb2 algorithm

   * */

}


/*
 * This should return a nonzero value if the two strings are identical
 * (case sensitive comparison) and 0 otherwise.
 */
int stringEquals(void *s1, void *s2) {
  // -- TODO -- //
  return strcmp((char *) s1, (char *) s2) == 0;
}


/*
 * This function should read in every word and replacement from the dictionary
 * and store it in the hash table.  You should first open the file specified,
 * then read the words one at a time and insert them into the dictionary.
 * Once the file is read in completely, return.  You will need to allocate
 * (using malloc()) space for each word.  As described in the spec, you
 * can initially assume that no word is longer than 60 characters.  However,
 * for the final bit of your grade, you cannot assumed that words have a bounded
 * length.  You CANNOT assume that the specified file exists.  If the file does
 * NOT exist, you should print some message to standard error and call exit(61)
 * to cleanly exit the program.
 */
void readDictionary(char *dictName) {
  // -- TODO --
  FILE * dict = fopen(dictName, "r");
  if (dict == NULL) {
    fprintf(stderr, "The file does not exist");
    exit(61);
  }
  char current = fgetc(dict);
  while (current != EOF) {
    int count = 0;
    int length = 60;
    char *key = malloc(60);
    while (isalnum(current)) {
      if (count >= length) {
        length *= 2;
        key = realloc(key, length);
      }
      key[count] = current;
      current = fgetc(dict);
      count++;
    }
    key[count] = '\0';
    while (isspace(current)) {
      current = fgetc(dict);
    }
    length = 60;
    count = 0;
    char *data = malloc(60);
    while (isprint(current)) {
      if (count >= length) {
        length *= 2;
        data = realloc(data, length);
      }
      data[count] = (char) current;
      current = fgetc(dict);
      count++;
      }
    data[count] = '\0';
    insertData(dictionary, key, data);
    current = fgetc(dict);
    }
  fclose(dict);
  }


/*
 * This should process standard input (stdin) and perform replacements as
 * described by the replacement set then print either the original text or
 * the replacement to standard output (stdout) as specified in the spec (e.g.,
 * if a replacement set of `taest test\n` was used and the string "this is
 * a taest of  this-proGram" was given to stdin, the output to stdout should be
 * "this is a test of  this-proGram").  All words should be checked
 * against the replacement set as they are input, then with all but the first
 * letter converted to lowercase, and finally with all letters converted
 * to lowercase.  Only if all 3 cases are not in the replacement set shoud
 * it report the original word.
 *
 * Since we care about preserving whitespace and pass through all non alphabet
 * characters untouched, scanf() is probably insufficent (since it only considers
 * whitespace as breaking strings), meaning you will probably have
 * to get characters from stdin one at a time.
 *
 * Do note that even under the initial assumption that no word is longer than 60
 * characters, you may still encounter strings of non-alphabetic characters (e.g.,
 * numbers and punctuation) which are longer than 60 characters. Again, for the
 * final bit of your grade, you cannot assume words have a bounded length.
 */
void processInput() {
  // -- TODO
  char *orig = malloc(60);
  char *first = malloc(60);
  char *lower = malloc(60);
  int counter = 0;
  int current = getchar();
  int length = 60;
  while(current != EOF) {
    if(isalnum(current)) {
      orig[counter] = (char) current;
      if (counter != 0) {
        first[counter] = (char) tolower(current);
      } else {
        first[counter] = (char) current;
      }
      lower[counter] = (char) tolower(current);
      counter++;
      if(counter >= length) {
        length *= 2;
        orig = realloc(orig, length);
        first = realloc(first, length);
        lower = realloc(lower, length);
      }
    } else {
     orig[counter] = '\0';
     first[counter] = '\0';
     lower[counter] = '\0';
     char *data1 = findData(dictionary, orig);
     char *data2 = findData(dictionary, first);
     char *data3 = findData(dictionary, lower);
     if (data1 != NULL) {
       fprintf(stdout, "%s", data1);
     } else if (data2 != NULL) {
       fprintf(stdout, "%s", data2);
     } else if (data3 != NULL) {
       fprintf(stdout, "%s", data3);
     } else {
       fprintf(stdout, "%s", orig);
     }
     fprintf(stdout, "%c", current);
     counter = 0;
     free(orig);
     free(first);
     free(lower);
     orig = malloc(60);
     first = malloc(60);
     lower = malloc(60);
   }
   current = getchar();
  }
  if (counter != 0) {
    orig[counter] = '\0';
    first[counter] = '\0';
    lower[counter] = '\0';
    char *data1 = findData(dictionary, orig);
    char *data2 = findData(dictionary, first);
    char *data3 = findData(dictionary, lower);
    if (data1 != NULL) {
      fprintf(stdout, "%s", data1);
    } else if (data2 != NULL) {
      fprintf(stdout, "%s", data2);
    } else if (data3 != NULL) {
      fprintf(stdout, "%s", data3);
    } else {
      fprintf(stdout, "%s", orig);
    }
  }
  free(orig);
  free(first);
  free(lower);
}
