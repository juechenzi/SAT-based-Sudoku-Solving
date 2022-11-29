touch cpu_times.txt
touch number_of_clauses.txt

for FILE in stat*; do
    grep 'CPU time' $FILE | grep -Eo '[+-]?[0-9]+([.][0-9]+)?' >> cpu_times.txt
done;

for FILE in stat*; do
    grep 'Number of clauses' $FILE | grep -Eo '[0-9]+' >> number_of_clauses.txt
done;
