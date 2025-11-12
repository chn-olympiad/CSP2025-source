#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5; 
string s;
long long a[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			int x = s[i] - '0';
			a[x]++;
		}
	}
	for (int i = 9;i >= 0;i--)
	{
		if (a[i] > 0)
		{
			for (int j = 1;j <= a[i];j++)
			{
				cout << i;
			}
		}
	}
	return 0;
}
