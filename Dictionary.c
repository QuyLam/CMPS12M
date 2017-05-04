//---------------------------------------------------------------------------
// Quy Lam                                                                    
// qlam                                                                      
// 12M                                                                      
// 05/10/16                                                                
//-------------------------------------------------------------------------
// Dictionary.                                                              
//-----------------------------------------------------------------------------
// Dictionary.c
// Implementation file for IntegerStack ADT in C
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Dictionary.h"

// private types --------------------------------------------------------------

// NodeObj 
typedef struct NodeObj{
  char* key;
  char* value;
  struct NodeObj* next;
} NodeObj;

// Node
typedef NodeObj* Node;

//newNode()
// constructor of the Node type
Node newNode(char* key, char* value){
  Node N = malloc(sizeof(NodeObj));
  N->key = key;
  N->value = value;
  N->next = NULL;
  return(N);
}  
//freeNode()
// destructor for the Node type
void freeNode(Node* pN){
  if( pN!=NULL && *pN!=NULL ){
    free(*pN);
    *pN = NULL;
  }
}
// DictionaryObj
typedef struct DictionaryObj{
  Node head;
  Node tail;
  int numItems;
} DictionaryObj;

// public functions -----------------------------------------------------------

// newDictionary()
// constructor for the Dictionary type
Dictionary newDictionary(void){
  Dictionary D = malloc(sizeof(DictionaryObj));
  assert(D!=NULL);
  D->head = NULL;
  D->tail = NULL;
  D->numItems = 0;
  return D;
}

// freeDictionary()
// destructor for the Dictionary type
void freeDictionary(Dictionary* pD){
  if( pD!=NULL && *pD!=NULL ){
    if( !isEmpty(*pD) ) makeEmpty(*pD);
    free(*pD);
    *pD = NULL;
  }
}


// isEmpty()
// returns 1 (true) if S is empty, 0 (false) otherwise
// pre: none
int isEmpty(Dictionary D){
  if( D==NULL ){
    fprintf(stderr, 
	    "Stack Error: calling isEmpty() on NULL Stack reference\n");
    exit(EXIT_FAILURE);
  }
  return(D->numItems==0);
}


// size()
// returns the number of (key, value) pairs in D
// pre: none
int size(Dictionary D){
  return D->numItems;
}

// lookup()
// returns the value v such that (k, v) is in D, or returns NULL if no 
// such value v exists.
// pre: none
char* lookup(Dictionary D, char* k){
  Node N = D->head;
  if( D==NULL ){
    fprintf(stderr, 
	    "Stack Error: calling isEmpty() on NULL Stack reference\n");
    exit(EXIT_FAILURE);
  }
  while(N != NULL){
    if( strcmp(N->key,k)== 0 ){
      return N->value;
    }
    N = N->next;
  }
  return NULL;
}

// insert()
// inserts new (key,value) pair into D
// pre: lookup(D, k)==NULL
void insert(Dictionary D, char* k, char* v){
  if(lookup(D,k) != NULL){  
    fprintf(stderr, 
	    "Stack Error: calling isEmpty() on NULL Stack reference\n");
    exit(EXIT_FAILURE);
  }
  if(D->numItems==0){
    D->head = D->tail = newNode(k,v);
    }else{
    Node N = newNode(k,v);
    D->tail->next = N;
      D->tail = N;
  }
    D->numItems++;
}

// delete()
// deletes pair with the key k
// pre: lookup(D, k)!=NULL
void delete(Dictionary D, char* k){
  if(lookup(D,k)==NULL){
    fprintf(stderr, 
	    "Stack Error: calling isEmpty() on NULL Stack reference\n");
    exit(EXIT_FAILURE);
  }

  Node N = D->head;

  
  if(strcmp(N->key,k) ==0){
    Node C = N->next;
    D->head = C;
    freeNode(&N);
  }else{
  while(N != NULL && N->next != NULL){
    if(strcmp(N->next->key,k) == 0){
      Node P = N->next;
      Node C = P->next;
      N->next = C;
      freeNode(&P);
      }
    N = N->next;
    }
  }
  D->numItems--;
}
 
// makeEmpty()
// re-sets D to the empty state.
// pre: none
void makeEmpty(Dictionary D){
  freeNode(&(D->head));
  D->numItems = 0;
}

// printDictionary()
// pre: none
// prints a text representation of D to the file pointed to by out
void printDictionary(FILE* out, Dictionary D){
  Node N;
  if( D==NULL ){
    fprintf(stderr, 
	    "Dictionary Error: calling printDictionary() on NULL Stack reference\n");
    exit(EXIT_FAILURE);
  }
  for(N=D->head; N!=NULL; N=N->next) fprintf(out, "%s %s  \n",N->key, N->value);
  //  fprintf(out, "\n");
}

//#endif



   







                                            
