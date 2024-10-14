#include <stdio.h>
#include <stdlib.h>
#include "MyFunctions.h"

/* 
 *   This is a c program to create a red and blue plain pixel map.
 *   Usage: 
 * 
 *   PurpleCircle OutFileName numRows numCols radius
 * 
 *   Here our program takes in an outfile name, and two arguments for
 *   the rows and columns for the size of the image to produce. 
*/ 

int main(int argc,    // This is the number of things passed into this function.  
         char *argv[] // This is the array of things passed. 
        ){

    int numRows;    /* Place holder for the number of rows    */ 
    int numCols;    /* Place holder for the number of columns */ 
    int imageSize;  /* Total number of pixels we will use     */ 
    int row, col;   /* row, and column counters               */
    int radius;     /* Size of my circle                      */
    int InOut;      /* Flag where (0 = out , and 1 = circle)  */  
    unsigned char *outImage;  /* pixel pointer                */ 
    unsigned char *ptr;       /* a ponter                     */ 
    //unsigned char *outputFP;  /* Output file                  */ 
    FILE *outputFP;           

    printf("=====================================\n");  
    printf("I'm making a plain Pixel Map!        \n");
    printf("=====================================\n\n");

    if(argc!=5){
        printf("Usage: ./PurpleCircle OUTfileName numrow numcols radius \n");
        exit(1);
    }
    if ( (numRows = atoi(argv[2]) ) <= 0){
        printf("Error: numRows needs to be positive");
    } 
    if ( (numCols = atoi(argv[3]) ) <= 0){
        printf("Error: numCols needs to be positive");
    }
    if ( (radius = atoi(argv[4]) ) <= 0){
        printf("Error: The radius should be positive");
    }

    // ============================================
    // Set up space for my soon to be ppm image. 
    // ============================================
    imageSize = numRows*numCols*3;  
    outImage  = (unsigned char *) malloc(imageSize); // get enough space for my image. 

    /* Open a file to put the output image into */ 
    if((outputFP = fopen(argv[1], "w")) == NULL){
        perror("output open error");
        printf("Error: can not open output file\n");
        exit(1);
    } 
    
    /* Now lets create the plain pixel map! */ 
    ptr = outImage; 



    for(row = 0; row < numRows; row++){
        for(col = 0; col < numCols; col++){
            // Walk through each row of the image column by column. 
            // Use a function to decide if you are in the circle or not.
            InOut = InCircle(numRows,numCols,radius,row,col);

            if (InOut ==1){
               /* Purple Pixel */ 
               *ptr     = 128;
               *(ptr+1) = 0; 
               *(ptr+2) = 128;
            }
            else {
               /* White Pixel */ 
               *ptr     = 255; 
               *(ptr+1) = 255; 
               *(ptr+2) = 255; 
            }
            // Advance the pointer. 
            ptr += 3; 
        }
    }


    // Put all of this information into a file with a need header. 
    fprintf(outputFP, "P6 %d %d 255\n", numCols, numRows);
    fwrite(outImage, 1, imageSize, outputFP);

    /* Done */ 
    fclose(outputFP);

    return 0;
}

\end{lstlisting}
\end{document}
