#include<iostream> 
#include<string>
#include <bits/stdc++.h>

using namespace std; 

void print_permute(string str, string out){

    if(str.length() == 0){
        cout << out << endl; 
        return; 
    }
    for(int i = 0; i < str.size(); i++){
        print_permute(str.substr(1), out+str[0]); 

        rotate(str.begin(), str.begin() + 1, str.end());
    }
   

}


int main(){

    string str = "abc"; 

    print_permute(str, ""); 

    return 0; 
}