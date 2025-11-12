#include <bits/stdc++.h>
using namespace std;
int a[100][4];
int s, n;

void dfs(int v, int h, int s1, int s2, int s3) {
	if (v == n) {
		s = max(s, h);
		return;
	}
	if (s1 + 1 <= n / 2)
		dfs(v + 1, h + a[v][0], s1 + 1, s2, s3);
	if (s2 + 1 <= n / 2)
		dfs(v + 1, h + a[v][1], s1, s2 + 1, s3);
	if (s3 + 1 <= n / 2)
		dfs(v + 1, h + a[v][2], s1, s2, s3 + 1);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		s = 0;
		for (int j = 0; j < n; j++) {
			for (int x = 0; x < 3; x++)
				cin >> a[j][x];
		}
		if(n <= 30){
			dfs(0, 0, 0, 0, 0);
			cout << s << "\n";
		}
	}
}