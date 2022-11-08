#include <iostream>

using namespace std;
int help(int a,int b,int c){
  if(a > 8 | b > 8) cerr<<"What the hell"<<endl;
 // cout<<"[("<<a<<","<<b<<" )"<<"is "<<c<<" ]";
  return a*9*9+b*9+c;
}
int main(){
	char a;
	int puzzle [9][9];
	int tot = 0;
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
	//trouble shooting
	// int reference[730];
	// for(int i = 0;i < 730;++i) reference[i] = 0;
	//
	cout<<"p cnf "<<9*9*9<<" "<<tot+8829<<endl;
	for(int i = 0; i < 9;++i){
		for(int k =0;k < 9;++k){
		  if(puzzle[i][k]){
			cout<<help(i,k,puzzle[i][k]) <<" 0"<<endl;
			//reference[help(i,k,puzzle[i][k])] = 1;
		  }
		}
	}
	// One number in each entry

	for(int x=0;x < 9;++x){
	  for(int y = 0;y < 9;++y){
		//int tester = 0;	//trouble shooting
	    for(int z = 1;z <10;++z){
	      cout<<help(x,y,z)<<' ';
		//  if(reference[help(x,y,z)]) tester = 1;	//trouble shooting
	    }
		//if(tester == 0) cerr<<"Fucked up ENTRY"<<x<<y<<endl;	//trouble shooting
	    cout<<" 0"<<endl;
	  }
	}
	//for each number appears at most once in each row
       	for(int x=0;x < 9;++x){
	    for(int y = 0;y < 9;++y){
	      for(int z = 1;z <10;++z){
		for(int i = x+1;i < 9 ;++i){
		  cout<<"-"<<help(x,y,z)<<" -"<<help(i,y,z)<<" 0"<<endl;
		//  if(reference[help(x,y,z)] && reference[help(i,y,z)] ) cout<<"Fucked up ROW " <<x<<y<<i<<endl;//trouble shooting
		}
	      }
	    }
	}
	for(int x=0;x < 9;++x){
	    for(int y = 0;y < 9;++y){
	      for(int z = 1;z <10;++z){
		for(int i = y+1;i < 9 ;++i){
		  cout<<"-"<<help(x,y,z)<<" -"<<help(x,i,z)<<" 0"<<endl;
		 // 		  if(reference[help(x,y,z)] && reference[help(x,i,z)] ) cout<<"Fucked up Col " <<x<<y<<i<<endl;//trouble shooting
		}
	      }
	    }
	}
	for(int z = 1;z < 10;++z){
		for(int i = 0; i < 3;++i){
			for(int j = 0; j < 3;++j){
	  			for(int x =0;x < 3;++x){
	    			for(int y = 0; y < 3;++y){
						  for(int k= y+1;k < 3;++k){
		    cout<<"-"<<help(3*i+x,3*j+y,z)<<" -"<<help(3*i+x,3*j+k,z)<<" 0"<<endl;
		//	if(reference[help(3*i+x,3*j+y,z)] && reference[help(3*i+x,3*j+k,z)] ) cout<<"Fucked up 3*3 " <<x<<y<<i<<j<<k<<endl;//trouble shooting
		  }
		}  
	      }
	    }
	  }
	}
	for(int z = 1;z < 10;++z){
		for(int i = 0; i < 3;++i){
			for(int j = 0; j < 3;++j){
	  			for(int x =0;x < 3;++x){
	    			for(int y = 0; y < 3;++y){

		  				for(int k= x+1;k < 3;++k){
		    				for(int l = 0;l<3;++l){
						//		if(reference[help(3*i+x,3*j+y,z)] && reference[help(3*i+k,3*j+l,z)] ) cout<<"Fucked up 3*3 " <<x<<y<<i<<j<<k<<" ";//trouble shooting
		      					cout<<"-"<<help(3*i+x,3*j+y,z)<<" -"<<help(3*i+k,3*j+l,z)<<" 0"<<endl;
			  
		    }
		  }
		}  
	      }
	    }
	  }
	}
	
}
