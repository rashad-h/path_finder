#include "input.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// function used to read map and initilize the program
// return 0 if successful, 1 otherwise
int read_map(FILE* file) {

    file = fopen("Final_Map.map", "r");
    if(file == NULL) {
        return 1;
    }
    // importing the nodes
    read_nodes(file);
    FILE* file_2;
    file_2 = fopen("Final_Map.map", "r");

    //feeling the adjacency matrix up
    read_links(file_2);
    fclose(file);
    return 0;
    
}

// function to read nodes from the file
int read_nodes(FILE* file)
{
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // check if the line indicates a node
        if (line[0] == '<' && line[1] == 'n' && num_nodes < MAX_NODES)
        {
            char id[20];
            char lat[20];
            // double lat_d;
            char lon[20];
            // double lon_d;
            int i = 9;
            int j = 0;
            while (line[i] != ' ')
            {
               id[j] = line[i];
               i++;
               j++;
            }
            while (j != 20)
            {
                id[j] = NULL;
                j++;
            }
            // save ID
            all_nodes[num_nodes].id = strtoll(id, NULL, 10);
            i = i+5;
            j = 0;
            while (line[i] != ' ')
            {
               lat[j] = line[i];
               i++;
               j++;
            }
            //save Lat
            all_nodes[num_nodes].lat = (strtod(lat, NULL) - 0.0000008);
            i = i+5;
            j = 0;
            while (line[i] != ' ')
            {
               lon[j] = line[i];
               i++;
               j++;
            }
            // save Lon
            all_nodes[num_nodes].lon = strtod(lon, NULL);
            num_nodes++;
        }
    }
    return 0;
}

//function to read links from the file
int read_links(FILE* file) 
{
    char line[256];
    // int f = 0;
    while (fgets(line, sizeof(line), file)) {
        // check if the line indicates a link
        if (line[0] == '<' && line[1] == 'l')
        {
            char id_1[20];
            long long id_1_int;
            char id_2[20];
            long long id_2_int;
            char length[20];
            double length_d;
            int i = 7;
            while (line[i] != 'n')
            {
                i++;
            }
            i += 5;
            int j = 0;
            while (line[i] != ' ')
            {
                id_1[j] = line[i];
                j++;
                i++;
            }
            while (j != 20)
            {
                id_1[j] = NULL;
                j++;
            }
            // find the id of the first node
            id_1_int = strtoll(id_1, NULL, 10);
            j = 0;
            i += 6;
            while (line[i] != ' ')
            {
                id_2[j] = line[i];
                j++;
                i++;
            }
            while (j != 20)
            {
                id_2[j] = NULL;
                j++;
            }
            // find the id of the second node
            id_2_int = strtoll(id_2, NULL, 10);
            while (line[i] != 'l')
            {
                i++;
            }
            j = 0;
            i += 7;         
            while (line[i] != ' ')
            {
                length[j] = line[i];
                j++;
                i++;
            }
            while (j != 20)
            {
                length[j] = NULL;
                j++;
            }
            length_d = strtod(length, NULL);
            // fill the adjacency matrix
            adjacency_matrix[ID_to_artificial_id(id_1_int)][ID_to_artificial_id(id_2_int)] = length_d;
            adjacency_matrix[ID_to_artificial_id(id_2_int)][ID_to_artificial_id(id_1_int)] = length_d;

        }
        
    }
    return 0;
}

// get the original id of the node and returns the artificial id
// returns -1 if fails
int ID_to_artificial_id(long long ID)
{   
    int artificial_id;
    for (int i = 0; i < num_nodes; i++)
    {
        if (all_nodes[i].id == ID)
        {
            artificial_id = i;
            break;
        }
    }
    return artificial_id;  
}