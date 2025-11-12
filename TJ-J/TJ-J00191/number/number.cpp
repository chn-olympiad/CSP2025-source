#include<bits/stdc++.h>

char s[1000000 + 10] = {'*'};
int chang = 0;

int main()
{
	std::freopen("number.in" , "r" , stdin);
	std::freopen("number.out" , "w" , stdout);
	
	std::cin>>s;
	for(int i = 0 ; i < 1000000 && s[i] != '\0' ; i++)
	{
		if(s[i] - '0' > 9)
		{
			for(int j = i ; j < 1000000 ; j++)
			{
				s[j] = s[j + 1];
			}
		}
	}
	chang = 0;
	for(int i = 0 ; i < 1000000 && s[i] != '\0' ; i++)
	{
		chang++;
	}
	
	std::sort(s , s + chang);
	for(int i = chang - 1 ; i >= 0 ; i--)
	{
		if(s[i] - '0' <= 9)
		{
			std::cout<<s[i];
		}
	}
	
	return 0;
}
