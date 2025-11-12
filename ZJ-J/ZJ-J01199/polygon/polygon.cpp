#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXN 5001
#define MOD 998244353
using namespace std;
int n;
int arr[MAXN];
int f(int index, int last, int num, int sum) {
	if (index >= n) {
		if (num >= 3 && sum > 2 * arr[last]) {
			return 1;
		} else {
			return 0;
		}
	}
	int ans = 0;
	ans += f(index + 1, last, num, sum);
	ans += f(index + 1, index, num + 1, sum + arr[index]);
	return ans;
}
int power2(int n) {
	long long ans = 1, a = 2;
	while (n > 0) {
		if (n & 1) {
			ans = (ans * a) % MOD;
		}
		a = (a * a) % MOD;
		n >>= 1;
	}
	return ans;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int maxx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxx = max(maxx, arr[i]);
	}
	if (maxx == 1) {
		cout << ((power2(n) - 1 - n - (n * (n - 1) / 2) % MOD) % MOD + MOD) % MOD;
		return 0;
	}
	sort(arr, arr + n);
	if (n == 3) {
		if (arr[0] + arr[1] > arr[2]) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	cout << f(0, -1, 0, 0);
	return 0;
}

