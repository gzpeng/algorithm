#include <iostream>
#include <algorithm>
#include <list>


std::list<std::list<int> > threesum(int *nums, int len, int target)
{
	if (nums == NULL || len == 0)
	{
		std::list<std::list<int> > res;
		return res;
	}
	std::sort(nums, nums + len);
	std::list<std::list<int> > res;
	std::list<int> lst;
	for (int i = 0; i < len - 2; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		int sum = target - nums[i];
		int left = i + 1, right = len - 1;
		while (left < right)
		{
			if (nums[left] + nums[right] == sum)
			{
				lst.push_back(nums[i]);
				lst.push_back(nums[left]);
				lst.push_back(nums[right]);
				res.push_back(lst);
				lst.clear();
				while(left < right && nums[left] == nums[left + 1]) left++;
				while(left < right && nums[right] == nums[right - 1]) right--;
				left++;
				right--;
			}
			else if (nums[left] + nums[right] > sum) right--;
			else left++;
			
		}  
	}  
	
	return res;
	
}


int main(void)
{
	int nums[6] = {-1, 0, 1, 2, -1, -4};
	std::list<std::list<int> > res = threesum(nums, 6, 0);
	std::list<std::list<int> >::iterator it;
	std::list<int>::iterator lt;
	for (it = res.begin(); it != res.end(); it++)
	{
		std::cout << "[";
		for (lt = it->begin(); lt != it->end(); lt++)
		{
			std::cout << *lt << ",";
		}
		std::cout << "]" << std::endl;
	}
	return 0;
}  


