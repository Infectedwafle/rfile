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
        int length = read_file(inputFileName, &buffer);

        //check if memory alloc worked
        if(length == -1) {
            fprintf( stderr, "File could not be read. Exiting..." );
            exit(0);
        }
     
        length = write_file(outputFileName, buffer, length);

        if(length == -1) {
            fprintf( stderr, "File could not be written to. Exiting..." );
        }

        //free memory
        free(buffer);

    }

    return 0;
};