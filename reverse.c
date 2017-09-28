/*****************************************************************
Program that will reverse a text file character for character

@author Kevin Anderson
@version Fall 2017
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

int main (int argc, char** argv[] )
{
    if(argc == 1) {
        fprintf( stderr, "You must supply an input file name." );
    } else {
        // alias the input params
        char* inputFileName = (char*)argv[1];
        char* outputFileName = (char*)argv[2];
    
        //pointer for char array
        char* buffer;

        //get the length of the file and read it into array
        int readLength = read_file(inputFileName, &buffer);

        //check if memory alloc worked
        if(readLength == -1) {
            fprintf( stderr, "File could not be read. Exiting..." );
            exit(0);
        }
        
        int writeLength = write_file(outputFileName, buffer, readLength);

        if(writeLength == -1 || writeLength != readLength) {
            fprintf( stderr, "File could not be written to. Exiting..." );
        }

        //free memory
        free(buffer);

    }

    return 0;
};