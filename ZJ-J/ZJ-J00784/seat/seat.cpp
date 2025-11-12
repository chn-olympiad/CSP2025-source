# include <bits/stdc++.h>
using namespace std;
int n, m, r, ind, ansl, ansh, a[103];
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
	cin >> n >> m >> r;
	a[1] = r;
	int t = n*m;
	for (int i = 2; i<=t; ++i){
		cin >> a[i];
	}
	sort(a+1, a+t+1, greater<int>());
	for (int i = 1; i<=t; ++i){
		if (a[i] == r){
			ind = i;
			break;
		}
	}
	int cnt = 0;
	for (int i = 1; i<=m; ++i){
		if (i*n >= ind){
			ansl = i;
			int x = (i-1)*n+1, y = i*n;
			for (int j = x; j<=y; ++j){
				cnt++;
				if (a[j] == r){
					if (ansl % 2 == 0){
						ansh = n - cnt + 1;
					}else{
						ansh = cnt;
					}
					break;
				}
			}
			break;
		}
	}
	cout << ansl << ' ' << ansh;
	return 0;
}
