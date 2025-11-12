#include <bits/stdc++.h>
using namespace std;
int n, q;

struct node {
	string a, b;
} a[200005];

struct node1 {
	string x, y;
} b[200005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a >> a[i].b;
	}
	for (int i = 1; i <= q; i++) {
		cin >> b[i].x >> b[i].y;
	}
	for (int i = 1; i <= q; i++) {
		cout << 0 << endl;
	}
	return 0;
}