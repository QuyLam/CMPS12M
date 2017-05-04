#----------------------------------------------------------------------------- # Quy Lam                                                                      # qlam                                                                         # 12M                                                                          # 04/19/16                                                                     #------------------------------------------------------------------------------
# Makefile
# Makefile for FileReverse.c with Macros
#------------------------------------------------------------------------------

FLAGS = -std=c99 -Wall
SOURCES = FileReverse.c
FILES = $(SOURCES) README Makefile
OBJECTS = FileReverse.o
EXEBIN = FileReverse
SUBMIT = submit cmps012b-pt.s16 lab3
CHECK = ls /afs/cats.ucsc.edu/class/cmps012b-pt.s16/lab3/qlam

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
