#include "graphics.h"
#include "input.h"
#include <stdlib.h>
#include <stdio.h>

#define NUM_COMMANDS 2

// functions used to draw the resutls
// return 0 if correct
int show_results(struct NodeArray shortest_path) {
    FILE* final_map = NULL;
    final_map = fopen("shortest_path.txt", "w");
    double x, y;
    for (int i = 0; i < shortest_path.length; i++)
    {
        x = shortest_path.array[i].lon;
        y = shortest_path.array[i].lat;
        fprintf(final_map, "%.6lf\t %.6lf\n", x, y);
    }

    char * commandsForGnuplot[] = {"set title \"Shortest Path\"", "plot 'shortest_path.txt' w lp"};
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    for (int i=0; i < NUM_COMMANDS; i++)
    {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    }
    

    return 0;
}
