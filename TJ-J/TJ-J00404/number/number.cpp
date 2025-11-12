#include <bits/stdc++.h>
using namespace std;
long long num[15];
string str;
string ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> str;
	for(int i = 0;i < str.size();i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			num[str[i] - '0']++;
		}
	}
	for(int i = 9;i >= 0;i--)
	{
		while(num[i] > 0)
		{
			if(i == 0)
			{
				ans += '0';
				num[i]--;
			}
			if(i == 1)
			{
				ans += '1';
				num[i]--;
			}
			if(i == 2)
			{
				ans += '2';
				num[i]--;
			}
			if(i == 3)
			{
				ans += '3';
				num[i]--;
			}
			if(i == 4)
			{
				ans += '4';
				num[i]--;
			}
			if(i == 5)
			{
				ans += '5';
				num[i]--;
			}
			if(i == 6)
			{
				ans += '6';
				num[i]--;
			}
			if(i == 7)
			{
				ans += '7';
				num[i]--;
			}
			if(i == 8)
			{
				ans += '8';
				num[i]--;
			}
			if(i == 9)
			{
				ans += '9';
				num[i]--;
			}
		}
	}
	cout << ans;
	return 0;
}
