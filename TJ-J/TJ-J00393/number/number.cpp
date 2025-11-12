#include <bits/stdc++.h>

int main()
{
	std::freopen("number.in", "r", stdin);
	std::freopen("number.out", "w", stdout);
		
	std::string s;
	std::cin >> s;
	std::vector<int> vec;
	for(int i = 0; i < s.size(); i++)
	{
		if('0' <= s[i] && s[i] <= '9')
			vec.push_back(-(s[i]-'0'));
	}
	std::sort(vec.begin(), vec.end());
	bool isVoid = true;
	for(int i = 0; i < vec.size(); i++)
	{
		if(vec[i] != 0 || !isVoid)
		{
			std::cout << -vec[i];
			isVoid = false;
		}
	}
	if(isVoid)
		std::cout << 0;
	std::cout << '\n';
	return 0;
} 
