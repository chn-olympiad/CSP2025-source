#include <bits/stdc++.h>
using namespace std;
string s;
int f = 1, a[100];
signed main ()
{
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	//OK100
	
	ios::sync_with_stdio(false);
	cin.tie (0), cout.tie (0);
	
	cin >> s;
	for (int i = 0; i < s.size (); i ++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[s[i] - '0'] ++;
		}
	}
	for (int i = 9; i >= 0; i --)
	{
		if (f && i == 0)cout << 0;
		else 
		{
			f = 0;
			while (a[i] --) cout << i;
		}
	}
}
