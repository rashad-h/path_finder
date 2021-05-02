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

// return the direct distance of two nodes
// return 0 if the two nodes are the same
// return -1 if the two are not directly connected
double find_direct_distance (int node1_id, int node2_id);


#endif