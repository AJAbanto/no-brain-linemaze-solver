# no-brain-linemaze-solver
Simple line maze solver, intended to show beginners can solve line mazes without loops

## Building
```
g++ shortest_path.cpp -o shortest_path.o
```
## Running
```
./shortest_path.o
```

## How it works
This algorithm relies on the recognition of turn sequences that result in a complete 360 degree turn. 