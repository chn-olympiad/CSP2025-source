#include<bits/std.c++.h>
using namespace std;
int a[N], b[M], c[Q];

int main() {
	freopen("number.in", r, "stdin")
	freopen("number.out", w, "stdout")
	char s;
	cin >> s;
	int n;
	cin >> n;
	for (int i = 1; i <= s; i++) {
		cin >> a[i];
	}
	for (j = 1; j <= s; j++) {
		cin >> b[j];
	}
	cin >> c[Q];
	for (int i = 0; i <= a[N]; i++) {
		for (int j = 0; j <= b[M]; j++) {
			if (b[j] % 1 == 0) {
				c[Q] = c[Q] + a[i];
			} else {
				a[N] = a[N] - a[i];
			}
		}
		int mh = max(c[Q], c[Q + 1]);
		cout << mh;
		return 0;
	}
}
