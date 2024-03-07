#ifndef GRAPHICS_GUARD__H
#define GRAPHICS_GUARD__H

#include <stdio.h>
#include "input.h"

struct NodeArray
{
    struct Node* array; // pointer to array of struct Nodes
    unsigned int length; // length of the array

};

// functions used to draw the resutls
// return 0 if correct 
int show_results(struct NodeArray shortest_path);

#endif