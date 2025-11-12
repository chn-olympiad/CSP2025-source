#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int num[1000000];
bool cmp(int x , int y)
{
	return x > y;
}
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;
	cin >> s;
	int len = s.size();
	int j = 0;
	for(int i = 0 ; i < len ; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			num[j] = s[i] - '0';
			j++;
		}
	}
	sort(num , num+j , cmp);
	for(int i = 0 ; i < j ; i++)
	{
		cout << num[i]; 
	}
	return 0;
}
