#ifndef INPUT_GUARD__H
#define INPUT_GUARD__H

#include <stdio.h>

#define MAX_NODES 2120


struct Node
{
    long long id;
    double lat;
    double lon;
};

struct Node all_nodes[MAX_NODES]; // array of all nodes

int num_nodes;
double adjacency_matrix[MAX_NODES][MAX_NODES]; // the adjacency matrix for the nodes

// function used to read map and initilize the program
// return 0 if successful, 1 otherwise
int read_map(FILE* file);

// function to read nodes from the file
int read_nodes(FILE* file);

//function to read links from the file
int read_links(FILE* file);

// get the original id of the node and returns the artificial id
// returns -1 if fails
int ID_to_artificial_id(long long ID);


#endif