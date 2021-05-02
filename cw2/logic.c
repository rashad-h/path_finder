#include "logic.h"

// returns the artificial id of the node
// return -1 if not successful
int node_by_ID(long int ID);

// return the artificial id of the node
// return -1 if not successful
int find_closest_point (double lat, double lon);

// return the path using Dijkstra
// returns -1 if not path exists
// returns 0 if not successful
struct nodeArray find_shortest_path_Djikstra (int node1_id, int node2_id);

// return the path using Floyd
// returns -1 if not path exists
// returns 0 if not successful
struct nodeArray find_shortest_path_Floyd (int node1_id, int node2_id);