#include <bits/stdc++.h>
using namespace std;
int a[1000010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int p = 0;
	for (int i = 0; i <= s.size() - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int k = s[i] - '0';
			a[p] = k;
			p++;
		}
	}
	sort(a, a + p);
	for (int i = 0; i < p; i++) {
		cout << a[p - i - 1];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
