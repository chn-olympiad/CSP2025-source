#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n = 0, j = 0;
	int nu[1000005];
	string s;
	cin >> s;
	n = s.length();
	for (int i = 1; i <= n; i++) {
		int pos = i - 1;
		if (isdigit(s[pos])) {
			j++;
			nu[j] = s[pos] - '0';
		}
	}
	sort(nu + 1, nu + j + 1);
	for (int i = j; i >= 1; i--) {
		cout << nu[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
