#---------------------------------------------------------------------------
# Quy Lam
# qlam
# 12M
# 05/10/16    
#------------------------------------------------------------------------------
# makefile for IntegerStackClient.c with macros
#------------------------------------------------------------------------------

FLAGS   = -std=c99 -Wall
SOURCES = DictionaryClient.c Dictionary.c 
FILES   = $(SOURCES) README Makefile DictionaryClient.c Dictionary.h DictionaryTest.c
OBJECTS = DictionaryClient.o Dictionary.o
HEADERS = Dictionary.h 
EXEBIN  = DictionaryClient
SUBMIT  = submit cmps012b-pt.s16 lab5
CHECK   = ls /afs/cats.ucsc.edu/class/cmps012b-pt.s16/lab5/qlam


all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS) $(HEADERS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES) $(HEADERS)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)

check:
	valgrind --leak-check=full $(EXEBIN) 

submit : $(FILES)
	$(SUBMIT) $(FILES)

checksubmit :
	$(CHECK)
