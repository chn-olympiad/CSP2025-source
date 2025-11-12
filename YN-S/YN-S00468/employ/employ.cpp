//huangyi 2025.11.1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 550;
int n, m, ans;
string s;
int a[N], sum[N];
bool bk[N];

void dfs(int x, int p) {
	if (x == n + 1 && p >= m) {
		ans++;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (bk[i] == 0) {
			if (sum[x - 1] < a[i]) {
				bk[i] = 1;
				dfs(x + 1, p + 1);
				bk[i] = 0;
			}
		}
	}
}

/*
3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++) {
		sum[i + 1] = sum[i];
		if (s[i] == '0')
			sum[i + 1]++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}
