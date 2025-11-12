#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+10;
long long a[N], sa[N];
long long n, k, ans, st=1;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sa[i] = sa[i-1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = st; j <= i; j++) {
			long long x = sa[i] ^ sa[j-1];
			if (x == k) {
				ans++, st=i+1;
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
