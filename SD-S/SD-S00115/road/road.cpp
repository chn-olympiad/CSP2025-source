#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+10,M = 1e6+10;
struct node{
	int u,v,w,id;
}a[M];
int n,m,k,c[N],ww,tot,ans,fa[N];
bitset <N> f;
int find(int x){
	if(!fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>a[i].u>>a[i].v>>a[i].w;
		}
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++){
			int x=find(a[i].u);
			int y=find(a[i].v);
			if(x!=y){
				fa[x]=y;
				ans+=a[i].w;
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=m;i++){
		++tot;
		cin>>a[tot].u>>a[tot].v>>a[tot].w;
		a[tot].id=tot;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>ww;
			++tot;
			a[tot].u=i;
			a[tot].v=j;
			a[tot].w=ww+c[i];
			a[tot].id=tot;
		}
	}
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		int x=find(a[i].u);
		int y=find(a[i].v);
		if(x!=y){
			fa[x]=y;
			if(f[a[i].u]){
				a[i].w-=c[a[i].u];
			}
			else if(a[i].id>m){
				f[a[i].u]=1;
			}
			ans+=a[i].w;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
