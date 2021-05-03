#include "logic.h"
#include "input.h"
#include "graphics.h"
#include <stdlib.h>
#include <math.h>

// returns the original ID of the node
// return -1 if not successful
int node_by_ID(long long ID)
{
    int id;
    if (ID_to_artificial_id(ID) != -1)
    {
        id = ID_to_artificial_id(ID);
        return id;  
    }
    else
    {
        return -1;
    }
}

// return the origianl ID of the node
// return -1 if not successful
int find_closest_point (double lat, double lon)
{
    for (int i = 0; i < num_nodes; i++)
    {
        if (fabs(all_nodes[i].lat - lat) < 0.000001)
        {
            if (fabs(all_nodes[i].lon - lon) < 0.000001)
            {
                return i;
            }
        }
        
    } 
    return -1;
}

// return the path using Dijkstra
// returns NULL if not successful
struct NodeArray find_shortest_path_Djikstra (int node1_id, int node2_id)
{
    int start_node = node1_id;
    int end_node = node2_id;
    int visited[MAX_NODES]; // keeping track of the nodes which are already visited
    //double cost[MAX_NODES][MAX_NODES]; // cost matrix
    double dist[MAX_NODES]; // distance of each node from the start node
    int pred[MAX_NODES];

    int i, j, count, next_node;
    double min_dist;

    // filling the cost matrix
    // for (i = 0; i < num_nodes; i++)
    // {
    //     for (j = 0; j < count; j++)
    //     {
    //         if (adjacency_matrix[i][j] == 0)
    //         {
    //             cost[i][j] = INF;
    //         }
    //         else
    //         {
    //             cost[i][j] = adjacency_matrix[i][j];
    //         }
               
    //     }
        
    // }

    // for (i = 0; i < num_nodes; i++)
    // {
    //     dist[i] = cost[start_node][i]; /* code */
    //     pred[i] = start_node;
    //     visited[i] = 0;
    // }
    for (i = 0; i < num_nodes; i++)
    {
        if (adjacency_matrix[start_node][i] == 0)
        {
            dist[i] = INF;
        }
        else
        {
            dist[i] = adjacency_matrix[start_node][i];
        }
        
        pred[i] = start_node;
        visited[i] = 0;
    }
    
    // changing the data for the start node
    dist[start_node] = 0;
    visited[start_node] = 1;
    count = 1;

    while (count < num_nodes - 1)
    {
        min_dist = INF;
        for (i = 0; i < num_nodes; i++)
        {
            if (dist[i] < min_dist && !visited[i])
            {
                min_dist = dist[i];
                next_node = i;
            }
            
        }
        
        visited[next_node] = 1;

        // for(i = 0; i < num_nodes; i++)
        // {
        //     if(!visited[i])
        //     {
        //         if ((min_dist + cost[next_node][i]) < dist[i])
        //         {
        //             dist[i] = min_dist + cost[next_node][i];
        //             pred[i] = next_node;
        //         }
                
        //     }
        // }
        for(i = 0; i < num_nodes; i++)
        {
            if(!visited[i])
            {
                double cost;
                if (adjacency_matrix[next_node][i] == 0)
                {
                    cost = INF;
                }
                else
                {
                    cost = adjacency_matrix[next_node][i];
                }
                
                if ((min_dist + cost) < dist[i])
                {
                    dist[i] = min_dist + cost;
                    pred[i] = next_node;
                }
                
            }
        }

        count++;
    }

    // Creating the node array
    struct NodeArray final_path;
    final_path.array = (struct Node* ) malloc(sizeof(struct Node));;
    final_path.length = 0;

    if (dist[end_node] != INF)
    {
        // printing distance and the path
        printf("The total distance is %lf\n", dist[end_node]);
        printf("The path is : %lli", all_nodes[end_node].id);
        j = end_node;
        final_path.array = realloc(final_path.array, (final_path.length + 1) * sizeof(struct Node));
        final_path.array[final_path.length] = all_nodes[j];
        final_path.length++;
        do
        {
            j = pred[j];
            final_path.array = realloc(final_path.array, (final_path.length + 1) * sizeof(struct Node));
            final_path.array[final_path.length] = all_nodes[j];
            final_path.length++;
            printf("<- %lli", all_nodes[j].id);
        } while (j != start_node);
        printf("\n");
    }
    else
    {
        printf("Path does not exist!\n");
    }
    
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
