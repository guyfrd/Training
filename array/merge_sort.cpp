#include<iostream> 
#include<vector> 


int main()
{

	std::vector<int> v = {7, 6, 5,3,2}; 
	int v_sz = v.size(); 

	for (int elem : v){
		std::cout<< elem << '\n'; 
	}


	return 0;
}
