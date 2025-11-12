#include <bits/stdc++.h>
using namespace std;
int n, k, ans, xx = 0, cnt = 0;
int s[500000];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++) {
		ans = s[i];
		for (int j = 0; j <= xx; j++) {
			if (ans == k) {
				cnt++;
				xx = i;
				break;
			}
			ans = ans ^s[j];
		}
	}
	cout << cnt;
	return 0;
}
