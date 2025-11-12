#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
char c;
int n;
int idx, a[100];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	while (cin >> c)
	{
		if (c <= '9' && c >= '0')
		{
			a[c - '0'] ++;
		}
	}
	for (int i = 9;i >= 0; i --)
	{
		while(a[i])
		{
			cout << i;
			a[i] --;
		}
	}
	return 0;
}
