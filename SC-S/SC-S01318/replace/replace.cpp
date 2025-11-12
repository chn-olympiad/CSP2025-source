#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 205, mod = 1e9 + 7, bs = 5307;
int ans;
int be, en;
int n, q, m;
string s, t;
map < int, vector<int> > mp[2];

int calc(vector <int> x, vector <int> y)
{
	int i, j, res = 0;
	if(x.size() == 0 || y.size() == 0) return 0;
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	i = j = 0;
	
	while(1)
	{
		if(i >= x.size() || j >= y.size())
			return res;
		
		if(x[i] < y[j]) i++;
		else if(x[i] > y[j]) j++;
		else res++, i++, j++;
	}
}
 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int i, j, k;
	int len, tmp;
	cin >> n >> q;
	
	for(i = 1; i <= n; i++)
	{
		cin >> s >> t;

		len = s.size(), tmp = 0;
		for(j = 0; j < len; j++)
			tmp = (tmp * bs + (s[j] - '0')) % mod;
		mp[0][tmp].push_back(i);
		
		len = t.size(), tmp = 0;
		for(j = 0; j < len; j++)
			tmp = (tmp * bs + (t[j] - '0')) % mod;
		mp[1][tmp].push_back(i);
	}
	
	while(q--)
	{
		cin >> s >> t;
		s = " " + s;
		t = " " + t;
		int t0, t1;
		ans = 0;
		n = s.size(), m = t.size();

		for(i = 1; i <= min(n, m); i++)
		{
			for(j = i; j <= min(n, m); j++)
			{
				t0 = t1 = 0;
				
				for(k = 1; k < i; k++)
					if(s[k] != t[k])
						break;
				
				if(k < i) continue;
				
				for(k = 1; k < min(n, m) - j + 1; k++)
					if(s[n - k + 1] != t[m - k + 1])
						break;
				
				if(k < min(n, m) - j + 1) continue;
				
				for(k = i; k <= j; k++)
				{
					t0 = (t0 * bs + s[k] - '0') % mod;
					t1 = (t1 * bs + t[k] - '0') % mod;
				}
				
				ans += calc(mp[0][t0], mp[1][t1]);
			}
		}
		
		cout << ans << "\n";
	}
	return 0;
}