#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}


int s[] = {};

int main() {
	freopen("number", "r", stdin);
	freopen("number", "w", stdout);
	for (int i; i <= i - 1; i++) {
		cin >> s[i];
	}
	sort(s, s + 1000, cmp);
	cout << s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
