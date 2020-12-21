#include <iostream>
#include <string>
#include <list>
#include <algorithm>
bool containstr(std::string res, std::list<std::string> strlst)
{
	for (auto str : strlst)
	{
		if (str == res)
			return true;
	}
		
	return false;
}
bool workbreak(std::string str, std::list<std::string> strlst)
{
	bool dp[str.length() + 1];
	std::fill(dp, dp + str.length() + 1, false);
	dp[0] = true;
	for (int i = 1; i <= str.length(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (dp[j] && containstr(str.substr(j, i - j), strlst))
			{
				dp[i] = true;
				break;
			}
			
		}
	}
	return dp[str.length()];
}

int main(void)
{
	std::cout << workbreak("catsanddog", std::list<std::string>{"cat", "sand", "dog"}) << std::endl;
	return 0;
}
