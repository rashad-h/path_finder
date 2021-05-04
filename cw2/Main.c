#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "logic.h"
#include "graphics.h"

int main(int argc, char const *argv[])
{
    FILE* map;
    if (!read_map(map))
    {
        printf("\nMap was loaded successfully!\n\n");
    }
    

    while (1)
    {
        printf("To choose the points by ID enter 1, to choose by coordinates enter 2\n");
        printf("To exit and print the paths enter 3 \n");
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
            long long node_id_1;
            int art_id_1;
            long long node_id_2;
            int art_id_2;

            printf("Please enter the id of the node 1: ");
            scanf("%lli", &node_id_1);
            if (node_by_ID(node_id_1) == -1)
            {
                printf("Sorry the node with this id does not exist!\n\n");
                continue;
            }
            // inpute node 2
            printf("Please enter the id of the node 2: ");
            scanf("%lli", &node_id_2);
            if (node_by_ID(node_id_2) == -1)
            {
                printf("Sorry the node with this id does not exist!\n");
                continue;
            }
            // check if they are the same node
            if (node_by_ID(node_id_2) == node_by_ID(node_id_1))
            {
                printf("You have chosen the same nodes!\n");
                continue;
            }
            art_id_1 = node_by_ID(node_id_1);
            art_id_2 = node_by_ID(node_id_2);

            while (1)
            {
                printf("In order to use Dijkstra enter 1, for Floyd enter 2:\n");

                struct NodeArray final_path;
                // Dijkstra
                scanf("%d", &option);
                printf("\n");
                if (option == 1)
                {
                    option = 0;
                    while ((getchar()) != '\n');

                    final_path = find_shortest_path_Djikstra (art_id_1, art_id_2);
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
                else if (option == 0)
                {
                    option = 0;
                    while ((getchar()) != '\n');
                    continue;
                }
                
                // Invalid option
                else
                {
                    printf("Sorry, the option you entered was invalid, please try again.\n");
                    printf("\n");
                    while ((getchar()) != '\n'); 
                }

                if (final_path.length > 0)
                {
                    show_results(final_path);
                    break;
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
            double latitude;
            double longitude;

            // inputting from the user
            printf("Please enter the latitude of the node 1: ");
            scanf("%lf", &latitude);
            printf("Please enter the longitude of the node 1: ");
            scanf("%lf", &longitude);
            node_id_1 = find_closest_point(latitude, longitude);
            if (node_id_1 == -1)
            {
                printf("Sorry the node with this coordinates does not exist!\n");
                continue;
            }
            printf("\n");
            // node 2
            printf("Please enter the latitude of the node 2: ");
            scanf("%lf", &latitude);
            printf("Please enter the longitude of the node 2: ");
            scanf("%lf", &longitude);
            node_id_2 = find_closest_point(latitude, longitude);
            if (node_id_2 == -1)
            {
                printf("Sorry the node with this coordinates does not exist!\n");
                continue;
            }
            // chack for the same nodes
            if (node_id_1 == node_id_2)
            {
                printf("You have chosen the same nodes!\n");
                continue;
            }


            while (1)
            {
                printf("In order to use Dijkstra enter 1, for Floyd enter 2:\n");

                struct NodeArray final_path;
                // Dijkstra
                scanf("%d", &option);
                printf("\n");
                if (option == 1)
                {
                    option = 0;
                    while ((getchar()) != '\n');

                    final_path = find_shortest_path_Djikstra (node_id_1, node_id_2);
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
                else if (option == 0)
                {
                    option = 0;
                    while ((getchar()) != '\n');
                    continue;
                }
                
                // Invalid option
                else
                {
                    printf("Sorry, the option you entered was invalid, please try again.\n");
                    printf("\n");
                    while ((getchar()) != '\n'); 
                }

                if (final_path.length > 0)
                {
                    show_results(final_path);
                    break;
                }
                
            }
            
        }

        // EXIT
        else if (option ==3)
        {
            option = 0;
            while ((getchar()) != '\n');

            exit(1);
        }

        else if (option ==0)
        {
            option = 0;
            while ((getchar()) != '\n');
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
