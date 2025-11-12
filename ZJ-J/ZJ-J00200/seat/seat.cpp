#include<bits/stdc++.h>
using namespace std;
int n, m, a[110], r_pts, r_number, cnt;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
 	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
	r_pts = a[1];
	sort(a + 1, a + n * m + 1, [&](int x, int y){
		return x > y;
	});
	for(int i = 1; i <= n * m; i++){
		if(a[i] == r_pts){
			r_number = i;
			break;
		}
	}
	for(int i = 1; i <= m; i++){
		if(i % 2 == 0){
			for(int j = n; j >= 1; j--){
				cnt++;
				if(cnt == r_number){
					cout << i << ' ' << j << '\n';
					return 0;
				}
			}
		}
		else{
			for(int j = 1; j <= n; j++){
				cnt++;
				if(cnt == r_number){
					cout << i << ' ' << j << '\n';
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
I really love CCF.Please give me full pts.
*/