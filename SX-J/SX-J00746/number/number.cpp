#include <bits/stdc++.h>
using namespace std;

int h[1000001];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int c = s.size(), j = 0;
	for (int i = 0; i < c; i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			h[j] = s[i] - '0';
			j++;
		}
	}
	sort(h, h + j, cmp);
	for (int i = 0; i < j; i++)
		cout << h[i];
	return 0;
}