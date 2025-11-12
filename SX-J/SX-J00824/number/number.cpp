#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a >= b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char n[1000010];
	string n0 = "0";
	cin >> n;
	n0 = n;
	sort(n, n + size(n0), cmp);
	for (int i = 0; i < (int)size(n0); i++)
		if (n[i] - '0' <= 9)
			cout << n[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
