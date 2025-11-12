#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,cnt;
struct E{
	int u,v,w;
}e[1100000];
int a[110000];
int f[200];
int fa[110000];
bool cmp(E q,E p){
	return q.w+a[q.u]<p.w+a[p.u];
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			int x; cin>>x;
			if(j==0){
				a[i+n]=x;
				continue;
			}
			e[++m].u=n+i;
			e[m].v=j;
			e[m].w=x;
		}
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y){
			fa[x]=y;
			cnt=cnt+e[i].w;
			if(e[i].u>n){
				f[e[i].u-n]++;
				if(f[e[i].u-n]==1){
					cnt=cnt+a[e[i].u];
				}
			}
		}
		int f=1;
		for(int j=1;j<n;j++){
			if(fa[j]!=fa[j+1]){
				f=0;
				break;
			}
		}
		if(f) break;
	}
	cout<<cnt;
	return 0;
}
