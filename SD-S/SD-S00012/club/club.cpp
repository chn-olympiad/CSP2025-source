#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5+5;
const int INF = 0x7fffffff;

int T,n,val[N][4],ans,dp[300][300][300];


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		ans = 0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> val[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int a=0;a<=min(i,n/2);a++){
				for(int b=0;b<=min(i,n/2);b++){
					if(a+b>i) continue;
					int c = i-a-b;
					if(c>n/2) continue;
					dp[i][a][b] = max(
						(a?dp[i-1][a-1][b]+val[i][1]:-INF),
						max(
						(b?dp[i-1][a][b-1]+val[i][2]:-INF),
						(c?dp[i-1][a][b]+val[i][3]:-INF)
						)
					);
					ans = max(ans,dp[i][a][b]);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
1
2
10 9 8
4 0 0
*/
