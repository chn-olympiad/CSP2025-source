#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
constexpr int MAXN = 1e5 + 5;
int n, a[MAXN][3];
PII gr[3][MAXN]; int gidx[3];
LL ans;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		gidx[0] = gidx[1] = gidx[2] = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			     if (a[i][0] >= max(a[i][1], a[i][2])) gr[0][++gidx[0]] = { a[i][0], max(a[i][1], a[i][2]) };
			else if (a[i][1] >= max(a[i][0], a[i][2])) gr[1][++gidx[1]] = { a[i][1], max(a[i][0], a[i][2]) };
			else if (a[i][2] >= max(a[i][0], a[i][1])) gr[2][++gidx[2]] = { a[i][2], max(a[i][0], a[i][1]) };
		}
		ans = 0;
		for (int tp = 0; tp < 3; tp++)
		{
			if (gidx[tp] > (n >> 1))
			{
//				cerr << T << '\n';
				sort(gr[tp] + 1, gr[tp] + gidx[tp] + 1, [](PII x, PII y){
					return x.first - x.second > y.first - y.second;
				});
				for (int i = 1; i <= (n >> 1); i++)
					ans += gr[tp][i].first;
				for (int i = (n >> 1) + 1; i <= gidx[tp]; i++)
					ans += gr[tp][i].second;
			}
			else
			{
				for (int i = 1; i <= gidx[tp]; i++)
					ans += gr[tp][i].first;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}