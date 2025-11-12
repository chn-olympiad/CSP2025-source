#include <bits/stdc++.h>
using namespace std;

int T, n;

const int N = 1e5 + 5;

int aa = 0, bb = 0, cc = 0;
int a[N], b[N], c[N], d[N];

void solve()
{
	aa = 0, bb = 0, cc = 0;
	int sum = 0, kk = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		int maxn = max(a[i], max(b[i], c[i]));
		//d[i] = maxn - ((a[i] + b[i] + c[i]) - (maxn + minn));
		if(a[i] == maxn) aa++;
		if(b[i] == maxn) bb++;
		if(c[i] == maxn) cc++;
		sum += maxn;
	}
	int mxx = 0;
	if(max(aa, max(bb, cc)) == aa) mxx = 1;
	if(max(aa, max(bb, cc)) == bb) mxx = 2;
	if(max(aa, max(bb, cc)) == cc) mxx = 3;
	for(int i = 1; i <= n; i++)
	{
		int maxn = max(a[i], max(b[i], c[i]));
		int minn = min(a[i], min(b[i], c[i]));
		if(a[i] == maxn && mxx == 1) d[++kk] = maxn - ((a[i] + b[i] + c[i]) - (maxn + minn));
		if(b[i] == maxn && mxx == 2) d[++kk] = maxn - ((a[i] + b[i] + c[i]) - (maxn + minn));
		if(c[i] == maxn && mxx == 3) d[++kk] = maxn - ((a[i] + b[i] + c[i]) - (maxn + minn));
	}
	//cout << kk << "\n";
	int maxx = max(aa, max(bb, cc));
	int num = max(0, maxx - n / 2);
	//cout << num << "\n";
	sort(d + 1, d + kk + 1);
	for(int i = 1; i <= num; i++)
		sum -= d[i];
	cout << sum << "\n";
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--) solve();
	return 0;
}
