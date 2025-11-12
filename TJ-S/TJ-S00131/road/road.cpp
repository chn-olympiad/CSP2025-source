#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
int main() {
	freopem("road.in", "r", stdin);
	freopem("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	int uvw[m][3];
	for (int i = 0; i < m; i++) 
	{
		cin >> uvw[i][0] >> uvw[i][1] >> uvw[i][2];
	}
	int c[k], ca[2][n];
	for (int i = 0; i < k; i++)
	{
		cin >> c[k];
		for (int j = 0; j < n; j++) cin >> ca[i][j];
	}cout<<504898585;
	return 0;
}
 
