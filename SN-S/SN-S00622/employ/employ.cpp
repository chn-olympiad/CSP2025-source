#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, n0, m0, c[10000007];
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for(int i = 1; i <= n; i++)
	{
		n0 *= i;
	}
	for(int i = 1; i <= m; i++)
	{
		m0 *= i;
	}
	cout << n0 / m0;
	return 0;
}


