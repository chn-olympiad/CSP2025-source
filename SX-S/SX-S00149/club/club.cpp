#include <bits/stdc++.h>
using namespace std;
int n, x;
const int N = 1e5+10;
int a[N], b[N], c[N], le[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n;
	while (n--) {
		int suma = 0, sumb = 0, sumc = 0;
		cin >> x;
		for (int i = 1; i <= x; i++) {
			cin >> a[i] >> b[i] >> c[i];
			suma += a[i], sumb += b[i], sumc += c[i];
			int k = max(sum[i - 1][0], max(sum[i - 1][1], sum[i - 1][2]));
			sum[i][0] = k + a[i], sum[i][1] = k + b[i], sum[i][2] = k + c[i];
		}
		int ans = 0;
		if (suma > sumb && suma > sumc) {
			ans = suma;
			for (int i = 1; i <= x; i++) {
				le[i] = max(b[i] - a[i], c[i] - a[i]);
			}
			sort(le + 1, le + 1 + x);
			for (int i = x; i > x / 2; i--) {
				ans += le[i];
			}
		} else if (suma > sumb && sumc > suma) {
			ans = sumc;
			for (int i = 1; i <= x; i++) {
				le[i] = max(b[i] - c[i], a[i] - c[i]);
			}
			sort(le + 1, le + 1 + x);
			for (int i = x; i > x / 2; i--) {
				ans += le[i];
			}
		} else {
			ans = sumb;
			for (int i = 1; i <= x; i++) {
				le[i] = max(a[i] - b[i], c[i] - b[i]);
			}
			sort(le + 1, le + 1 + x);
			for (int i = x; i > x / 2; i--) {
				ans += le[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

