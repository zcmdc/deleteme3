#include <stdio.h>
#include <stdlib.h>
#include "MyFunctions.h"

/*
 *  This is a file to make an all green circle in the middle of our image (or .ppm)
 *  in C for the fun of programming!
 *
 *  Author: John Chrispell          Date 10/28/2021
 *
 */

int main(int argc,               // The number of command line arguments.
         char *argv[] ){         // Vector of command line arguments.

    // Do all variable declairations up here at the top.

    int numRows;          // The number of rows for my image file.
    int numCols;          // The number of cols for my image to be.
    int imageSize;        // The total size of the .ppm file image.
    int row, col;         // The marker to let me know where I am in the image.
    int Radius;           // This will be the size of the circle to put image center. 
    int InOrOut;          // Flag for in or out of my circle. 

    unsigned char *outImage;  /* pixel pointer            */
    unsigned char *ptr;       /* pointer                  */
    FILE *outputFP;           /* My out put file pointer. */

    printf("==============================================\n");
    printf(" I'm making a green circle .ppm file for you! \n");
    printf("==============================================\n");

    // Read in the command line arguments:

    if(argc != 5){
         printf("Usage: AllGreen OutFile numRows numCols Radius\n");
         exit(1);
    }

    if((numRows = atoi(argv[2])) <= 0){
         printf("The given number or rows is not positive!\n");
    }
    if((numCols = atoi(argv[3])) <= 0){
         printf("The given number of cols is not positive!\n");
    }
    if((Radius = atoi(argv[4])) <= 0){
         printf("You need to give a positve radius value!\n");
    }

    printf("=============================================\n");
    printf(" Now working to set up sizes.                \n");
    printf("=============================================\n");

    imageSize = numRows*numCols*3;
    outImage  = (unsigned char *) malloc(imageSize);  // Get enough space in memory for the image.

    /* Open the image for writting. */ 
    if( (outputFP = fopen(argv[1],"w")) == NULL){
         perror("output open error");
         printf("Error in opeing your given output file!\n");
         exit(2);
    }

    printf("=============================================\n");
    printf(" Index Through the given image.              \n");
    printf("=============================================\n");

    ptr = outImage; 

    for( row = 0 ; row < numRows ; row++){
        for( col = 0 ; col < numCols ; col++){
             printf("Row and Col (%d,%d)\n",row,col); 
             InOrOut = CheckRadius(numRows, numCols, Radius, row, col); 

             if(InOrOut == 1){
                 // Inside the circle the pixel is green! 
                 *ptr     = 0;   // red   pixel
                 *(ptr+1) = 255; // green pixel
                 *(ptr+2) = 0;   // blue  pixel
             } else {
                 *ptr     = 0;   // red   pixel
                 *(ptr+1) = 0;   // green pixel
                 *(ptr+2) = 0;   // blue is best here!
             }
            // Advance the pixel pointer
            ptr += 3;
        }
    }

    printf("============================================\n");
    printf(" Write it all out to a file for viewing.    \n");
    printf("============================================\n");

    fprintf(outputFP, "P6 %d %d 255\n", numCols, numRows);
    fwrite(outImage, 1, imageSize, outputFP);

    /* Done */
    fclose(outputFP);
    return 0;
}
