#include <bits/stdc++.h>
using namespace std;
int n, s, len;
long long k, sum;
const int N = 5e5+5;
int a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == k) {
			s += 1;
		} else if (a[i] == 0)
			continue;
		else {
			sum = a[i];
			for (int j = i + 1; j < n; j++) {
				sum = int(sum ^a[j]);
				if (sum == k) {
					i = j + 1;
					s++;
					break;
				} else if (sum > k)
					break;

			}
		}
	}
	cout << s;
	return 0;
}