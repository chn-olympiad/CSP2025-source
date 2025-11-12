#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500001];
int qzh[500001];
int ans, lst;
set<int> t;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		qzh[i] = qzh[i - 1] ^ a[i];
	for (int i = 1; i <= n; ++i) // 以 i 为结尾
	{
		t.insert(qzh[i - 1]);
		set<int>::iterator fd = t.lower_bound(qzh[i] ^ k);
		if (*fd == (qzh[i] ^ k))
		{
			t.clear();
			lst = i;
			++ans;
		}
	}
	cout << ans << '\n';
	return 0;
}
