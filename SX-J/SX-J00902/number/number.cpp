#include <bits/stdc++.h>
using namespace std;

const int S = 1e6, SI = 10;

char s[S + 5];

int times[SI + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s + 1;
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		if (s[i] >= '0' && s[i] <= '9')
			times[s[i] - '0']++;
	for (int i = SI - 1; i >= 0; i--)
		while (times[i]--)
			cout << i;
	cout << '\n';
	return 0;
}
