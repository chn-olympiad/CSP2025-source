#include <bits/stdc++.h>
using namespace std;
int n, m, k = 1;
int a[105][105], b[105 * 105], r;
 

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> b[i];
	r = b[1];
	sort(b + 1, b + n * m + 1);
	reverse(b + 1, b + n * m + 1);
	//cout << n * m << '\n';
	//for (int i = 1; i <= n * m; i++) cout << b[i] << ' ';
	for (int i = 1; i <= m; i++){
		if (i % 2 != 0) for (int j = 1; j <= n; j++) a[j][i] = b[k], k++;
		else for (int j = n; j >= 1; j--) a[j][i] = b[k], k++;
	} 
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (a[i][j] == r){
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;
}
