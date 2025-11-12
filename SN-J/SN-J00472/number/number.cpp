#include <bits/stdc++.h>
using namespace std;
int main()
{
	int s[1000000];
	int n,maxn = 100000000;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (maxn < s[i])
		{
			maxn = s[i];
		}
	}
	cout << maxn;
	return 0;
}
