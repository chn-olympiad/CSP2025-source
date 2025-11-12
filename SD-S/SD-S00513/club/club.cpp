#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct node { int w, i; };

int T, n, ans, maxn;

int p[5];

node a[N][5];

vector<int> cnt;

bool cmp(node x, node y)
{
	return x.w < y.w;
}

int solve()
{
	ans = 0;
	memset(p, 0, sizeof p);
	cnt.clear();
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 3; j++)
			cin >> a[i][j].w, a[i][j].i = j;
	for (int i = 1; i <= n; i++)
		sort(a[i] + 1, a[i] + 3 + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		ans += a[i][3].w;
		p[a[i][3].i]++;
	}
//	return 0;
	int maxn = 0;
	if (p[1] > n / 2) maxn = 1;
	if (p[2] > n / 2) maxn = 2;
	if (p[3] > n / 2) maxn = 3;
	for (int i = 1; i <= n; i++)
	{
		if (a[i][3].i == maxn) 
			cnt.push_back(max(a[i][1].w - a[i][3].w, a[i][2].w - a[i][3].w));
	}
	sort(cnt.begin(), cnt.end(), greater<int>());
	for (int i = 0; i < p[maxn] - n / 2; i++)
		ans += cnt[i];
	return ans;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	while(T--) cout << solve() << "\n";
	return 0; 
}

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13

1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
