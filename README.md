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
- **7. Number of different C4 subgraphs (I think I implemented it, but it was too slow to pass tests)**

## Example 
### Input
```
4

18
3 16 13 12
3 14 13 17
2 11 13
3 14 12 16
4 16 11 14 18
2 11 18
3 17 12 11
2 13 16
5 18 14 17 16 12
3 14 11 16
5 6 3 5 10 7
4 4 9 7 1
4 2 3 8 1
5 4 9 2 10 5
0 
6 5 9 1 8 10 4
3 9 7 2
3 9 6 5

20
5 12 13 20 19 18
4 14 16 18 12
6 18 16 11 19 14 20
8 13 18 20 19 12 16 15 17
6 20 17 12 13 16 15
5 18 17 15 19 14
4 11 12 13 14
9 20 13 19 18 15 16 14 17 11
7 12 13 11 18 17 15 14
6 18 12 14 19 15 17
4 9 7 3 8
7 9 1 10 7 5 4 2
6 8 9 1 4 7 5
7 2 7 8 6 10 9 3
6 8 6 10 9 4 5
5 8 3 5 4 2
6 5 6 9 10 4 8
8 6 8 10 3 4 9 1 2
6 8 1 6 4 10 3
5 8 5 1 4 3

35
5 32 29 31 26 27
1 35
5 29 34 22 27 31
5 31 28 33 25 29
8 26 29 34 24 31 21 23 33
4 32 30 26 24
2 33 22
5 24 25 26 35 32
5 29 33 27 34 24
5 24 26 34 32 33
5 26 35 21 32 31
5 21 27 32 22 35
7 31 28 22 34 24 35 32
8 33 29 31 23 27 25 34 26
4 26 23 33 28
3 21 33 31
8 26 29 31 34 21 33 32 23
6 29 31 34 28 26 24
6 27 34 24 29 30 28
3 24 26 28
5 12 11 17 16 5
4 13 3 12 7
4 15 14 5 17
9 20 10 8 5 18 19 6 13 9
3 8 14 4
11 5 11 17 15 20 10 18 1 6 8 14
6 19 12 14 3 1 9
6 13 18 4 19 20 15
9 3 18 14 9 17 5 1 19 4
2 6 19
10 4 13 18 17 14 1 5 3 16 11
8 1 6 12 11 17 13 10 8
9 14 15 9 4 17 16 7 5 10
9 18 19 5 3 17 13 14 10 9
5 11 2 12 8 13

40
8 31 39 21 36 29 33 27 23
12 40 25 21 24 32 36 35 31 23 33 39 22
13 35 40 33 38 37 29 26 32 39 28 22 30 27
11 23 37 22 21 26 31 27 25 38 24 29
13 38 28 33 40 35 23 24 22 21 32 37 26 36
9 22 29 27 30 28 21 35 37 33
11 24 25 21 38 35 37 28 33 34 23 30
7 34 36 32 33 22 40 37
13 24 21 34 25 40 35 27 36 29 23 39 31 37
10 38 28 21 23 31 40 24 34 33 27
11 32 25 22 21 26 36 24 37 34 38 40
5 30 27 29 28 22
11 21 25 24 23 39 27 32 29 22 35 34
12 24 38 39 28 21 22 35 31 34 30 37 32
9 24 33 37 38 36 34 21 22 31
12 21 32 22 33 27 30 39 28 26 37 40 23
11 25 21 36 32 38 27 40 33 29 37 39
7 30 28 27 23 32 31 26
5 27 31 38 26 35
10 22 21 34 29 27 38 26 39 36 23
15 13 17 9 1 2 16 10 11 14 20 6 4 7 5 15
13 6 16 11 20 8 14 4 5 12 13 3 15 2
11 10 2 18 4 13 5 7 9 16 1 20
10 9 15 14 7 2 13 11 5 10 4
7 17 2 9 13 11 7 4
8 11 4 16 3 5 19 18 20
13 19 16 6 18 9 20 17 12 4 13 1 10 3
9 10 18 5 14 6 16 12 7 3
9 6 1 20 9 3 12 13 17 4
7 12 18 6 16 14 7 3
9 1 2 10 19 14 4 18 9 15
10 8 16 2 11 17 18 3 5 13 14
11 3 16 8 2 5 15 1 7 17 10 6
9 8 9 20 14 11 15 10 7 13
9 3 9 2 14 5 7 6 13 19
9 8 2 17 1 11 9 15 20 5
12 15 3 4 11 7 6 5 16 8 14 17 9
11 5 10 14 3 17 7 15 20 19 11 4
9 1 14 16 2 13 3 9 20 17
9 2 3 9 5 8 10 17 11 16
```

### Output
```
6 5 5 5 4 4 4 3 3 3 3 3 3 3 2 2 2 0 
2
T
4 4 4 4 3 4 4 4 4 3 3 3 4 3 0 3 3 4 
F
1 1 1 1 1 1 1 1 1 1 2 2 2 2 1 2 2 2 
2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 
2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 
18
123

9 8 8 7 7 7 6 6 6 6 6 6 6 5 5 5 5 4 4 4 
1
T
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
F
1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 
1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 
1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 
236
130

11 10 9 9 9 9 8 8 8 8 7 6 6 6 6 5 5 5 5 5 5 5 5 5 5 4 4 4 4 3 3 3 2 2 1 
1
T
4 5 4 4 4 4 5 4 4 4 4 4 3 4 4 5 4 4 4 4 4 4 5 3 4 4 3 4 5 5 4 3 5 3 4 
F
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
307
495

15 13 13 13 13 13 12 12 12 12 11 11 11 11 11 11 11 11 10 10 10 10 9 9 9 9 9 9 9 9 9 9 8 8 7 7 7 7 5 5 
1
T
3 3 3 3 3 3 3 4 3 3 3 3 3 3 3 3 3 3 4 3 3 3 3 3 3 3 3 3 3 4 3 3 3 3 3 4 3 3 3 3 
F
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 
2 2 1 2 2 2 2 2 2 2 2 1 2 2 2 2 2 2 2 2 1 3 1 1 1 3 3 3 3 3 1 3 3 1 3 1 3 3 3 3 
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
2255
580
```

## Author of most of the content in README file:
- _Andrzej Jastrzębski from Gdańsk University of Technology_
