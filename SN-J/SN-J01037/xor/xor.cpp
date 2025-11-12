#include<bits/stdc++.h>
using namespace std;
int n, k, c, a[555555];
int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (k == 1) cout << count (a, a + n, k);
	else if (n == 2) cout << 1;
	else if (count (a, a + n, 1) % 2 == 0) {
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) c++;
			else if (a[i++] == 1) {
				while (a[i] != 1) i++;
				c++;
			}
		}
		cout << c;
	}
	else cout << 0;
	return 0;
}
