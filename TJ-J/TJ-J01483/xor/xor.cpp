#include <bits/stdc++.h>
using namespace std;
//)!$*#@$*#^$)
typedef long long ll;
ll xorx[500005];
int a[500005], b[500005];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		ll tmp;
		cin >> tmp;
		xorx[i] = xorx[i - 1] ^ tmp;
		bool flag = 0;
		ll ntf = xorx[i] ^ k;
		for (int j = b[i - 1]; j < i; j++) {
			if (xorx[j] == ntf) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			a[i] = a[i - 1] + 1;
			b[i] = i;
		}
		else {
			a[i] = a[i - 1];
			b[i] = b[i - 1];
		}
	}
	cout << a[n] << endl;
	return 0;
}
