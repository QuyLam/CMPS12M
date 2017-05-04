//---------------------------------------------------------------------------
// Quy Lam
// qlam
// 12M
// 05/20/16    
//-----------------------------------------------------------------------------
// DictionaryTest.c                                                          
// Test client for the Dictionary ADT                                        
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Dictionary.h"

#define MAX_LEN 180

int main(int argc, char* argv[]){
  Dictionary A = newDictionary();
  char* k;
  char* v;
  char* word1[] = {"one","two","three","four","five","six","seven"};
  char* word2[] = {"1","2","-2","hello","world","!!!","end"};
  int i;

  printf("%s %s \n","test isEmpty is ",  (isEmpty(A)?"true":"false"));


  for(i=0; i<7; i++){
    insert(A, word1[i], word2[i]);
  }
  //  insert(A,"one","2");
  printDictionary(stdout, A);

  for(i=0; i<7; i++){
    k = word1[i];
    v = lookup(A, k);
    printf("key=\"%s\" %s\"%s\"\n", k, (v==NULL?"not found ":"value="), v);
  }
  delete(A, "one");
  delete(A, "three");
  delete(A, "seven");
  printDictionary(stdout, A);

  printf("%s %s \n","test isEmpty is ", (isEmpty(A)?"true":"false"));

  insert(A,"one","this");
  insert(A,"three","is");
  insert(A,"seven","it");


  for(i=0; i<7; i++){
    k = word1[i];
    v = lookup(A, k);
    printf("key=\"%s\" %s\"%s\"\n", k, (v==NULL?"not found ":"value="), v);
  }

  // delete(A, "one");  // error: key not found

  printf("%s %s \n","test isEmpty is ", (isEmpty(A)?"true":"false"));
  printf("%d\n", size(A));
  makeEmpty(A);
  printf("%s %s \n","test isEmpty is ", (isEmpty(A)?"true":"false"));

  freeDictionary(&A);
  printDictionary(stdout, A);
  printf("%d\n", size(A));

}
