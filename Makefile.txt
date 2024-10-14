# Makefile used for All Green Image project
# Author John Chrispell                 Date: 10/21/2021
#                                   modified: 10/21/2021

# The put together the list of objects you need in your project.
# These correspond to the different .c files in the project. 
OBJS = AllGreen.o HelperFunctions.o

# The following is a list of includes: 
INCLUDES = MyFunctions.h

# Debugging flags that can be turned on and off depending on the
# way you want to compile the given code. 
DEBUGFLAGS = 

# Parameters that you can have to assist with the compile. 
CFLAGS = -Wall -g ${DEBUGFLAGS}

# Rules for making the executable file:
AllGreen: ${OBJS} ${INCLUDES} Makefile
	gcc -Wall -o Allgreen ${OBJS} -lm

# Dependencies for the object  
${OBJS}: ${INCLUDES} Makefile

# This is unrelated to the actual make. This is my clean up.
# Invoke : make clean
clean: 
	echo Removing *.o Allgreen
	/bin/rm -f *.o Allgreen
