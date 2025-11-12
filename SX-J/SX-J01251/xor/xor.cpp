#include <bits/stdc++.h>
using namespace std;
int a[500010];
int s[500010];
bool flag = false;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, sum = 0, biaoji;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = a[i] ^ s[i - 1];
		if (s[i] == k && !flag) {
			sum++;
			biaoji = i;
			flag = true;
		}
	}
	while (biaoji < n) {
		for (int i = biaoji + 1; i <= n; i++) {
			if ((s[i]^s[biaoji] ) == k ) {
				sum++;
				biaoji = i;
				break;
			}
		}
	}
	cout << sum << endl;
}
