#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int n,m,k;
int fa[N],c[11],a[11][10001];
map<int,int>ed;
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return find(fa[x]);
}
void merge(int x,int y){
	int nx=find(x);
	int ny=find(y);
	fa[ny]=nx;
}
struct edge{
	int u,v,w;
}e[10000001];
int cnt;
int tot=0;
void kruscal(){
	for(int i=1;i<=cnt;i++){
		int nu=find(e[i].u),nv=find(e[i].v);
		if(nu!=nv){
			tot+=e[i].w;
			merge(nu,nv);
		}
	}
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		e[++cnt].u=u;
		e[cnt].v=v;
		e[cnt].w=w;
	}
	for(int d=1;d<=k;d++){
		cin >> c[d];
		for(int j=1;j<=n;j++){
			cin >> a[d][j];
		}
		if(c[d]==0){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					e[++cnt].u=i;
					e[cnt].v=j;
					e[cnt].w=a[d][i]+a[d][j];
//					ed[cnt]=d;
				}
			}
		}
	}
	sort(e+1,e+cnt+1,cmp);
	kruscal();
	if(k==0) cout << tot;
	else cout << tot;
	return 0;
}