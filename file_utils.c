#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * Reads every character in a file backwards into **buffer
 * @param  filename pointer to the name of the file
 * @param  buffer   pointer to char array
 * @return          [description]
 */
int read_file(char* filename, char **buffer ){

	FILE *filePointer;
	long length = 0;
	long index = 0;

    struct _stat fileStats;
    int result;
    result = _stat( filename, &fileStats );
    
    if(result != 0) {
        fprintf(stderr, "Problem getting information.  " );  
        switch (errno)  
        {  
            case ENOENT:  
                fprintf(stderr, "File %s not found.\n", filename);  
                break;  
            case EINVAL:  
                fprintf(stderr, "Invalid parameter to _stat.\n");  
                break;  
            default:  
                /* Should never be reached. */  
                fprintf(stderr, "Unexpected error in _stat.\n");  
        }

        return -1;
    } else {
    	//open file and find length
        filePointer = fopen(filename, "rb");
        // fseek(filePointer, 0, SEEK_END);
        // length = ftell(filePointer);
        //fseek(filePointer, 0, SEEK_SET);
        length = fileStats.st_size;


        *buffer = (char*) malloc(length * sizeof(char));

        //seek backwards through the file
        for(int i = 0; i < length; ++i) {
            if(fread(*buffer + (length - i) - 1, sizeof(char), 1, filePointer) <= 0) {
                fprintf( stderr, "There was a problem reading from the file.\n" );
                return -1;
            }
        }

        fclose(filePointer);
    }


    //return the length of the file read
    return length;
}

/**
 * writes each *buffer to file with the specificed filename
 * @param  filename [description]
 * @param  buffer   [description]
 * @param  size     [description]
 * @return          [description]
 */
int write_file(char* filename, char *buffer, int size) {
	FILE* filePointer;
	filePointer = fopen(filename, "wb");

	if(filePointer == NULL) {
		fprintf( stderr, "There was a problem opening the file for writing.\n" );
        return -1;
	}
    int length = 0;

    for(int i = 0; i < size; i++) {
        if(fwrite(buffer + i, sizeof(char), 1, filePointer) > 0) {
            length++;
        } else {
            fprintf( stderr, "There was a problem writing to the file.\n" );
            return -1;
        }
    }
    
	fclose(filePointer);
    return 0;
}

/**
 * [file_exists description]
 * @param  filename [description]
 * @return          [description]
 */
int file_exists(char* filename) {
    FILE *fp;

    if(!(fp = fopen(filename, "r"))) {
         return 0;
    }

    return 1;
}