#include <iostream>
#include <cmath>
int mysqrt(int x)
{
	if (x < 0) return 0;
	int low = 1, high = x;
	while (low <= high)
	{
		long mid = (high - low) / 2 + low;
		if (mid * mid == x) return mid;
		else if (mid * mid < x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (high * high < x)
		return high;
	else
		return low;
}  


int mysqrt2(int x)
{
	if (x < 0) return 0;
	std::cout << x << std::endl;
	long res = x;
	while (res * res > x)
	{
		res = (res + x / res) / 2;
	}
	return int(res);
	
}  

double mysqrt3(int x)
{
	double cur = double(x), pre = 0;
	while (std::abs(cur - pre) > 0.000001)
	{
		pre = cur;
		cur = (pre + x / pre) / 2;
		std::cout << cur << "  " << pre << std::endl;
	}  

	return cur;	
}  

double mysqrt4(int x)
{
	double cur = double(x);
	while (std::abs(cur * cur - x) > 0.000001)
	{
		cur = (cur + x / cur) / 2;
		std::cout << cur << std::endl;
	}  

	return cur;	

}
double mysqrt5(int x)
{
	double left = 0;
	double right = double(x);
	double result = 0;
	double mid = 0;
	while(std::abs(result - x) > 0.000001)
	{
		mid = (left + right) / 2;
		std::cout << mid << std::endl;
		result = mid * mid;
		if (result > x)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return mid;
}
int main(void)
{
	//std::cout << mysqrt4(25) << std::endl;
	//std::cout << mysqrt4(8) << std::endl;
	//std::cout << mysqrt2(2.3) << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << mysqrt5(8) << std::endl;
	std::cout << mysqrt(8) << std::endl;
	std::cout << mysqrt4(8) << std::endl;
	return 0;	
}  
