#include <stdio.h>
#include "input.h"
#include "logic.h"
#include "graphics.h"

int main(int argc, char const *argv[])
{
    // Load the map
    //read_map();
    //printf("Map was loaded successfully!\n\n");

    while (1)
    {
        printf("To choose the points by ID enter 1, to choose by coordinates enter 2\n");
        printf("To exit enter 3 \n");
        // Evaluationg the option
        static int option;
        scanf("%d", &option);
        printf("\n");

        // By ID
        if (option == 1)
        {
            option = 0;
            while ((getchar()) != '\n');
            
            // Find nodes by ID
            int node_id_1;
            int node_id_2;
            //node_id_1 = node_by_ID();
            //node_id_2 = node_by_ID();

            while (1)
            {
                printf("In order to use Dijkstra enter 1, for Floyd enter 2");

                //int final_path[MAX_NODES];

                // Dijkstra
                if (option == 1)
                {
                    option = 0;
                    while ((getchar()) != '\n');

                    // Use Dijkstra
                    //final_path = find_shortest_path_Dijkstra(node_id_1, node_id_2);
                    // show_results(final_path);
                }

                // Floyd
                else if (option ==2)
                {
                    option = 0;
                    while ((getchar()) != '\n');

                    // Use Floyd
                    //final_path = find_shortest_path_Floyd(node_id_1, node_id_2);
                    // show_results(final_path);
                }
                // Invalid option
                else
                {
                    printf("Sorry, the option you entered was invalid, please try again.\n");
                    printf("\n");
                    while ((getchar()) != '\n'); 
                }
                
            }
        }

        // By coordinates
        else if (option ==2)
        {
            option = 0;
            while ((getchar()) != '\n');

            // Find nodes by coordinates
            int node_id_1;
            int node_id_2;
            //node_id_1 = find_closest_point();
            //node_id_2 = find_closest_point();
            
        }

        // EXIT
        else if (option ==3)
        {
            option = 0;
            while ((getchar()) != '\n');

            exit(1);
        }

        //invalid input
        else
        {
            printf("Sorry, the option you entered was invalid, please try again.\n");
            printf("\n");
            while ((getchar()) != '\n'); 
        }
    }
    
    return 0;
}
