#include <bits/stdc++.h>
using namespace std;

char a[1010];

bool cmp(int x, int y) {
	return y < x;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	getline(cin, s);
	int c = s.size(), k = 0;
	for (int i = 0; i < c; i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			a[k] = s[i];
			k++;
		}
	}
	sort(a, a + k, cmp);
	for (int i = 0; i < k; i++)
		cout << a[i];
	return 0;
}