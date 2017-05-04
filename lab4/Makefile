#---------------------------------------------------------------------------   
# Quy Lam                                                                      
# qlam                                                                         
# 12M                                                                          
# 05/02/16                                                                     
#-----------------------------------------------------------------------------
# Makefile
# makefile for charType.c with Macros
#------------------------------------------------------------------------------

FLAGS = -std=c99 -Wall
SOURCES = charType.c
OBJECTS = charType.o
EXEBIN = charType
FILES = $(SOURCES) README Makefile
SUBMIT = submit cmps012b-pt.s16 lab4
CHECK = ls /afs/cats.ucsc.edu/class/cmps012b-pt.s16/lab4/qlam

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm $(EXEBIN) $(OBJECTS)

submit : $(FILES)
	$(SUBMIT) $(FILES)

check : 
	$(CHECK)
