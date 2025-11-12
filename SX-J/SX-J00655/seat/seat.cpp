#include <bits/stdc++.h>
using namespace std;
int a[50][50], m, n;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[n][m];
		}
	}
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
        sclf(a[0][0],a[i][j]); 
		}
	}
	cout<<a[1][1];
	return 0;
}
