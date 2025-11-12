#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 502
#define MOD 998244353
using namespace std;
int n, m;
char s[MAXN];
int c[MAXN];
int arr[MAXN];
bool calc() {
	int fangqi = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum >= m) {
			return true;
		}
		if (fangqi >= c[arr[i]]) {
			fangqi++;
			continue;
		}
		if (s[i] == '1') {
			sum++;
		} else {
			fangqi++;
		}
	}
	return sum >= m;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	long long ans = 0;
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		arr[i] = i;
	}
	ans += calc();
	while (next_permutation(arr, arr + n)) {
		if (calc()) {
			ans++;
		}
	}
	cout << (ans % MOD);
	return 0;
}

