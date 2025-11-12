#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

const int N = 1e5 + 10;

const ull base = 1331;

const ull inf = ULONG_LONG_MAX;

int n, q, ans;

ull pre[2][N];

string s[N][2], t[2];

map<ull, map<ull, int>> cnt;

ull _hash(const string& str)
{
	ull h = 0, l = str.size();
	for (int i = l - 1; i >= 0; i--)
		h = str[i] + h * base;
	return h;
}

ull qpow(ull x, ull y)
{
	ull ans = 1;
	while(y)
	{
		if (y & 1) ans = x * ans;
		x = x * x;
		y >>= 1;
	}
	return ans;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) 
		cin >> s[i][0] >> s[i][1];
	for (int i = 1; i <= n; i++)
	{
		cnt[_hash(s[i][0])][_hash(s[i][1])]++;
	}
		
	while(q--)
	{
		ans = 0;
		cin >> t[0] >> t[1];
		int len = t[0].size();
		int L = len + 1, R = 0;
		for (int i = 0; i < len; i++) 
			if (t[0][i] != t[1][i]) 
				L = min(L, i), R = max(R, i);
		
		for (int j = 0; j <= 1; j++)
		{
			pre[j][len] = 0;
			for (int i = len - 1; i >= 0; i--)
				pre[j][i] = pre[j][i + 1] * base + t[j][i];			
		} 
		for (int l = 0; l <= L; l++)
		{
			for (int r = len - 1; r >= R; r--)
			{
				ull hash0 = pre[0][l] - pre[0][r + 1] * qpow(base, r - l + 1);
				ull hash1 = pre[1][l] - pre[1][r + 1] * qpow(base, r - l + 1);
				if (cnt.count(hash0))
					if (cnt[hash0].count(hash1))
						ans += cnt[hash0][hash1];
			}
		}			
		cout << ans << "\n";
	}
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

2
0

3 4
a b
b c
c d
aa bb
aa b
a c 
b a

0
0
0
0
*/
