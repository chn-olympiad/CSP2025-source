#include <iostream>
using namespace std;
const int MAXN = 5e5 + 5;
int a[MAXN], f[MAXN];
int main(void) {
	ios_base :: sync_with_stdio(false);
	cin . tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1;i <= n; ++i)
		cin >> a[i];
	for (int i = 1;i <= n; ++i) {
		f[i] = f[i - 1];
		int s = 0;
		for (int j = i;j > 0; --j) {
			s ^= a[j];
			if (s == k) {
				f[i] = max(f[i], f[j - 1] + 1);
				break;
			}
		}
	}
	cout << f[n];
	return 0;
}
