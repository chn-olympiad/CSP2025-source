#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
int a[MAXN], b[MAXN], c[MAXN];

int main() {
	freopen("clud.in", "r", stdin);
	freopen("clud.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += max(a[j], max(b[j], c[j]));

		}
		cout << sum << endl;
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}