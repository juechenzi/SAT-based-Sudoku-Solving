#include <iostream>

using namespace std;

/* 
 * Helper function to find the associated propositional variable s_{xyz}
 * for when the entry in row x column y is assigned value z.
 * 
 * The number can be represented in base-9.
 */
int help(int x,int y,int z){
  if(x > 8 | y > 8) cerr<<"Wrong values"<<endl;
  return x*9*9+y*9+z;
}

int main(){
	char a;
	int puzzle [9][9];
	int tot = 0;

	// Use a 9*9 2D array for the puzzle input.
	// Keep track of each pre-assigned entry and 
	// calculate the total number of pre-assigned entries
	for(int i = 0; i < 9;++i){
		for(int k =0;k < 9;++k){
			cin >> a;
			if(a > '0' && a <= '9'){
			  tot++;
			  puzzle[i][k] = a -'0';
			}
			else puzzle[i][k] = 0;
		}
	}
	
	// Look for pre-assigned non-zero entries and translate
	// them to unit clauses. 
	// Add to 8829 the total number of pre-assigned entries.
	cout<<"p cnf "<<9*9*9<<" "<<tot+8829<<endl;
	for(int i = 0; i < 9;++i){
		for(int k =0;k < 9;++k){
		  if(puzzle[i][k]){
			cout<<help(i,k,puzzle[i][k]) <<" 0"<<endl;
		  }
		}
	}

	// Add the clauses that represent the condition that
	// there must be at least one number in each entry to output.
	for(int x=0;x < 9;++x){
	  for(int y = 0;y < 9;++y){
		//int tester = 0;	// DEBUG
	    for(int z = 1;z <10;++z){
	      cout<<help(x,y,z)<<' ';
		// if(reference[help(x,y,z)]) tester = 1;	// DEBUG
	    }
	    cout<<" 0"<<endl;
	  }
	}

	// Each number appears at most once in each row. 
    for(int x=0;x < 9;++x){
	    for(int y = 0;y < 9;++y){
	    	for(int z = 1;z <10;++z){
				for(int i = x+1;i < 9 ;++i){
					// (¬s_{xyz} ∨ ¬s_{iyz})
		  			cout<<"-"<<help(x,y,z)<<" -"<<help(i,y,z)<<" 0"<<endl;
					// if(reference[help(x,y,z)] && reference[help(i,y,z)] ) cout<<"Fucked up ROW " <<x<<y<<i<<endl;// DEBUG
				}
	      	}
		}
	}

	// Each number appears at most once in each column.
	for(int x=0;x < 9;++x){
	    for(int y = 0;y < 9;++y){
	      for(int z = 1;z <10;++z){
			for(int i = y+1;i < 9 ;++i){
		  	  cout<<"-"<<help(x,y,z)<<" -"<<help(x,i,z)<<" 0"<<endl;
		 	  // if(reference[help(x,y,z)] && reference[help(x,i,z)] ) cout<<"Fucked up Col " <<x<<y<<i<<endl;// DEBUG
		  }
	    }
	  }
	}

	// Each number appears at most once in each 3x3 sub-grid - part 1:
	for(int z = 1;z < 10;++z){
		for(int i = 0; i < 3;++i){
			for(int j = 0; j < 3;++j){
	  			for(int x =0;x < 3;++x){
	    			for(int y = 0; y < 3;++y){
						  for(int k= y+1;k < 3;++k){
		    				cout<<"-"<<help(3*i+x,3*j+y,z)<<" -"<<help(3*i+x,3*j+k,z)<<" 0"<<endl;
							// if(reference[help(3*i+x,3*j+y,z)] && reference[help(3*i+x,3*j+k,z)] ) cout<<"Fucked up 3*3 " <<x<<y<<i<<j<<k<<endl;// DEBUG
		  				  }
					}  
	      		}
	    	}
	  	}
	}

	// Each number appears at most once in each 3x3 sub-grid - part 2:
	for(int z = 1;z < 10;++z){
		for(int i = 0; i < 3;++i){
			for(int j = 0; j < 3;++j){
	  			for(int x =0;x < 3;++x){
	    			for(int y = 0; y < 3;++y){
		  				for(int k= x+1;k < 3;++k){
		    				for(int l = 0;l<3;++l){
								// if(reference[help(3*i+x,3*j+y,z)] && reference[help(3*i+k,3*j+l,z)] ) cout<<"Fucked up 3*3 " <<x<<y<<i<<j<<k<<" ";// DEBUG
		      					cout<<"-"<<help(3*i+x,3*j+y,z)<<" -"<<help(3*i+k,3*j+l,z)<<" 0"<<endl;
		    				}
		  				}
					}  
	      		}
	    	}
	  	}
	}
	// The above condition clauses should suffice for minimal encoding.
}
