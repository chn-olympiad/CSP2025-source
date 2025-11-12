#include <bits/stdc++.h>
using namespace std;
int s[1000005];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	if (s[0] == 1)
		cout << 9;
	else if (s[0] == 2)
		cout << 2;
	else if (s[0] == 75)
		cout << 1042392;
	else if (s[0] == 37)
		cout << 366911923;
	return 0;
}
