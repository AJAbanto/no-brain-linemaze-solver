# no-brain-linemaze-solver
Simple line maze solver, intended to show how beginners can solve line mazes without loops

## Building
```
g++ shortest_path.cpp -o shortest_path.o
```
## Running
```
./shortest_path.o
```

## How it works
This algorithm relies on the recognition of turn sequences that can be simplified. 

### Assumptions
- The robot traverses the line maze using either a left-hand or right-hand rule
- There are no loops in the maze
- Actions taken when first traversing the line maze is stored in `vector<char>` arrays where each turn/action performed at an intersection is represented as a `char` . See below:

| Letter | Action |
| ---- | ---- | 
| `L` | Left turn|
| `R` | Right turn|
| `U` | U-turn|
| `S` | Head Straight |
| `E` | Maze end encountered (stopped) | 
### Patterns recognized 
| Pattern | Simplified result | Description |
| -------- | --------- | -------- |
| `L U L` | `S` | U-turn after a left |
| `R U R` | `S` | U-turn after a right |
| `S U L` | `R` | U-turn after going straight (while using Left-hand rule) |
| `S U R` | `L` | U-turn after going straight (while using Right-hand rule) |