#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char s[N];
int q[N];
long long t, w = 0;
long long e;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> (s + 1);
	t = strlen(s + 1);
	for (int i = 1; i <= t; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			continue;
		} else {
			w++;
			q[w] = s[i] - '0';
		}
	}
	sort(q + 1, q + 1 + w);
	for (int i = w; i >= 1; i--) {
		e = e * 10 + q[i] ;
		cout << q[i];
	}
	return 0;
}
