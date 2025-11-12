#include<bits/stdc++.h>
using namespace std;
int t,I,J,ans,cnt,flag,maxx = -1,minn = 99999;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		int n,b[4] = {0},d[4] = {0},c[20005][4] = {0},a[20005][4] = {0};
		ans = 0;
		cin >> n;
		int m = n / 2;
		for(int i = 1;i <= n;i++){
			maxx = -1; minn = 99999; J = 0; I = 0; flag = 0;
			for(int j = 1;j <= 3;j++){
				cin >> a[i][j];
				if(maxx < a[i][j]){
					maxx = a[i][j];
					J = j;
				}
			}
			c[i][J] = maxx; d[i] = 1;
			if(b[J] < m){
				b[J]++;
			} 
			else{
				int maxx_1 = -1,J_ = 0;
				for(int j = 1;j <= i;j++){
					if(minn > c[j][J]){
						minn = c[j][J];
						I = j;
					}
				}
				d[I] = 0;
				ans -= minn;
				if(d[i] == 0){
					for(int j = 1;j <= 3;j++){
						if(a[i - 1][j] == c[i - 1][J]) a[i - 1][j] = -2;
						if(maxx_1 < a[i - 1][j]){
							maxx_1 = a[i - 1][j];
						}
					}
					if(maxx_1 + maxx > c[i - 1][J]){
						ans = ans + maxx_1 + maxx - c[i - 1][J];
						d[i] = 1;
					}
				}
			}
			
			ans += maxx;
		}
		cout << ans << "\n";
	}
	return 0;
} 
