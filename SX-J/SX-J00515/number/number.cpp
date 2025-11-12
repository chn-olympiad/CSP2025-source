#include <bits/stdc++.h>
using namespace std;
string a;
int b[1010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "r", stdout);
	int i, j, o, p = 0, w, t;
	cin >> a;
	o = a.size();
	for (i = 0; i < o; i++)
		if (a[i] >= '0' && a[i] <= '9')
			b[++p] = a[i] - '0';
	for (i = 1; i <= p; ++i) {
		t = -1;
		for (j = 1; j <= p; ++j) {
			if (b[j] > t) {
				t = b[j];
				w = j;
			}
		}
		b[w] = -1;
		cout << t;
	}
	return 0;
}
