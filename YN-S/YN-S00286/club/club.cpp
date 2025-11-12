#include <iostream>
#include <algorithm>
using namespace std;

#define N 100005
long long t, n;
long long a[N], b[N], c[N];
long long ak = 0, bk = 0, ck = 0;
long long ans = 0;

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> t;
	while (t--) {
		long long ak = 0, bk = 0, ck = 0;
		long long ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			if (a[i] > max(b[i], c[i]) && ak <= n / 2) {
				ans += a[i];
				ak++;
			} else if (b[i] > max(a[i], c[i]) && bk <= n / 2) {
				ans += b[i];
				bk++;
			} else if (c[i] > max(b[i], a[i]) && ck <= n / 2) {
				ans += c[i];
				ck++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}