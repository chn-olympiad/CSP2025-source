#include<bits/stdc++.h>
#define Maxn 10010
#define ll long long
using namespace std;
long long ans;
ll ci[Maxn],ck[Maxn][Maxn],dpk[Maxn];//״̬
ll fa[Maxn],c[20][Maxn],cw[20],w[Maxn][Maxn],fis[Maxn],dp[Maxn];
ll n,m,k;
void dpt(int x){
	for(int j=1;j<=n;j++){
		if(x!=j)for(int l=1;l<=k;l++){
			ll p;
			if(ci[l])p=c[l][x]+c[l][j];
			else p=cw[l]+c[l][x]+c[l][j];
			if(w[x][j]>=p){
				w[x][j]=p;
				ck[x][j]=k;
			}
		}
	}
}
int main(){
	freopen("roadin.txt","r",stdin);
	freopen("roadout.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)w[i][j]=1e9;
	}
	for(int i=0;i<m;i++){
		ll p,x,y,z;
		scanf("%lld %lld %lld",&x,&y,&z);
		w[x][y]=z,w[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&cw[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&c[i][j]);
		}
	}
	dpt(1);
	for(int i=1;i<=n;i++)dp[i]=w[1][i];
	for(int i=1;i<n;i++){
		int next,ww=1e9;
		for(int j=1;j<=n;j++){
			if(ww>dp[j]&&fa[j]!=1){
				ww=dp[j];
				next=j;
			}
		}
		ci[ck[dpk[next]][next]]++;
		ans+=ww;
		fa[next]=1;
		dpt(next);
		for(int j=1;j<=n;j++)
		for(int j=1;j<=n;j++){
			dp[j]=min(dp[j],w[next][j]);
			if(dp[j]>w[next][j])dpk[j]=next;
		}
	}
	printf("%lld",ans+1);
	return 0;
}
