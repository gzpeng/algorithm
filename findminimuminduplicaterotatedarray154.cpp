#include <iostream>


int findminimum(int *nums, int len)
{
	int start = 0, end = len - 1;
	while (start + 1 < end)
	{
		int mid = (end - start) / 2 + start;
		if (nums[mid] < nums[end]) 
			end = mid;	  
		else if (nums[mid] > nums[end])
	 		start = mid + 1;
		else
			end--;
		
		
	}  
	
	if (nums[start] < nums[end]) return nums[start];
	else return nums[end];  
	
	
}  



int main(void)
{
	
	int nums[6] = {1, 1, 1, 1, 2, 1};
	std::cout << findminimum(nums, 6) << std::endl;
	return 0;	
}  
