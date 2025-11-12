#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=1e5+5;
struct P{
	ll x,y,z;
}p[N];
bool cmpx(P a,P b){
	return a.x>b.x;
}
bool cmpy(P a,P b){
	if(a.x==b.x&&a.y==b.y)return a.z>b.z;
	if(a.x==b.x)return a.y>b.y;
	return a.x>b.x;
}
int n,m;
ll dp[N>>1][N>>1][N>>1],f[M>>1];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;scanf("%d",&_);
	while(_--){
		scanf("%d",&n);m=n>>1;
		if(n<=500){
			ll ans=0;
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;++i)
				scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].z);
			for(int i=1;i<=n;++i){
				for(int a=min(i,m);a>=0;--a)
					for(int b=min(i-a,m);b>=0;--b){
						int c=i-a-b;
						if(c>m)break;
						if(a<m)dp[a+1][b][c-1]=max(dp[a+1][b][c-1],dp[a][b][c-1]+p[i].x);
						if(b<m)dp[a][b+1][c-1]=max(dp[a][b+1][c-1],dp[a][b][c-1]+p[i].y);
						dp[a][b][c]=dp[a][b][c-1]+p[i].z;
					}
			}
			for(int a=m;a>=0;--a)
				for(int b=m;b>=0;--b)
					for(int c=m;c>=0;--c)
						ans=max(ans,dp[a][b][c]);
			printf("%lld\n",ans);
		}
		else{
			bool op=1;
			ll ans=0;
			for(int i=1;i<=n;++i){
				scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].z);
				if(p[i].y!=0)op=0;
				if(op){
					sort(p+1,p+n+1,cmpx);
					for(int i=1;i<=m;++i)ans+=p[i].x;
					printf("%lld",ans);
				}
				else{
					sort(p+1,p+n+1,cmpy);
					for(int i=1;i<=m;++i)ans+=p[i].x;
					for(int i=1;i<=m;++i)ans+=p[i+m].y;
					printf("%lld",ans);
				}
			}
		}
	}
	return 0;
}
