#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=10000+10;
const int maxm=1000000+10;
const int maxk=10+10;
const int inf=1e16;
int n,m,k,U,ans=inf,cnt=0,top=0,b[maxk][maxn],c[maxk],fa[maxn+maxk];
bool vis[maxn+maxk];
struct node{
	int u,v,w;
}a[maxm+maxn*maxk];
bool cmp(node u1,node u2){
	return u1.w<u2.w;
}
int find(int u){
	if(u==fa[u]) return u;
	return fa[u]=find(fa[u]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int u,v,w;
	cin>>n>>m>>k; U=(1<<k)-1;
	for(int i=1;i<=n;i++) vis[i]=true;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		a[++top]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(!c[i]) cnt++;
		for(int j=1;j<=n;j++){
			scanf("%lld",&b[i][j]);
			a[++top]={j,n+i,b[i][j]};
		}
	}
	sort(a+1,a+top+1,cmp);
	for(int i=0;i<=U;i++){
		if(cnt==k) i=U;
		int pans=0,pcnt1=n,pcnt2=0;
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<=k;j++){
			vis[n+j]=false;
			if(!(i&(1<<(j-1)))) continue;
			pans+=c[j]; pcnt1++; vis[n+j]=true;
		}
		if(pans>=ans) continue;
		for(int j=1;j<=top;j++){
			u=a[j].u; v=a[j].v; w=a[j].w;
			if(!vis[u] || !vis[v]) continue;
			int fu=find(u);
			int fv=find(v);
			if(fu!=fv){
				pans+=w; pcnt2++; fa[fu]=fv;
				if(pans>=ans) break;
				if(pcnt2==pcnt1-1) break;
			}
		}
		if(pcnt2==pcnt1-1) ans=min(ans,pans);
		if(cnt==k) break;
	}
	printf("%lld\n",ans);
	return 0;
}