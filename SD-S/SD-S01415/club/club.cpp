# include <iostream>
# include <cstring>
# include <cstdio>
# include <algorithm>
using namespace std;
const int N = 201;
int t , n , a[3][N] , d[N][N][N] , ans;
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	while(t--){
		ans = 0;
		memset(d , 0 , sizeof(d));
		cin >> n;
		for(int i = 1 ;i <= n ; i++){
			cin >> a[0][i] >> a[1][i] >> a[2][i];
		}
		for(int k = 1 ; k <= n ; k++){
			for(int i = 0 ; i <= min(k , n / 2); i++){
				if(i > k) break;
				for(int j = 0 ; j <= min(k , n / 2); j++){
					if(i + j > k) break;
					int &p = d[i][j][k - i - j];
					if(i > 0) p = max(p , d[i - 1][j][k - i - j] + a[0][k]);
					if(j > 0) p =  max(p , d[i][j - 1][k - i - j] + a[1][k]);
					if(k - i - j > 0)p = max(p , d[i][j][k - i - j - 1] + a[2][k]);
					ans = max(ans , d[i][j][n - i - j]);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
