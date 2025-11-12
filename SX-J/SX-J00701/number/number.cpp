#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int a[1000001] = {}, j = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i <= s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[j++] = s[i] - '0';
	}
	sort(a, a + j, cmp);
	for (int i = 0; i < j; i++) {
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
