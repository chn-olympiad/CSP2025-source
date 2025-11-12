#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w;
	bool operator <(node z)const{
		return w<z.w;
	}
}f[10000001],f1[10000001];
int n,m,k,ans=INT_MAX,fa[100001],a[1001][11],c[11],p[11];
int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
void dfs(int d){
	if(d==k){
		int cnt=0,m1=m;
		for(int i=1;i<=m;i++){
			f1[i].u=f[i].u;
			f1[i].v=f[i].v;
			f1[i].w=f[i].w;
		}
		for(int i=1;i<=k;i++){
			if(p[i]==1){
				cnt+=c[i];
				for(int j=1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						m1++;
						f1[m1].u=j;
						f1[m1].v=k;
						f1[m1].w=a[i][j]+a[i][k];
					}
				}
			}
		}
		sort(f1+1,f1+m1+1);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=m1;i++){
			int x=find(f1[i].u);
			int y=find(f1[i].v);
			if(x!=y){
				fa[x]=y;
				cnt+=f1[i].w;
			}
		}
		ans=min(ans,cnt);
		return ;
	}
	d++;
	for(int i=0;i<=1;i++){
		p[d]=i;
		dfs(d);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>f[i].u>>f[i].v>>f[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	dfs(0);
	cout<<ans;
	return 0;
}
