//SN-J00965 程越萱 西安滨河学校
#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], cnt;
string s1, s2;
int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long i = 1, j = 1;
	while (i <= n && j <= n) {
		long long t = a[i];
		for (long long kc = i+1; kc <= j; kc++) {
			t ^= a[kc];
		}
		if (t == k) {
			cnt++;
			i = j+1;
			j++;
		} else {
			j++;
		}
		if (j > n) {
			i++;
			j = i;
		}
	}
	cout << cnt;
	return 0;
}
