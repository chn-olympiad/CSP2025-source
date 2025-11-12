// XGDFZ wsq
#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace wsq {
	const int N = 1e6;
	int n, k;
	int a[N], sum[N];
	void main() {
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i], sum[i] = sum[i - 1] ^ a[i];
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++) {
				if((sum[i-1]^sum[j]) == k) {
					cnt++;
					i = j;
					break;
				}
			}
		}
		cout << cnt <<endl;
	}
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int T = 1;
	// cin >> T;
	while(T--)
		wsq::main();
	return 0;
}
