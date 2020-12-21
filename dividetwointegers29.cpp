#include <iostream>
#include <cmath>
#include <climits>

/*
+ -
0
cross the border
*/


long  mydivide(long  dividend, long  divisor);
int dividetwointegers(int dividend, int divisor)
{
	if (divisor == 0) return -1;
	int sign = 1;
	if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) sign = -1;
	long ldividend = 0, ldivisor = 0;
	if (dividend < 0)
		ldividend = long(dividend * -1);
	else
		ldividend = long(dividend);
	if (divisor < 0)
		ldivisor = long(divisor * -1);
	else
		ldivisor = long(divisor);
	long  res = 0;
	res = mydivide(ldividend, ldivisor);
	if (sign == 1 && res > INT_MAX) return INT_MAX;
	if (sign == -1 && res > INT_MAX) return INT_MIN;
	return int(sign * res);
}  

long  mydivide(long  dividend, long  divisor)
{
	if (dividend < divisor) return 0;
	long  sum = divisor, multiple = 1;
	while ((sum + sum) < dividend)
	{
		sum += sum;
		multiple += multiple;
	}  
	return multiple + mydivide(dividend - sum, divisor);
}  

int main(void)
{
	std::cout << dividetwointegers(-8, 2) << std::endl;
	return 0;	
}  
