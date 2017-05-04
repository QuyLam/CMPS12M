#---------------------------------------------------------------------------
# Quy Lam
# qlam
# 12m
# 05/25/16    
#------------------------------------------------------------------------------
#   Makefile for List ADT
#------------------------------------------------------------------------------

# Variables
JARFILE    = ListClient
MAINCLASS  = ListClient
SOURCES    = List.java ListInterface.java ListClient.java\
             ListIndexOutOfBoundsException.java ListTest.java
FILE 	   = Makefile List.java ListInterface.java ListClient.java\
	     ListIndexOutOfBoundsException.java ListTest.java 
CLASSES    = List.class ListInterface.class ListClient.class List\$$Node.class\
             ListIndexOutOfBoundsException.class
SUBMIT     = submit  cmps012b-pt.s16 lab6 
CHECK      = ls /afs/cats.ucsc.edu/class/cmps012b-pt.s16/lab6/qlam
# Build Targets
all: $(JARFILE)

$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(CLASSES)
	rm Manifest
	chmod +x $(JARFILE)

$(CLASSES): $(SOURCES)
	javac -Xlint $(SOURCES)  

clean:
	rm -f $(CLASSES) $(JARFILE)

submit: $(FILE)
	$(SUBMIT) $(FILE)

check :
	$(CHECK)


