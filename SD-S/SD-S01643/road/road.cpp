#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int k,m,n,a[105][maxn],c[15],fa[maxn];long long ans;
struct edge{
	int u,v;long long w;
}e[2000005];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void K(){
	sort(e+1,e+m+1,cmp);
	int tot=0;
	for(int i=1;i<=m;i++){
		int a=find(e[i].u),b=find(e[i].v);
		if(a==b) continue;
		tot++,ans+=e[i].w,fa[a]=b;
		if(tot==n-1) break;
	}
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(k)
	    for(int i=1;i<=m;i++)
	        for(int j=1;j<=k;j++) e[i].w=min(e[i].w,(long long)a[j][e[i].u]+a[j][e[i].v]+c[j]);
	K();
	cout<<ans;
}  
