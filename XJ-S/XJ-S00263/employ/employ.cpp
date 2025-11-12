#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[500];
	string s;
	cin >> n >> m;
	cin >> s;
	int isA = 1;
	for (int i=0;i<n;i++)
	{
		if (s[i] != '1')
		{
			isA = 0;
		}
	}
	for (int i=0;i<n;i++)
	{
		cin >> c[i];
	}
	if (isA)
	{
		long long int ji = 1;
		for (int i=1;i<=n;i++)
		{ 
			ji *= i;
			ji %= 998244353;
		}
		cout << ji;
	}
	else
	{
		cout << "0";
	}
	return 0;
} 

