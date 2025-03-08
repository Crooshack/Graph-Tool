# Graph Analysis Tool

## Task Description
The program processes multiple graphs and determines the following parameters:

1. **Degree sequence** - a sequence of n numbers representing the degree of each vertex.
2. **Number of components** - a single character `T` (true) or `F` (false) indicating the number of connected components.
3. **Bipartiteness** - a single character `T` (true) or `F` (false) indicating whether the graph is bipartite.
4. **Eccentricity of vertices** - a sequence of n numbers representing the eccentricity of each vertex within its component.
5. **Planarity** - a single character `T` or `F` indicating whether the graph is planar.
6. **Vertex coloring** using different algorithms:
   - a) **Greedy** (vertices ordered by their number) - a sequence of n numbers.
   - b) **LF method** (ties resolved by vertex number) - a sequence of n numbers.
   - c) **SLF method** (ties resolved by highest degree, then lowest number) - a sequence of n numbers.
7. **Number of different C4 subgraphs** - a single number representing the count of C4 subgraphs.
8. **Number of complement graph edges** - a single number representing the edge count of the graph's complement.

If any parameter is not implemented, the program outputs a single `?` character for that parameter.

## Input Format
The first line contains an integer `k` - the number of graphs.  
Each of the following `k` data sets contains:
- An integer `n` - the order of the graph.
- `n` lines, each describing a vertex's neighbors:
  - An integer `s` - the number of neighbors.
  - `s` integers - the IDs of the neighboring vertices.
  
Neighbor IDs are in the range `[1, n]`.

## Output Format
The program outputs `k` sets of results, each containing the designated parameters in the order specified above. The format is:
- Sequences of `n` numbers for points **1, 4, 6a, 6b, 6c**.
- A single number for points **7, 8**.
- A character `T` or `F` for points **2, 3, 5**.
- `?` for any unimplemented parameters.

## Unimplemented Features
The following parameters are not implemented and will output `?`:
- **4. Eccentricity of vertices**
- **5. Planarity**
- **6. Vertex coloring** (Greedy, LF, SLF)
- **7. Number of different C4 subgraphs**
- **8. Number of complement graph edges**

## Author of most of the content in README file:
- _Andrzej Jastrzębski from Gdańsk Tech_
