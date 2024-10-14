# Makefile used to make a circle ppm

# The following are the OBJECT files that the executable is dependent on. 
# They correspond to the .c in the project and if the .c are modified they get recompiled. 
OBJS = PurpleCircle.o ../HelperFunctions.o

# The following are the header files for stenceling functions. 
INCLUDES = MyFunctions.h

# Debugging flags typically go here. 
# Use the convention turn on with flag setting: -DDBG_<NAME>

DEBUGFLAGS = 

# Parameters automatically used by gcc to compile source code to object file. 

CFLAGS = -Wall -g ${DEBUGFLAGS}

# Rule for make the executable file "PurpleCircle"
PurpleCircle: ${OBJS} ${INCLUDES} Makefile
	gcc -Wall -g -o PurpleCircle ${OBJS} -lm

# Dependencies for the object files to the included and Makefile.
${OBJS}: ${INCLUDES} Makefile

# This is an unrelated rule that we can use to clean up by removing *.o files. 
# Invoke the "make clean"
clean: 
	echo Removing *.o PurpleCircle
	/bin/rm -f *.o PurpleCircle
