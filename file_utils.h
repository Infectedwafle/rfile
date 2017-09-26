#ifndef     FILE_UTILS_H
#define     FILE_UTILS_H

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);
int file_exists(char* filenaame);

#endif
