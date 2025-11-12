#include <iostream>
using namespace std;
int n,m;
int b[10005][10005];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >>b;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			b++;
			a[sum] = s[i] - 48;
		}
	}
	for (int i = 1; i <= sum; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[j] < a[i]) {
				n = a[i];
				a[i] = a[j];
				a[j] = n;
			}
		}
	}
	for (int i = 1; i <= sum; i++) {
		cout << a[i];
	}
	return 0;
	}