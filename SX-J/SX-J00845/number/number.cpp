#include <bits/stdc++.h>
using namespace std;
string s;
long long k, a[1000010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	long long l = s.size();
	for (long long i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			k++;
			a[k] = s[i] - '0';
		}
	}
	for (long long i = 1; i <= k; i++) {
		for (long long j = i + 1; j <= k; j++) {
			if (a[i] < a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
	for (long long i = 1; i <= k; i++) {
		cout << a[i];
	}
	return 0;
}