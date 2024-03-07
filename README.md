# Path Finding Application

This application, named `path_finding`, is designed to facilitate pathfinding on maps by utilizing Dijkstra or Floyd's algorithm. It reads map files with a specified format and provides paths between any two nodes. Additionally, it allows for the comparison of results between the two algorithms. Upon exiting the program, it generates a graph visualization using GNUPLOT.

## Features

- **Pathfinding Algorithms**: Implements both Dijkstra and Floyd's algorithms for finding paths between nodes.
- **Map File Compatibility**: Reads any `.map` file with the same format as the original file provided.
- **Node Selection**: Users can choose nodes by their ID or coordinates.
- **Graph Visualization**: Generates a graphical representation of the map using GNUPLOT.
- **Comparison**: Users can compare results obtained from Dijkstra and Floyd's algorithms.

## Usage

1. Clone the repository to your local machine.
2. Compile the program using your preferred compiler.
3. Run the compiled executable.
4. Provide the path to the map file when prompted.
5. Choose the nodes between which you want to find the path.
6. Select the algorithm (Dijkstra or Floyd) for pathfinding.
7. View the path results and optionally compare them.

## Example Nodes for Testing

Here are some randomly chosen nodes with their respective IDs and coordinates for testing purposes:

| ID          | Latitude    | Longitude   |
|-------------|-------------|-------------|
| -2560       | 53.807613   | -1.554711   |
| 1615401915  | 53.804646   | -1.554947   |
| 1968799687  | 53.804071   | -1.555334   |
| 247958669   | 53.805909   | -1.556134   |
| 1615404345  | 53.804747   | -1.555335   |
| -2486       | 53.809637   | -1.557703   |
| 49510370    | 53.802597   | -1.558777   |

Feel free to use these nodes to test the application.

## Requirements

- GNUPLOT
- Compatible C++ compiler
