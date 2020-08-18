#include<iostream> 
#include<vector> 
#include<map> 

/*Given an array arr of integers, 
check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).*/ 

bool checkIfExist(std::vector<int>& arr) {
    if(arr.size() < 2)
		return false; 
	
	std::map<int, int> m; 

	for(int n : arr){
		if (m[n*2]){
			return true; 
 		}
		if((n % 2)== 0 && m[n/2]){

			return  true; 			
		}
		m[n] = 1;
	} 
	
	return false;
}




int main(){

	std::vector<int> v1 = {10, 2, 5, 3};
	std::vector<int> v2 = {7,1,14,11}; 
	std::vector<int> v3 = {3,1,7,11}; 
	std::vector<int> v4 = {-2,0,10,-19,4,6,-8}; 
	std::vector<int> v5 = {0,0}; 
	std::cout << "V1: "<< checkIfExist(v1)<< "\n"; 
	std::cout << "V2: "<< checkIfExist(v2)<< "\n"; 
	std::cout << "V3: "<< checkIfExist(v3)<< "\n"; 
	std::cout << "V4: "<< checkIfExist(v4)<< "\n"; 
	std::cout << "V5: "<< checkIfExist(v5)<< "\n"; 


}


