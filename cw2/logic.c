#include "logic.h"

// returns the original ID of the node
// return -1 if not successful
int node_by_ID(long int ID)
{
    return -1;
}

// return the origianl ID of the node
// return -1 if not successful
int find_closest_point (double lat, double lon)
{
    return -1;
}

// return the path using Dijkstra
// returns NULL if not successful
struct NodeArray find_shortest_path_Djikstra (int node1_id, int node2_id)
{
    struct NodeArray final_path;


    /////
    final_path.array = NULL;
    final_path.length = 0;
    return final_path;
}

// return the path using Floyd
// returns NULL if not successful
struct NodeArray find_shortest_path_Floyd (int node1_id, int node2_id) 
{
    struct NodeArray final_path;


    /////
    final_path.array = NULL;
    final_path.length = 0;
    return final_path;
}
