#-----------------------------------------------------------------------------
# Quy Lam                                                                     
# qlam                                                                        
# 12M                                                                         
# 04/08/16                                                                    
#-----------------------------------------------------------------------------
# Makefile                                                                    
# Makefile to complile FileReverse class                                  
# A Makefile with macros                                                      
#-----------------------------------------------------------------------------  

JAVASRC    = FileReverse.java
SOURCES    = README Makefile $(JAVASRC)
MAINCLASS  = FileReverse
CLASSES    = FileReverse.class 
JARFILE    = FileReverse
SUBMIT     = submit cmps012b-pt.s16 lab2
CHECK      = ls /afs/cats.ucsc.edu/class/cmps012b-pt.s16/lab2/qlam

all: $(JARFILE)

$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(CLASSES)
	rm Manifest
	chmod +x $(JARFILE)

$(CLASSES): $(JAVASRC)
	javac -Xlint $(JAVASRC)

clean:
	rm $(CLASSES) $(JARFILE)

submit: $(SOURCES)
	$(SUBMIT) $(SOURCES)

check:
	$(CHECK)
