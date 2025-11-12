#include <bits/stdc++.h>
using namespace std;
char s[10000010];
char sz[10000010];
int qd[10000010];
int jsq = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int a = strlen(s);
	for (int i = 0; i < a; i++) {
		if (isdigit(s[i])) {
			sz[jsq] = s[i];
			jsq++;
		}
	}
	for (int i = 0; i < jsq; i++) {
		qd[i] = int(sz[i]);
	}
	int o = jsq;
	for (int i = 0; i < jsq; i++) {
		for (int j = 1; j < o; j++) {
			if (qd[j] > qd[j - 1]) {
				int fz = qd[j];
				qd[j] = qd[j - 1];
				qd[j - 1] = fz;
			}
		}
		o--;
	}
	for (int i = 0; i < jsq; i++) {
		cout << qd[i] - 48 ;
	}
	return 0;
}
