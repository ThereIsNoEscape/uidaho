#  Jonathan Buch
#  Section #1
#  Lab #5
#  Retrieved From Prof. Bruce Bolden on February 24th, 2015
 
#  Makefile
#    a makefile for the stack example.
#

#            SHELL = 	/bin/sh

#              TOP = .
#      CURRENT_DIR = .

#              CPP = /lib/cpp $(STD_CPP_DEFINES)
              CXX  = g++

#        CCOPTIONS =
#           CFLAGS = $(CDEBUGFLAGS) $(CCOPTIONS) $(ALLDEFINES)
#           RM_CMD = $(RM) *.o core

SRCSStack=	testStack.cpp	\
		stack.cpp	\
		link.cpp	

OBJSStack=	testStack.o	\
		stack.o		\
		link.o		

SRCSQueue=	testQueue.cpp	\
		QueueL.cpp	\
		listQ.cpp

OBJSQueue=	testQueue.o	\
		QueueL.o	\
		listQ.o


testStack.o:	stack.h

testQueue.o:	QueueL.h

stack.o:	stack.h	\
		link.h

QueueL.o:	QueueL.h \
		listQ.h

link.o:		link.h

listQ.o:	listQ.h


PROGRAM1 = testStack

PROGRAM2 = testQueue

all:: $(PROGRAM1) $(PROGRAM2)

#PROGRAM1:: $(PROGRAM1)

#PROGRAM2:: $(PROGRAM2)

testStack: $(OBJSStack)
	$(CXX) -o $@ $(OBJSStack)

testQueue: $(OBJSQueue)
	$(CXX) -o $@ $(OBJSQueue)


#$(CXX) -o $@ $(OBJS) $(LDOPTIONS) $(LOCAL_LIBRARIES) $(LDLIBS)  $(EXTRA_LOAD_FLAGS)

clean::
	$(RM) testStack 
	$(RM) testQueue

latex::
	latex stack.tex
	latex queue.tex    

###########################################################################
# common rules for all Makefiles - do not edit

emptyrule::

clean::
	rm *.o

