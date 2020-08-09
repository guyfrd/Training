#include<iostream> 
#include<vector> 
#include <cmath>        // std::abs

void print_vec(std::vector<int>& nums1){

	for(int n : nums1) {
		std::cout << n << " "; 
	}
		std::cout << "\n";
}

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n){
	int num2_i = 0, num1_i = 0; 
	
	while(num1_i < (m +n) && num2_i < n)
	{
		if(nums1[num1_i] < nums2[num2_i]){
				num1_i++; 
		} else { 		
			nums1.insert(nums1.begin() + num1_i, nums2[num2_i]); 
			num2_i++;
			print_vec(nums1);
		}		
	}

	
	while(num2_i < n){
		nums1.push_back(nums2[num2_i]); 
		num2_i++;
	}

}  


int main(){
	std::vector<int> v1 = {1,2,3} ;
	std::vector<int> v2 = {2,5,6};
	

	merge(v1, v1.size(), v2, v2.size()); 
	

	for(int n : v1) {
		std::cout << n << "\n"; 
	}

}


/*

std::vector<int>& diff_merge(std::vector<int>& v1, std::vector<int>& v2){ 

std::vector<int> v_res; 
	int short_size = v1.size() < v2.size() ? v1.size() : v2.size();  
	
	std::vector<int>& long_vec = v1.size() < v2.size() ? v2 : v1;  
	std::cout<< "short_size:" << short_size << "\n";	

	for (int i = 0; i < short_size; i++){
		std::cout << "v1: " << v1[i] << "v2: " << v2[i] << "\n" ;  
		if(v1[i] < v2[i])
		{
			v_res.push_back(v1[i]);
			v_res.push_back(v2[i]);
		} else { 
			v_res.push_back(v2[i]);		
			v_res.push_back(v1[i]);		
		}
	}
	for(int elem : long_vec){ 
		v_res.push_back(elem); 
	}
} */
