#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define V vector
#define x first
#define y second
using namespace std;

const int maxn = 2e5;
const int mod = 998244353;

string s[maxn + 5][2];

int qpow(int a, int b)
{
	if(!b) return 1;
	int tmp = qpow(a, b>>1);
	return tmp * tmp % mod * (b&1 ? a : 1) % mod;
}

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	srand(time(0));
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> s[i][0] >> s[i][1];
	while(~--q)
	{
		string t[2];
		cin >> t[0] >> t[1];
		if(t[0].size() != t[1].size())
		{
			cout << "0\n";
			continue;
		}
		int a, b;
		a = b = 0;
		for(int i = 0; i < t[0].size() && t[0][i] == t[1][i]; ++i)
			++a;
		for(int i = t[0].size()-1; (~i) && t[0][i] == t[1][i]; --i)
			++b;
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			if(s[i][0].size() >= t[0].size() - a - b && s[i][0].size() <= t[0].size())
			{
				for(int l = max((int)(t[0].size()-s[i][0].size()-b), 0); l <= a && l + s[i][0].size() <= t[0].size(); ++l)
				{
					int r = l + s[i][0].size();
					bool T = 1;
					for(int k = 0; k <= 5 && T; ++k)
					{
						int j = rand()%(r-l) + l;
						if(t[0][j] != s[i][0][j-l] || t[1][j] != s[i][0][j-l])
							T = 0;
					}
					for(int j = l; j < r && T; ++j)
						if(t[0][j] != s[i][0][j-l] || t[1][j] != s[i][1][j-l])
							T = 0;
					if(T)
						++ans;
				}
			}
		cout << ans << '\n';
	}

	return 0;
}
