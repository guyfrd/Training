#include<iostream> 
#include<vector> 


bool validMountainArray(std::vector<int>& A) {
	int i = 0; 
	
	if( A.size() < 3 )
		return false; 
 
	while ( A[i] < A[i+1] && i < A.size() ){
		
		i++; 
	}
	printf("max i: %d \n", i); 

 	 if(i == A.size() -1 || i == 0)
        return false;

	while (i < A.size() -1){
		printf("i: %d curr: %d next: %d\n", i, A[i], A[i+1]);
		if(A[i+1] >= A[i])
			return false; 
		
		i++; 
	}
	return true;

}


int main(){
	std::vector<int> v1 = { 2,1 }; 
	std::vector<int> v2 = { 3, 5, 5 }; 
	std::vector<int> v3 = { 9,8,7,6,5,4,3,2,1,0 }; 

	std::cout << "v1: " << validMountainArray(v1) << "\n";
	std::cout << "v2: " << validMountainArray(v2) << "\n";
	std::cout << "v3: " << validMountainArray(v3) << "\n";  
}

