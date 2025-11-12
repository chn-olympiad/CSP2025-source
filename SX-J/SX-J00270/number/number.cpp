#include <bits/stdc++.h>
using namespace std;
int ji = 0;
string s;
int a[1000000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int x = s[i] - '0';
			ji++;
			a[ji] = x;
		}
	}
	sort(a + 1, a + ji + 1);
	for (int i = ji; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
