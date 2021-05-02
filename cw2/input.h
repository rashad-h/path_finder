#ifndef INPUT_GUARD__H
#define INPUT_GUARD__H

#include <stdio.h>

struct Node
{
    long int id;
    double lat;
    double lon;
};

// function used to read map and initilize the program
// return 0 if successful, 1 otherwise
int read_map(FILE* file);

// function to read nodes from the file
// int read_nodes(FILE* file);

//function to read links from the file
// int read_links(FILE* file);


#endif