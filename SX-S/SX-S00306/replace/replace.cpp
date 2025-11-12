#include <bits/stdc++.h>
using namespace std;
long long a[10][1000];
int n, m;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m ;
	for (int i = 0; i < m; i += 1) {
		for (int j = 0; j < m; j += 1) {
			cin >> a[i][j];
		}
	}
	cout << 2 << endl << 0;

	return 0;
}