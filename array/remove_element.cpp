#include <iostream> 
#include <vector> 
#include <stdio.h>
 
int removeElement(std::vector<int>& nums, int val) {
	
	int num_val = 0; 
	int new_length = 0;     
	int tmp = 0; 
	int i =0; 
	int i_from_end = nums.size()-1; 
	
//find how many elemnts in the array to calc the new length 
	for(int elm : nums){
		if(elm == val){
			num_val++; 
		}
	}
	new_length = nums.size() - num_val; 
	

	while(i < new_length)
	{
		//while(v[i_from_end] != val)		
		if(nums[i] == val){
			while(nums[i_from_end] == val)
			{
				printf("i_from_end %d\n", i_from_end);
				i_from_end--;
			}
			tmp = nums[i_from_end]; 
			nums[i_from_end] = nums[i]; 
			nums[i] = tmp; 
			i_from_end--; 
		}
		i++; 
		
	}
	return new_length; 
	
}




int main(){

	std::vector<int> v = {0,1,2,2,3,0,4,2}; 
//std::vector<int> v = {3,2,2,3}; 
	int new_length; 
	
	for(int n :v)
	{
		printf("%d ", n);

	}
	printf("\n"); 


	new_length = removeElement(v,2); 

	printf("new length: %d\n",new_length); 

	
	for(int n = 0 ; n < new_length ; n++)
	{
		printf("%d ", v[n]);

	}
	printf("\n"); 
}
