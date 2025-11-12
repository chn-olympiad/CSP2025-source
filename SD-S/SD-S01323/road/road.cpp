#include<bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
using namespace std;
const int N=1e4+200,M=1e6+200;
int n,m,K,dp[(1<<10)+10],fa[N],tot,lt;
struct node{
	int xx,yy,zz;
}e[M],g[M],tr[N];
int c[15],f[15][N];
bool cmp(const node &a,const node &b) {
	return a.zz<b.zz;
}
int getf(int x) {
	return (fa[x]==x)?x:fa[x]=getf(fa[x]);
}
int lg[(1<<10)+20];
void solve(int x) {
	int cnt=0,cf=0;FOR(i,1,K)if((x>>(i-1))&1)cnt++;
	FOR(i,1,n+cnt)fa[i]=i;
	int tot1=tot;FOR(i,1,tot1)g[i]=e[i];
	FOR(i,1,K) {
		if((x>>(i-1))&1) {
			cf++;
			FOR(j,1,n) {
				g[++tot1].xx=cf+n;g[tot1].yy=j;g[tot1].zz=f[i][j];
			}
		}
	}
	sort(g+1,g+1+tot1,cmp);
	lt=n+cnt;int ans=0;
	FOR(i,1,tot1) {
		int r1=getf(g[i].xx),r2=getf(g[i].yy);
		if(r1^r2) {
			fa[r1]=r2;lt--;ans+=g[i].zz;
		}
		if(lt==1) {
			dp[x]+=ans;return ;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&K);
	FOR(i,1,n)fa[i]=i;
	lt=n;
	FOR(i,1,m) {
		int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
		e[++tot].xx=u;e[tot].yy=v;e[tot].zz=w;
	}
	FOR(i,0,K-1)lg[1<<i]=i;
	sort(e+1,e+1+tot,cmp);
	FOR(i,1,tot) {
		int r1=getf(e[i].xx),r2=getf(e[i].yy);
		if(r1^r2) {
			fa[r1]=r2;lt--;
			e[n-lt]=e[i];
		}
		if(lt==1)break;
	}
	tot=n-1;
	FOR(i,1,K) {
		scanf("%lld",&c[i]);FOR(j,1,n)scanf("%lld",&f[i][j]);
	}
	FOR(i,1,(1<<K)-1) {
		int fr=i&(-i);
		dp[i]=dp[i^fr]+c[lg[fr]+1];
	}
	int mmin=1ll<<60;
	FOR(i,0,(1<<K)-1) {
//		printf("%d ",dp[i]);
		solve(i);mmin=min(mmin,dp[i]);
	}
	printf("%lld",mmin);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

