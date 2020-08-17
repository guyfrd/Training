#include<iostream> 
#include<vector> 


void print_vec(std::vector<int>& nums){

	for(int n : nums) {
		std::cout << n << " "; 
	}
		std::cout << "\n";
}

void swap(int* a, int* b){
	int temp; 

	temp = *a; 
	*a = *b; 
	*b = temp;
}  

int partition(int arr[], int low, int high)
{
	int pivot = high , index = low , i; 
	
	for(i = low; i < high; i++){
		if(arr[i] < arr[pivot]){
			swap(&arr[i], &arr[index]); 
			index++;
		}
	}

	swap(&arr[pivot] , &arr[index]); 
}

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 


int removeDuplicates(std::vector<int>& nums) {
 	int j = 0; 
	int arr_size = nums.size(); 
	
	for(int i = 1; i < nums.size(); i++){
		if( nums[i] != nums[j] ){
			j++; 
			nums[j] = nums[i]; 
		} 

	}
	return (j + 1); 
}



int main(){
	std::vector<int> v = {0,0,1,1,1,2,2,3,3,4};
	//std::vector<int> v = {1,1,2};
	
	int new_length = 0; 
	
	new_length = removeDuplicates(v); 
	printf("new length: %d\n", new_length); 
	print_vec(v); 

}
