#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(void){
    string temp;

    // Get the first line, it's either SAT or UNSAT.
    // If the first line is UNSAT, then there is no solution.
    getline(cin,temp);
    if(temp.find("UN") != string::npos) return 0;

    // Get the second line which is the truth assignment of
    // propositional variables.
    getline(cin,temp);

    stringstream inp(temp);
    int val;
    int count = 0;

    while(inp >>val){
        // If the variable is assigned to true, the variable's number
        // indicates the which value the sudoku entry should be. 
        // Do a mod operation and print that value to output.
        if(val > 0){
            cout<< (val+8)%9+1;
            count++;
            // Every 3 entries, print a space.
            // Every 9 entries, print a newline.
            if(count%3 ==0) cout <<" ";
            if(count == 9){
                cout<<endl;
                count = 0;
            }
        }
    }

    return 0;
}