#include <bits/stdc++.h>
#define V vector
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;

const int maxn = 1e5;
const int maxm = 3;

int T, n, ans;
V<int> cs[maxm + 5];
pii b[maxm + 5];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		ans = 0;
		cs[1].clear(); cs[2].clear(); cs[3].clear();
		cin >> n;
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= 3; ++j)
				cin >> b[j].sec, b[j].fir = j;
			sort(b + 1, b + 3 + 1, [](pii o, pii p) {
				return o.sec > p.sec;
			});
			cs[b[1].fir].emplace_back(b[1].sec - max(b[2].sec, b[3].sec));
			ans += b[1].sec;
		}
		for(int i = 1; i <= 3; ++i)
		{
			if(cs[i].size() > n / 2)
			{
				sort(cs[i].begin(), cs[i].end());
				for(int j = 0; j < cs[i].size() - n/2; ++j)
					ans -= cs[i][j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}