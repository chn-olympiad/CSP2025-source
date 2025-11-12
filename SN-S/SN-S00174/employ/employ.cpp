#include <bits/stdc++.h>
using namespace std;
int n, m, x[505];
string a;
int cmp(int a, int b)
{
	return a<b;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> a;
	bool f = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> x[i];
		if (x[i] == 0) f = 1;
	}
	sort(x+1, x+1+n,cmp);
	if (m == n && f)
	{
		for (int i = 1;i <= n;i++)
		{
			if (x[i] < i)
			{
				cout << 0;
				return 0;
			}
		}
	}
	return 0;
}

