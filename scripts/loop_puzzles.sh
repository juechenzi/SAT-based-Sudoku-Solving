for FILE in x*;
    do 
        ./sud2sat <$FILE >$FILE.cnf;
        minisat $FILE.cnf assign_$FILE.txt >stat_$FILE.txt;
        ./sat2sud <assign_$FILE.txt >solution_$FILE.txt;
done;