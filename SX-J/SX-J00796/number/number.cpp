#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int sum = 0;
	int w = s.size();
	int q;
	for (int i = 0; i < w; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			sum++;
			q = s[i] - '0';
			a[sum] = q;
		}
	}
	sort(a, a + sum + 1);
	for (int i = sum; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
