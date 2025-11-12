#include <bits/stdc++.h>
using namespace std;
int a[100005][4], b[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t, n;
	cin >> t;
	while (t--){
		cin >> n;
		int ans = 0, num = 0, x = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 3; j++){
				cin >> a[i][j];
				if (a[i][j] > num){
					num = a[i][j];
					x = j;
				}
			}
			b[x]++;
			ans += num;
			x = 0, num = 0;	
		}
		bool flag = true;
		for (int i = 1; i <= 3; i++){
			if (b[i] > n / 2){
				flag = false;
				x = i;
				break;
			}
			b[i] = 0;
		}
		if (flag)
			cout << ans << endl;
		else{
			for (int i = 1; i <= n; i++){
				if (a[i][x] <= a[i + 1][x] && b[x] > n / 2){
					if (a[i][(x + 1)%4] >= a[i][(x + 2) % 4])
						ans = ans - a[i][x] + a[i][(x+1) % 4];
					else
						ans = ans - a[i][x] + a[i][(x + 2)%4];
					b[x]--;
				}
			}
			cout << ans << endl;
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 3; j++){
				a[i][j] = 0;
			}
		}
		for (int i = 1; i <= 3; i++) b[i] = 0;
	}
	return 0;
}
