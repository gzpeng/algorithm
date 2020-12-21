#include <iostream>
#include <utility>
#include <cstring>
#include <cmath>

int count = 0;
int pointer = 0;
char *tempbuf = new char[5];
int counttime = 0;
int read4(char *temp)
{	
	char src[] = "abcdefghijk";
	char *dest = strncpy(temp, src + counttime, 4);
	counttime += strlen(dest);
	return strlen(dest);
}

int read(char *buf, int n)
{
	int index = 0;
	while (index < n)
	{
		if (pointer == 0)
		{
			count = read4(tempbuf);
		}
		if (count == 0) break;
		while (index < n && pointer < count)
		{
			buf[index++] = tempbuf[pointer++];  
		}
		if (pointer == count) pointer = 0;
	}  
	return index;
}  



int main(void)
{
	char *buf = new char[10];
	std::fill(buf, buf + 10, '\0');
	std::cout << read(buf,2) << std::endl;
	std::cout << buf << std::endl;
	std::cout << read(buf,3) << std::endl;
	std::cout << buf << std::endl;
	delete []buf;
	return 0;	
}  
