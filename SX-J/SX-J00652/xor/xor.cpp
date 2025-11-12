#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005];

struct node {
	int t[25];
} tr[500005], s[500005];
int ans = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k)
			ans++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}