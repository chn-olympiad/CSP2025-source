#include<bits/stdc++.h>
using namespace std;
int a[100010][5];
int b[10], c[10];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, sum = 0, ans = 0;
	cin >> t;
	for(int x = 1;x <= t;x++){
		sum = 0;
		ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin >> a[i][j];
			}
		}
		for(int i = 1;i <= n;i++){
			ans += a[i][1];
		}
		cout << ans << "\n";
	}
	return 0;
}