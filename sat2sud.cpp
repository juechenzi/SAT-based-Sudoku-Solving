#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    string temp;
    getline(cin,temp);
    if(temp.find("UN") != string::npos) return 0;
    getline(cin,temp);
    stringstream inp(temp);
    int val;
    int count = 0;
    while(inp >>val){
        if(val > 0){
            cout<< (val+8)%9+1;
            count++;
            if(count%3 ==0) cout <<" ";
            if(count == 9){
                cout<<endl;
                count = 0;
            }
        }
    }
}