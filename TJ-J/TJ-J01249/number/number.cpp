#include <bits/stdc++.h>
using namespace std;

long long st[11] = {0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin >> str;
	for(long long i = 0;i < str.length();i++)
	{
		if(str[i] >= '0' && str[i] <= '9') 
		{
			st[str[i] - '0'] ++;
		}
	}
	for(long long i = 9;i >= 0;i--)
	{
		for(long long j = 1;j <= st[i];j++)
		{
			cout << i; 
		}
	}
	return 0;
}
