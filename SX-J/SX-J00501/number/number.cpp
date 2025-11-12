#include <bits/stdc++.h>
using namespace std;
string a, b;
int cnt = 1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' and a[i] <= '9') {
			b[cnt] = a[i];
			cnt++;
		}
	}
	for (int i = 1; i < cnt; i++) {
		char maxa = '0';
		int maxx;
		for (int j = 1; j <= cnt; j++) {
			if (b[j] > maxa) {
				maxa = b[j];
				maxx = j;
			}
		}
		cout << maxa;
		b[maxx] = '0';
	}
	return 0;
}
