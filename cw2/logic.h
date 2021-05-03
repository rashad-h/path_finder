#ifndef LOGIC_GUARD__H
#define LOGIC_GUARD__H

#include <stdio.h>
#include "input.h"
#include "graphics.h"

#define INF 999999 // number for infinity

// returns the original ID of the node
// return -1 if not successful
int node_by_ID(long long ID);

// return the original ID of the node
// return -1 if not successful
int find_closest_point (double lat, double lon);

// return the path using Dijkstra
// returns -1 if not path exists
// returns 0 if not successful
struct NodeArray find_shortest_path_Djikstra (int node1_id, int node2_id);

// return the path using Floyd
// returns -1 if not path exists
// returns 0 if not successful
struct NodeArray find_shortest_path_Floyd (int node1_id, int node2_id);





#endif