#include<bits/stdc++.h>
using namespace std;
int t, n, ans, a[100005][4];;
int x1[100005], x2[100005], x3[100005], nu1, nu2, nu3;
int main(){
	std::ios::sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--){
		cin >> n;
		ans = nu1 = nu2 = nu3 = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] == max(a[i][1], max(a[i][2], a[i][3]))){
				nu1++;
				x1[nu1] = a[i][1] - max(a[i][2], a[i][3]);
			}
			else if (a[i][2] == max(a[i][1], max(a[i][2], a[i][3]))){
				nu2++;
				x2[nu2] = a[i][2] - max(a[i][1], a[i][3]);
			}
			else{
				nu3++;
				x3[nu3] = a[i][3] - max(a[i][2], a[i][1]);
			}
			ans += max(a[i][1], max(a[i][2], a[i][3]));
		}
		if (nu1 > n / 2){
			sort(x1+1, x1+nu1+1);
			int l = nu1 - n/2;
			for (int i = 1; i <= l; i++){
				ans -= x1[i];
			}
		}
		if (nu2 > n / 2){
			sort(x2+1, x2+nu2+1);
			int l = nu2 - n/2;
			for (int i = 1; i <= l; i++){
				ans -= x2[i];
			}
		}
		if (nu3 > n / 2){
			sort(x3+1, x3+nu3+1);
			int l = nu3 - n/2;
			for (int i = 1; i <= l; i++){
				ans -= x3[i];
			}
		}
		cout << ans << endl;
	}
 	return 0;
}
