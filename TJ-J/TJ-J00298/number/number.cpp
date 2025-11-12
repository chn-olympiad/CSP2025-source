#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	string s, a = "";
	int num = 0;
	cin >> s;
	for(int i = 0;i <= 16;i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a += s[i];
		}
		else
		{
			continue;
		}
	}
	for(int j = 0;j <= 16;j++)
	{
		for(int i = 0;i <= 16;i++)
		{
			if(a[i] < a[i + 1])
			{
				num = a[i];
				a[i] = a[i + 1];
				a[i + 1] = num;
			}
			else
			{
				continue;
			}
		}
	}
	cout << a;
	
	return 0;
}
