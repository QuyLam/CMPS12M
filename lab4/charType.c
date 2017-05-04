//---------------------------------------------------------------------------   
// Quy Lam                                                                      
// qlam                                                                         
// 12M                                                                          
// 05/02/16                                                                     
//-----------------------------------------------------------------------------
// charType.c
// 
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>
#include<string.h>

#define MAX_STRING_LENGTH 100

// function prototype 
void extract_chars(char* s, char* a, char* d, char* punct, char* white_sp);

// function main which takes command line arguments 
int main(int argc, char* argv[]){
  FILE* in;        // handle for input file                  
  FILE* out;       // handle for output file                 
  char* line;      // string holding input line              
  char* alpha; // string holding all alphabetic chars 
  char* digit;  //string holding all numeric chars
  char* punct; //string holding all punctuation chars
  char* space; //string holding all whitespace chars
  int line_count=1;

  // check command line for correct number of arguments 
  if( argc != 3 ){
    printf("Usage: %s input-file output-file\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // open input file for reading 
  if( (in=fopen(argv[1], "r"))==NULL ){
    printf("Unable to read from file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // open output file for writing 
  if( (out=fopen(argv[2], "w"))==NULL ){
    printf("Unable to write to file %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  // allocate strings line and alpha, digit, punct, space on the heap 
  line = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
  alpha = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
  digit = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
  punct = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
  space = calloc(MAX_STRING_LENGTH+1, sizeof(char) );

  assert( line!=NULL && alpha!=NULL && digit!=NULL && punct!=NULL && space!=NULL );

  // read each line in input file, extract alpha-numeric characters 
  while( fgets(line, MAX_STRING_LENGTH, in) !=NULL ){
  
    extract_chars(line, alpha, digit, punct, space);
    int a = strlen(alpha);
    int d = strlen(digit);
    int p = strlen(punct);
    int s = strlen(space);

    fprintf(out, "line %d contains: \n", line_count);
    
   
    fprintf(out,"%d alphabetic character%s: %s\n", a, a==1?" ":"s", alpha);
    fprintf(out,"%d numeric character%s: %s\n", d , d==1?"":"s", digit);
    fprintf(out, "%d punctuation character%s: %s\n", p, p==1?"":"s", punct);
    fprintf(out, "%d whitespace character%s: %s\n", s, s==1?"":"s", space);
       
    line_count++;

  }

  // free heap memory 
  free(line);
  free(alpha);
  free(digit);
  free(punct);
  free(space);

  // close input and output files 
  fclose(in);
  fclose(out);
  
  return EXIT_SUCCESS;
}

// function definition 
void extract_chars(char* s, char* a,char* d, char* p, char* w){
  int i=0, j=0, k=0, l=0, m=0;
  while(s[i]!='\0' && i<MAX_STRING_LENGTH){
    if( isalpha( (int)s[i]) ){
      a[j++] = s[i];
      i++;
    }
    else if( isdigit( (int)s[i]) ){ 
      d[k++] = s[i];
      i++;
    }
    else if( ispunct( (int)s[i]) ){
      p[l++] = s[i];
      i++;
    }
    else if( isspace( (int)s[i]) ){
      w[m++] = s[i];
      i++;
    }
  }
    a[j] = '\0';
    d[k] = '\0';
    p[l] = '\0';
    w[m] = '\0';
}

