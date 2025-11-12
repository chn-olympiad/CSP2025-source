//µ­³þÜ² 
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
int TTT = 1, n, q, ans[N];
basic_string <int> hs[N][2], ht[N][2];
string s[N][2], t[N][2];
map < pair<string, string>, int> mp;

void solve(int i, int j)
{
	while(find(s[i], s[j]))
	{
		
	}
}

void mian()
{
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	for(int i = 1; i <= q; i++) cin >> t[i][0] >> t[i][1];
	
	if(q <= 200 && q != 1)
	{
		for(int i = 1; i <= n; i++) mp[{s[i][0], s[i][1]}]++;
//		for(auto x : mp) cout << x.first.first << " " << x.first.second << "\n";
		for(int i = 1; i <= q; i++)
		{
			int ans = 0;
			if(t[i][0].size() != t[i][1].size()) {cout << "0\n"; continue;}
			for(int l = 0; l < t[i][0].size(); l++)
			{
				string a, b;
				for(int r = l; r < t[i][0].size(); r++)
				{
					a += t[i][0][r], b += t[i][1][r];
					if(mp.count({a, b}))
					{
						bool f = true;
						for(int j = 0; j < t[i][0].size(); j++)
							if((j < l || j > r) && t[i][0][j] != t[i][1][j]) {f = false; break;}
						if(f) ans += mp[{a, b}];
					}
				}
			}
			cout << ans << "\n";
		}
	}
//	else
//	{
//		for(int i = 1; i <= q; i++)
//		{
//			if(t[i][0].size() != t[i][1].size()) {cout << "0\n"; continue;}
//			for(int j = 1; j <= n; j++) solve(i, j);
//		}
//	}
}

signed main()
{	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
//	cin >> TTT;
	while(TTT--) mian();
	return 0;
}
//3 4
//a b
//b c
//c d
//aa bb
//aa b
//a c
//b a


