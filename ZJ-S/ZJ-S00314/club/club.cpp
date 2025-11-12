#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 100;
int n, a[N][4], t;
pair <int, int> ak[4], e;
vector <int> akioi[4], eioi;
int maxid(int x, int y, int z)
{
	int d = max(x, max(y, z));
	if(d == x) return 1;
	else if(d == y) return 2;
	else return 3;
}
int anomax(int x, int y, int z)
{
	int d = max(x, max(y, z));
	if(d == x) return max(y, z);
	else if(d == y) return max(x, z);
	else return max(x, y);
}
bool cmp1(int x, int y)
{
	return a[x][1] - anomax(a[x][1], a[x][2], a[x][3]) > a[y][1] - anomax(a[y][1], a[y][2], a[y][3]);
}
bool cmp2(int x, int y)
{
	return a[x][2] - anomax(a[x][1], a[x][2], a[x][3]) > a[y][2] - anomax(a[y][1], a[y][2], a[y][3]);
}
bool cmp3(int x, int y)
{
	return a[x][3] - anomax(a[x][1], a[x][2], a[x][3]) > a[y][3] - anomax(a[y][1], a[y][2], a[y][3]);
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld", &n);
		ak[1] = ak[2] = ak[3] = e;
		akioi[1] = akioi[2] = akioi[3] = eioi;
		for(int i = 1; i <= n; ++i)
		{
			scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
			int d = maxid(a[i][1], a[i][2], a[i][3]);
			ak[d] = make_pair(ak[d].first + 1, ak[d].second + a[i][d]);
			akioi[d].push_back(i);
		}
		int ans = ak[1].second + ak[2].second + ak[3].second;
		sort(akioi[1].begin(), akioi[1].end(), cmp1);
		sort(akioi[2].begin(), akioi[2].end(), cmp2);
		sort(akioi[3].begin(), akioi[3].end(), cmp3);
		for(int tk = 1; tk <= 3; tk++)
		{
			if(ak[tk].first <= n / 2) continue;
			for(int j = n / 2; j < akioi[tk].size(); j++)
			{
				int now = akioi[tk][j];
				ans -= a[now][tk] - anomax(a[now][1], a[now][2], a[now][3]);
			}
		}
		cout << ans << "\n";
	}
}
