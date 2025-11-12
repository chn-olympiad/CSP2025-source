#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[500005], cnt;
bool book[500005];

int main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (long long i = 1; i <= n; i++) {
		long long j = i;
		long long t = a[i];
		while (book[j] == 0 && j > 0 && t != k) {
			j--;
			if (book[j] == 1 || j <= 0) {
				break;
			}
			t = t ^a[j];
		}
		if (t == k) {
			book[i] = 1;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
