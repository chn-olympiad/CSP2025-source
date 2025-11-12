#include <bits/stdc++.h>
using namespace std;
inline long long read() { long long x = 0 , f = 1; char c = getchar(); while(c < '0' || '9' < c) {	if(c == '-') f = -1; c = getchar(); } while('0' <= c && c <= '9') { x = x*10 + c-'0'; c = getchar(); } return x * f; }
const int N=1e5+5;
struct human{
	int a,b,c;
}a[N];
int n,T,half;
bool SPA;
long long dp[35][35][35][35],ans; 
inline bool abgc(const human &a,const human &b) { return a.a > b.a ; }
signed main() {
	 freopen("club.in" , "r" , stdin);
	 freopen("club.out" , "w" , stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),half=n>>1,ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].b||a[i].c)
				SPA=0;
		}
		if(n<=30){
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++)
				for(int j=0;j<=half;j++)
					for(int k=0;k<=half;k++)
						for(int l=0;l<=half;l++){
							//->1
							if(j)
								dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j-1][k][l]+a[i].a);
							//->2
							if(k)
								dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k-1][l]+a[i].b);
							//->3
							if(l)
								dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l-1]+a[i].c);
						}
			for(int j=0;j<=half;j++)
				for(int k=0;k<=half;k++)
					for(int l=0;l<=half;l++)
						ans=max(ans,dp[n][j][k][l]);
			cout<<ans<<'\n';
		}
		else if(SPA){
			sort(a+1,a+1+n,abgc);
			for(int i=1;i<=half;i++)
				ans+=a[i].a;
			cout<<ans<<'\n';
		}
		else{
			for(int i=1;i<=n;i++)
				ans+=max({a[i].a,a[i].b,a[i].c});
			cout<<ans<<'\n';
		}
	}
	return 0;
}
