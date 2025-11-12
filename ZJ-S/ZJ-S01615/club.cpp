#include <bits/stdc++.h>
using namespace std;
//const int maxn=1e5+10;
const int maxn=201;
int n,p[maxn][4],ans,mx;
int dp[maxn][maxn][maxn];
//void dfs(int w,int sum,int p1,int p2,int p3){
////	cout << w << ' ' << sum << ' ' << p1 << ' ' << p2 << ' ' << p3 << '\n';
//	if(w==n+1){
//		ans=max(ans,sum);
//		return;
//	}
//	if((p1+1)<=mx) dfs(w+1,sum+p[w][1],p1+1,p2,p3);
//	if((p2+1)<=mx) dfs(w+1,sum+p[w][2],p1,p2+1,p3);
//	if((p3+1)<=mx) dfs(w+1,sum+p[w][3],p1,p2,p3+1);
//}
void getans(){
	for(int p1=0;p1<=n;p1++){
		for(int p2=0;p2<=n;p2++){
			for(int p3=0;p3<=n;p3++){
				dp[p1][p2][p3]=0;
			}
		}
	}
	for(int p1=0;p1<=mx;p1++){
		for(int p2=0;p2<=mx;p2++){
			for(int p3=0;p3<=mx;p3++){
				if((p1+p2+p3)>n) continue;
				if((p1+1)<=mx) dp[p1+1][p2][p3]=max(dp[p1+1][p2][p3],dp[p1][p2][p3]+p[p1+p2+p3][1]);
				if((p2+1)<=mx) dp[p1][p2+1][p3]=max(dp[p1][p2+1][p3],dp[p1][p2][p3]+p[p1+p2+p3][2]);
				if((p3+1)<=mx) dp[p1][p2][p3+1]=max(dp[p1][p2][p3+1],dp[p1][p2][p3]+p[p1+p2+p3][3]);
			}
		}
	}
	for(int p1=1;p1<=mx;p1++){
		for(int p2=1;p2<=mx;p2++){
			for(int p3=1;p3<=mx;p3++){
				ans=max(ans,dp[p1][p2][p3]);
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		ans=0,mx=n/2;
		for(int i=1;i<=n;i++){
			cin >> p[i][1] >> p[i][2] >> p[i][3];
		}
		
//		dfs(1,0,0,0,0);
		getans();
		cout << ans << '\n';
	}
	return 0;
}
