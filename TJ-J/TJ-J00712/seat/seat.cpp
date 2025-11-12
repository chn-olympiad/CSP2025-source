#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, w = 1;
	int a[105][105]; 
	int map[105][105];
	int ans[105][105];
	cin >> n >> m;
	int t = m * n;
	for(int i = 1; i <= t; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			if(a[i][j] > map[i][j]){
				w = a[i][j]; 
				if(w == 100){
					ans[i][j] = map[i][j];
				}
			}
		}
	}
	for(int i =1; i <= n; i++){
		for(int j = i; j <= m; j++){
			cout << ans[i][j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
