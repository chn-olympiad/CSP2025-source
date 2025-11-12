#include<bits/stdc++.h>
#define int long long
using namespace std;
int re()
{
	int sum = 0, p = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')p = -1; ch = getchar();}
	while(isdigit(ch)){sum = sum * 10 + (ch - '0'); ch = getchar();}
	return sum * p;
}
const int M = 5e3 + 10, base = 19491001, MOD = 1e9 + 9;
int n, q, pw[M], hs[M][2], len[M];
char s[2][M], t[2][M];
map<pair<int, int> ,int> mp;
int calc(int l, int r, int op)
{
	return (hs[r][op] - hs[l - 1][op] * pw[r - l + 1] % MOD + MOD) % MOD;
}
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = re(), q = re(), pw[0] = 1;
	for(int i = 1; i <= 5000; i++) pw[i] = pw[i - 1] * base % MOD;
	for(int i = 1; i <= n; i++) 
	{
		cin >> (s[0] + 1) >> (s[1] + 1);
		len[i] = strlen(s[0] + 1);
		for(int j = 1; j <= len[i]; j++)
		{
			hs[j][0] = (hs[j - 1][0] * base + (s[0][j] - 'a' + 1)) % MOD;
			hs[j][1] = (hs[j - 1][1] * base + (s[1][j] - 'a' + 1)) % MOD;
		}

		mp[{hs[len[i]][0], hs[len[i]][1]}]++;
	}
	
	while(q--)
	{
		cin >> (t[0] + 1) >> (t[1] + 1);
		int Len = strlen(t[0] + 1);
		for(int i = 1; i <= Len; i++)
		{
			hs[i][0] = (hs[i - 1][0] * base + (t[0][i] - 'a' + 1)) % MOD;
			hs[i][1] = (hs[i - 1][1] * base + (t[1][i] - 'a' + 1)) % MOD;
		}
		int st = 1, ed = Len;
		for(int i = 1; i <= Len; i++)
			if(t[0][i] != t[1][i]) {st = i;break;}
		for(int i = Len; i >= 1; i--)
			if(t[0][i] != t[1][i]) {ed = i;break;}

		int ans = 0;
		for(int i = ed; i <= Len; i++)
		{
			for(int j = 1; j <= st; j++)
			{
				ans += mp[{calc(j, i, 0), calc(j, i, 1)}];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
