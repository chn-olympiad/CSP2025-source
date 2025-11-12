#include <bits/stdc++.h>
using namespace std;
int a[10001];
int s[10001];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char s;
	cin >> s;
	int n;
	n = len(s);
	int y = 0;
	int oo = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] = '1' || a[i] = '2' || a[i] = '3' || a[i] = '4' || a[i] = '5' || a[i] = '6' || a[i] = '7' || a[i] = '8'
		                                       || a[i] = '9' || a[i] = 3) {
			s[i] = a[i];
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (s[j] > s[j + 1]) {
						y = s[j];
						s[j] = s[j + 1];
						s[j + 1] = y;
						oo++;
					}
				}
			}
		}
	}
	for (int i = 1; i <= oo; i++) {
		cout << s[i];
	}
	return 0;
}