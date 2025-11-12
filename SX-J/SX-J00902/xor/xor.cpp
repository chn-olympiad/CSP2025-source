#include <bits/stdc++.h>
using namespace std;

const int N = 5e5, K = 1 << 20, KB = 20;

int a[N + 5], sum[N + 5], ans[N + 5], mx[N + 5], lst[K + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	sum[i] = sum[i - 1] ^ a[i];
	}
	memset(lst, -1, sizeof(lst));
	lst[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (lst[k ^ sum[i]] != -1)
			ans[i] = mx[lst[k ^ sum[i]]] + 1;
		mx[i] = max(mx[i - 1], ans[i]);
		lst[sum[i]] = i;
	}
	cout << mx[n] << '\n';
    return 0;
}
