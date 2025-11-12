#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define pii pair<int,int>
#define fi first 
#define se second
#define pb emplace_back

const int N=10010,M=1000010;

int n,m,k,u,v,w,c[N],a[12][N],fa[N],ans,mn,uid,dian;

int find(int p){
	if(p==fa[p])return p;
	return fa[p]=find(fa[p]);
}

struct jcd{
	int u,v,w;
}e[M],mm[M],co[M];

vector<pii> f[N],g[N],f1[N];

bool cmp(jcd a,jcd b){
	return a.w<b.w;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	mn=1e18;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
//		f[u].pb(v,w);
//		f[v].pb(u,w);
		e[i].u=u;e[i].v=v;e[i].w=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int id=0;
	for(int i=1;i<=m;i++){
		int u=find(e[i].u),v=find(e[i].v),w=e[i].w;
		if(u!=v){
			ans+=w;id++;
			fa[v]=u;
			mm[++uid].u=e[i].u;
			mm[uid].v=e[i].v;
			mm[uid].w=w;
			co[uid]=mm[uid];
//			f[e[i].u].pb(e[i].v,w);
//			f[e[i].v].pb(e[i].u,w);
		}
		if(id==n-1)break;
	}
	mn=min(mn,ans);
	for(int s=1;s<(1<<k);s++){
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<n;i++){
			mm[i]=co[i];
		}
		uid=n-1;ans=0;dian=n;
		for(int i=1;i<=k;i++){
			int p=i-1;
			if((1<<p)&s){
				ans+=c[i];dian++;
				for(int j=1;j<=n;j++){
					mm[++uid].u=n+i;
					mm[uid].v=j;
					mm[uid].w=a[i][j];
				}
			}
		}
		if(ans>mn)continue;
		sort(mm+1,mm+1+uid,cmp);
		id=0;
		for(int i=1;i<=uid;i++){
			int u=find(mm[i].u),v=find(mm[i].v),w=mm[i].w;
			if(u!=v){
				ans+=w;id++;
				fa[v]=u;
			}
			if(id==dian-1||ans>mn)break;
		}
		mn=min(mn,ans);
//		for(int i=1;i<=n;i++)
//		memcpy(f[i],g[i],sizeof f[i]);
//		for(int i=n+1;i<=n+k;i++)
//		g[i].clear();	
	}
	cout<<mn<<"\n";
	return 0;
}
