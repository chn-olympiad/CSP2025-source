#include<iostream>
#include<cstring>
using namespace std;
const int N =1001,M=4;
int n;
long long a[N][M];
long long ans = 0;
long long satisfaction = 0;
int club_sze[M];
int membmax[N];
void dfs(int memb) {
	//cout << memb << endl;
	if(memb>n) {
		ans = max(satisfaction,ans);
		return;
	}
	for(int i=1; i<=3; i++) {
		if(club_sze[i]>=n/2) {
			continue;
		}
		club_sze[i]++;
		satisfaction+=a[memb][i];
		//cout << satisfaction << ' ' << i << endl;
		dfs(memb+1);
		club_sze[i]--;
		satisfaction-=a[memb][i];
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) {
		satisfaction=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		dfs(1);
		printf("%lld\n",ans);
//		for(int i=1; i<=n; i++) { // 物品
//			for(int j=1; j<=3; j++) { //三个背包
//				for(int k=1; k<=n/2; k++) { //还有多少体积
//					for(int l=1; l<=3; l++) { //从哪个背包继续推
//						if(l!=j) {
//							for(int mm=1; mm<=k; mm++) { //上一个体积 和我这个背包无关吗？ 自己折腾去
//								dp[i][j][k] = max(dp[i][j][k],dp[i-1][l][mm]+a[i][j]);
//							}
//						} else {
//							dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]+a[i][j]);  //有关
//							
//							//if(j==2) cout << i << ' ' << k << ' ' << dp[i][j][k] << endl;
//						}
//
//					}
//					
//
//				}
//			}
//		}
//		printf("%lld\n",max(dp[n][3][n/2],max(dp[n][1][n/2],dp[n][2][n/2])));
	}
	return 0;
}

