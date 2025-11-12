#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3+10;
ll n;
ll a[N];
ll s[N];
ll ans;
ll p;
ll h;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 3; i <= n; i++) {
		p = i;
		h = 2 * a[i];
		while (p > 1) {
			p--;
			if (s[i] - s[p] > h) {
				ans++;
				cout << s[i] - s[p] << " " << h << endl;
				break;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
