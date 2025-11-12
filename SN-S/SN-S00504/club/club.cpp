#include<bits/stdc++.h>
#define fir first
#define sec second
#define ll long long
#define ull unsigned ll
#define ldb long double
#define inf 1000000000
#define infll 1000000000000000000ll
#define maxn 100000
using namespace std;
int aqx, n;
pair<int, int> A[maxn + 10][3];
vector<int> V[3];
bool cmp(int x, int y)
{
	return A[x][0].fir - A[x][1].fir < A[y][0].fir - A[y][1].fir;
}
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	return;
}
void solve()
{
	cin >> n;
	for (int i = 0;i < 3;i++) V[i].clear();
	for (int i = 1;i <= n;i++) for (int j = 0;j < 3;j++) {cin >> A[i][j].fir; A[i][j].sec = j;}
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		sort(A[i], A[i] + 3); reverse(A[i], A[i] + 3);
		ans += A[i][0].fir; V[A[i][0].sec].push_back(i);
	}
	int idx = -1;
	for (int i = 0;i < 3;i++) if (V[i].size() * 2 > n) idx = i;
	if (idx == -1) {cout << ans << "\n"; return;}
	sort(V[idx].begin(), V[idx].end(), cmp);
	for (int i = 0;i < V[idx].size() - n / 2;i++) ans -= A[V[idx][i]][0].fir - A[V[idx][i]][1].fir;
	cout << ans << "\n";
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	init();
	cin >> aqx;
	while (aqx--) solve();
	return 0;
}
