#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long t, n;
int a[N];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdin);
	scanf("%lld", &t);
	while (t > 0) {
		t--;
		cin >> n;
		long long cnt;
		for (int i = 1; i <= n; i++) {
			int b, c;
			cin >> a[i] >> b >> c;
		}
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= n / 2; i++) {
			cnt += a[i];
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
