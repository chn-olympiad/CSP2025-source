#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,M=2e6+10;
int n,m,k,c[N],f[N],siz[N],ans=1e18,cnt; 
struct edge{int u,v,w;}e[M],te[M];
inline bool cmp(edge x,edge y){return x.w<y.w;}
int find(int x){return (x==f[x])?x:(f[x]=find(f[x]));}
inline bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return 0;
	if(siz[x]>siz[y])swap(x,y);
	return f[x]=y,siz[y]+=siz[x],1;
}
signed main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>te[i].u>>te[i].v>>te[i].w;
	sort(te+1,te+1+m,cmp);
	for(int i=1;i<=n;i++)f[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++)if(merge(te[i].u,te[i].v))e[++cnt]=te[i];
	m=cnt;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)e[++m].u=j,e[m].v=i+n,cin>>e[m].w;
	}
	sort(e+1,e+1+m,cmp);
	for(int S=0;S<(1<<k);S++){
		int res=0;
		for(int i=1;i<=k;i++)if((S>>(i-1))&1)res+=c[i];
		for(int i=1;i<=n+k;i++)f[i]=i,siz[i]=1;
		for(int i=1;i<=m;i++){
			if((e[i].v>n)&&!((S>>(e[i].v-n-1))&1))continue;
			if(merge(e[i].u,e[i].v))res+=e[i].w;
		}
		ans=min(ans,res);
	}
	return cout<<ans,0;
}
