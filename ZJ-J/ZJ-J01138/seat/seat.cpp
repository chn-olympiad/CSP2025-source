#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], R, cnt;

bool cmp(int x, int y){
	return x > y;
}

signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	R = a[1];
	for(int i = 2; i <= n * m; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1; i <= m; i ++){
		for(int j = 1; j <= n; j ++){
			cnt ++;
			if(a[cnt] == R){
				cout << i << " " << j;
				return 0;
			}
		}
		i ++;
		for(int j = n; j >= 1; j --){
			cnt ++;
			if(a[cnt] == R){
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
