#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	long long sum = 0;
	cin >> s;
	int a[15] = {0};
	for (long long i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
