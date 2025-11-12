#include <bits/stdc++.h>
using namespace std;

long long n, m, s[110], x[110], a, b, c=1;

int main() {
	freopen("seat1.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i <= n*m;i++) {
		cin >> s[i];
		if (i == n) {
			a = s[i];
		}
	}
	sort(s+1, s+n*m+1);
	for (int i=n*m;i >= 1;i--) {
		x[i] = s[i];
	}
	for (int i=1;i <= m;i++) {
		if (x[c] == a) {
			cout << i << " " << 1;
			return 0;
		}
		c++;
	}
	for (int i=m;i >= 1;i--){
		if (x[c] == a) {
			cout << i << " " << 2;
			return 0;
		}
		c++;
	}
	for (int i=1;i <= m;i++) {
		if (x[c] == a) {
			cout << i << " " << 3;
			return 0;
		}
		c++;
	}
	for (int i=m;i >= 1;i--){
		if (x[c] == a) {
			cout << i << " " << 4;
			return 0;
		}
		c++;
	}
	return 0;
}
