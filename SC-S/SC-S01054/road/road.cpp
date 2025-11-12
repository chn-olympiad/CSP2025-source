#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int a[N][N];
int b[N][N];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= 3;j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1;i <= k;i++) {
		for (int j = 1;j <= n + 1;j++) {
			cin >> b[i][j];
		}
	}
	return 0;
}