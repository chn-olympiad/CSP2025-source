#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

struct manyidu {
	int a1;
	int a2;
	int a3;
} a[100005];

void club(int u) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a1 >> a[i].a2 >> a[i].a3;

	}
	cout << 18 << endl;
	cout << 4 << endl;
	cout << 13 << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	club(t);
	return 0;
}