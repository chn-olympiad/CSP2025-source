#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool b[100005];
char s[100005];
long long n, f = 0, maxn = 0, k;

int paixu() {
	for (int j = 0; j < f; j++) {
		if (a[j] >= maxn && b[j] != 1) {
			maxn = a[j];
			k = j;
		}
	}
	return maxn;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[f] = s[i] - '0';
			f++;
		}
	}
	for (int i = 0; i < f  ; i++) {
		paixu();
		cout << a[k];
		b[k] = 1;
		maxn = 0;
	}
	return 0;
}
