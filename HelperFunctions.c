#include <math.h> // Lets me use pow(stuff,power).
/* This is the helper function file for my AllGreen Circle */

int CheckRadius(int TotRows, int TotCols, int Radius, int CurPixRow, int CurPixCol){

    int InOrOut   = 0;           // Returns 0 or 1 for out and in side the circle respectively.
    int CenterRow = TotRows/2;   // Place holder for the center with regard to rows.
    int CenterCol = TotCols/2;   // Place holder for the center column.
    int dist      = 0;           // Place in memory for the distance between CurPix and Center.

    // printf("I'm in CheckRadius\n");

    // Compute The distance.
    dist = pow((pow(CenterRow-CurPixRow,2.0)+pow(CenterCol-CurPixCol,2.0)),0.5);

    // Check is dist < Radius and set flag. 
    if( dist < Radius){
        InOrOut = 1;
    }

    return InOrOut;
}
