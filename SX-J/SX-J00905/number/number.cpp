#include <bits/stdc++.h>
using namespace std;
int n[1000010], z;
string a ;
char s;
char c = 0, x = 9;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0;; i++) {
		if (int(a[i]) >= '0' && int (a[i]) <= '9' ) {
			z++;
			n[z] = a[i] - '0';
		}
		if (int(a[i + 1]) == 0) {
			break;
		}
	}
	sort(n + 1, n + 1 + z, cmp);
	for (int i = 1; i <= z; i++) {
		cout << n[i];
	}
	return 0;
}

//cin >> s;
//		a[i] = s;
//		if (int(s) >= '0' && int (s) <= '9' ) {
//			z++;
//			n[z] = a[i] - '0';
//		}
