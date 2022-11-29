./sud2sat <puzzle.txt >puzzle.cnf
minisat puzzle.cnf assign.txt >stat.txt
./sat2sud <assign.txt >solution.txt
