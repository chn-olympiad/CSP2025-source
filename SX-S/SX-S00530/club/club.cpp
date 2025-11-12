#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

int T;

int n, a[N][4], num, a1, a2, a3, sum;

int f[N];

void dfs(int step) {

	if (a1 > n / 2)
		return;
	if (a2 > n / 2)
		return;
	if (a3 > n / 2)
		return;
	if (step > n) {
		if (a1 > n / 2)
			return ;
		if (a2 > n / 2)
			return ;
		if (a3 > n / 2)
			return ;
		num = max(num, sum);
		return;
	}
	if (a1 + 1 <= max(1, (step + 1) / 2)) {
		a1++;
		sum += a[step][1];
		dfs(step +  1);
		a1--;
		sum -= a[step][1];
	}
	if (a2 + 1 <= max(1, (step + 1) / 2)) {
		a2++;
		sum += a[step][2];
		dfs(step + 1);
		a2--;
		sum -= a[step][2];
	}
	if (a3 + 1 <= max(1, (step + 1) / 2)) {
		a3++;
		sum += a[step][3];
		dfs(step + 1);
		a3--;
		sum -= a[step][3];
	}
	return ;
}

void solve2() {

	int q[N], w[N];
	memset(q, 0, sizeof(q));
	memset(w, 0, sizeof(w));
	for (int i = 1; i <= n; i++)
		q[i] = a[i][1];
	sort(q + 1, q + n + 1);
	for (int i = 1; i <= n; i++) {
		w[i] = q[n - i + 1];
	}
	int ans = 0;
	for (int i = 1; i <= n / 2 ; i++)
		ans += w[i];
	cout << ans << endl;
}

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		bool k = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2] != 0 || a[i][3] != 0)
				k = 1;
		}
		if (k == 0)
			solve2();
		if (n <= 30) {
			num = a1 = a2 = a3 = sum = 0;
			dfs(1);
			cout << num << endl;
		}

	}
	return 0;
}
//Ren5Jie4Di4Ling5%
