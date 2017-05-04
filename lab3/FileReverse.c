/*--------------------------------------------------------------------
 * Quy Lam
 * qlam
 * 12M
 * 04/19/2016
---------------------------------------------------------------------
 FileReverse.c
 This C program will read input file then print it backwards on a line by itself.
---------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void stringReverse(char* s){
  int i = 0, j = strlen(s)-1;
  char temp[256];
  while(i<j){      
    temp[1] = s[i];
    s[i] = s[j];
    s[j] = temp[1];
       i++;		
       j--;
     }
}


int main(int argc, char* argv[]){
  FILE* in;
  FILE* out;
  char word[256];

  /* check the command line for correct number of arguments */
  if(argc !=3){
    printf("Usage: %s <input file> <output file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  /* open input file for reading */
  in = fopen(argv[1], "r");
  if( in==NULL){
    printf("Unable to read from the file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  /* open output file for writing */
  out = fopen(argv[2], "w");
  if( out==NULL){
    printf("Unable to write to the file %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  /* read words from input file, print it backwards on a line by itself in output file */
  while( fscanf(in, "%s", word) != EOF){
    stringReverse(word);
    fprintf(out, "%s\n", word);
  }
  /* close input and output files */
  fclose(in);
  fclose(out);

  return(EXIT_SUCCESS);
}
