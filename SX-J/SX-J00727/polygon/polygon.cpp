#include <bits/stdc++.h>
using namespace std;
long long n, I = 0;

long long a[100010], cho[2] = {0, 1}, s = 0, num = 0, flag[100010];
void dfs(long long Fl) {
	if (Fl == n + 1) {
		if (num <= 2) {
			return;
		}
		long long tot = 0, maxx = -1;
		for (int i = 1; i <= n; i++) {
			maxx = max(maxx, flag[i]);
			tot += flag[i];
		}
		if (tot <= 2 * maxx)
			return;
		I++;

		return;
	}
	for (int i = 0; i < 2; i++) {
		s += cho[i] * a[Fl];
		num += cho[i];
		flag[Fl] = a[Fl] * cho[i];
		dfs(Fl + 1);
		num -= cho[i];
		s -= cho[i] * a[Fl];
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	dfs(1);
	cout << I;
	return 0;
}
