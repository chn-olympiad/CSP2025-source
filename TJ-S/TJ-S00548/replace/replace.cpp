#include<bits/stdc++.h>
using namespace std;
int n, q, sum;
char s[10000][10000][2], t[10000][10000][2], sl[10000];
int get_len(int a, int b)
{
	int ans = 0;
	while(t[a][ans][b] != 0)
	{
		ans++;
	}
	return ans;
}
bool check(int a, int b, int c)
{
	for (int i = 0; i < sl[b]; i++)
	{
		if (s[b][i][0] != t[c][a+i][0])
		{
			return false;
		}
		if (s[b][i][1] != t[c][a+i][1])
		{
			return false;
		}
	}
	return true;
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
	string x;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		for (int j = 0; j <= x.length(); j++)
		{
			s[i][j][0] = x[j];
		}
		cin >> x;
		for (int j = 0; j <= x.length(); j++)
		{
			s[i][j][1] = x[j];
		}
		sl[i] = x.length();
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> x;
		for (int j = 0; j <= x.length(); j++)
		{
			t[i][j][0] = x[j];
		}
		cin >> x;
		for (int j = 0; j <= x.length(); j++)
		{
			t[i][j][1] = x[j];
		}
	}
	for (int i = 1; i <= q; i++)
	{
		sum = 0;
		if (get_len(i, 0) != get_len(i, 1))
		{
			cout << 0 << endl;
			continue;
		}
		int tl = get_len(i, 0);
		for (int j = 0; j <= tl; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (j + sl[k] > tl)
				{
					continue;
				}
				if (check(j, k, i))
				{
					sum++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
