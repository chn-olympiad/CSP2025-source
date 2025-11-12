//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 100005;
int t, n, a[N][4], aA[N], ans;
bool flagA, flagB;

void solve(int cnt1, int cnt2, int cnt3, int sum)
{
	int hn = n >> 1;
	if (cnt1 > hn || cnt2 > hn || cnt3 > hn) return;
	int i = cnt1 + cnt2 + cnt3 + 1;
	if (i > n)
	{
		ans = max(ans, sum);
		return;
	}
	solve(cnt1 + 1, cnt2, cnt3, sum + a[i][1]);
	solve(cnt1, cnt2 + 1, cnt3, sum + a[i][2]);
	if (!flagB) solve(cnt1, cnt2, cnt3 + 1, sum + a[i][3]);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		// 多测，一定一定要清空！！！
		cin >> n;
		flagA = true;
		flagB = true;
		ans = 0;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= 3; j++)
		{
			cin >> a[i][j];
			if (j != 1 && a[i][j] != 0) flagA = false;
			if (j == 3 && a[i][j] != 0) flagB = false;
		}
		if (flagA)
		{
			for (int i = 1; i <= n; i++) aA[i] = a[i][1];
			sort(aA + 1, aA + n + 1, greater<int>());
			for (int i = 1; i <= n; i++) cout << aA[i] << " "; cout << endl;
			for (int i = 1; i <= (n >> 1); i++) ans += aA[i];
			cout << ans << endl;
			return 0;
		}
		solve(0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}

