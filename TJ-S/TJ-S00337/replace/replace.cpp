#include <bits/stdc++.h>
using namespace std;

namespace pb 
{
	const int MAXN = 2e5 + 5;
	int n, q;
	long long ans;
	struct STRINGpair
	{
		int fb, secb, l;
	}sp[MAXN];
	string t1, t2, s1, s2;
	void solve()
	{
		cin >> n >> q;
		for(int i = 1; i <= n; i++)
		{
			cin >> s1 >> s2;
			sp[i].fb = s1.find('b');
			sp[i].secb = s2.find('b');
			sp[i].l = s1.size();
		}
		while(q--)
		{
			ans = 0;
			cin >> t1 >> t2;
			int t1b = t1.find('b');
			int t2b = t2.find('b');
			int tl = t1.size(); 
			for(int i = 1; i <= n; i++)
			{
				if(sp[i].l <= tl)
				{
					if(t1b >= sp[i].fb && tl - t1b >= sp[i].l - sp[i].fb)
					{
						int d = sp[i].secb - sp[i].fb;
						if(t2b - t1b == d) ans++;
					}
				}
			}
			cout << ans << endl;
		}
	}
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pb::solve();
	return 0;
}
