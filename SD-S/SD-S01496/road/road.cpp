#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7,M=1e6+7;

struct node{
	int u,v,w;
}d[M*2],b[M*2];
int n,m,k,fa[N+15],ans=0,v[15],tot,es=0x3f3f3f3f,now=0;
bool vis[N+15],flag=0;
bool cmp(node x, node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1; i<=n+k; i++) fa[i]=i;
	for(int i=1; i<=m; i++){
		cin >> d[i].u >> d[i].v >> d[i].w;
	}
	tot=m;
	for(int i=1; i<=k; i++){
		cin >> v[i];
		if(v[i]!=0) flag=1;
		for(int j=1; j<=n; j++){
			int x;
			cin >> x;
			tot++;
			d[tot].u=n+i;
			d[tot].v=j;
			d[tot].w=x;
		}
	}
	
	if(!flag){
		sort(d+1,d+tot+1,cmp);
		for(int i=1; i<=tot; i++){
			int fx=find(d[i].u),fy=find(d[i].v);
			if(fx!=fy){
				ans+=d[i].w;
				fa[fx]=fy;
				vis[d[i].u]=1;
				vis[d[i].v]=1;
			}	
		}
		for(int i=1; i<=k; i++){
			if(vis[n+i]) ans+=v[i];
		}
		cout << ans;
		return 0; 
	}	
	
	for(int i=0; i<=k; i++){
		ans=0;
		now=m+n*i;
		for(int j=1; j<=n+k; j++){
			fa[j]=j;
			vis[j]=0;
		}
		for(int j=1; j<=now; j++) b[j]=d[j];
		sort(b+1,b+now+1,cmp);
		for(int j=1; j<=now; j++){
			int fx=find(b[j].u),fy=find(b[j].v);
			if(fx!=fy){
				ans+=b[j].w;
				fa[fx]=fy;
				vis[b[j].u]=1;
				vis[b[j].v]=1;
			}	
		}
		for(int j=1; j<=i; j++){
			if(vis[n+j]) ans+=v[j];
		} 
		es=min(es,ans);
	}
	cout << es;
	return 0;
}

