#include <bit/stdc++.h>
using namespace std;
int n, k;
long long a[5000005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k == 0) {
		int t = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				t++;
			}
		}
		cout << t;
		return 0;
	}
	return 0;
}