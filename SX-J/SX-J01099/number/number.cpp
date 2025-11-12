#include <bits/stdc++.h>
using namespace std;

int h[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int a = s.size();
	if (a == 1) {
		cout << s;
		return 0;
	}
	int cnt = 0;
	for (int i = 0, j = 0; i < a, j < a; i++, j++) {
		int d = 0;
		if (s[i] >= '0' && s[i] <= '9') {
			cnt++;
			d = s[i] - '0';
			h[j] = d;
		}
	}
	if (cnt == 1) {
		for (int i = 0; i < a; i++) {
			if (s[i] >= '0' && s[i] <= '9')
				cout << s[i] - '0';
		}
	}
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			int jh = 0;
			if (h[j]  < h[j + 1] ) {
				jh = h[j] ;
				h[j] = h[j + 1];
				h[j + 1]  = jh;
			}
		}
		cout << h[i];
	}
	return 0;
}
