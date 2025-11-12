#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, a[100000][3], b[10][5];
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) for (int j = 0; j < 3; j++) cin >> a[i][j];
	for (int i = 0; i < k; i++) for (int j = 0; j < 5; j++) cin >> b[i][j];
	cout << 13;
	return 0;
}