#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in ", 'r', stdin);
	freopen("employ.out", 'w', stdout);

	int n, m;
	cin >> n >> m;

	if (n >= m) {
		cout << m;
	}

	if (n < m) {
		cout << n;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
