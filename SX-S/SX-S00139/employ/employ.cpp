#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans = 1;
int a[505];
int srt[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	int an = n;
	int cnt = 0;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			an--;
		}
		srt[a[i]]++;
	}
	if (an < m) {
		cout << 0;
		return 0;
	}
	for (int i = m; i >= 0; i--) {
		cnt++;
		ans = ans * an % 998244353;
		if (srt[cnt] != 0) {
			an -= srt[cnt];
		} else {
			an--;
		}
	}
	cout << ans;
	return 0;
}
