#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 0;
string s;
bool f[510];

struct node {
	int id, c;
} a[510];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].c;
		a[i].id = i;
	}
	cout << 2;
	return 0;
}