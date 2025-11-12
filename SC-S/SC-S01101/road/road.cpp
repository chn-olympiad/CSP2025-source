#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int r[1010][1010];
struct node{
	int u,v,w;
}road[1000010];
bool cmp(node a,node b){
	return a.w<b.w;
}
int f[1010];
int Find(int x){
	if(x==f[x]) return x;
	return f[x]=Find(f[x]);
}
void Kruscar(){
	int ans=0,num=0;
	sort(road+1,road+1+m,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u=road[i].u,v=road[i].v,w=road[i].w;
		if(Find(u)==Find(v)) continue;
		ans+=w;
		num++;
		f[Find(u)]=Find(v);
		if(num==n-1){
			break;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			r[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		r[u][v]=min(r[u][v],w);
		r[v][u]=min(r[v][u],w);
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		int a[10010];
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				r[j][k]=min(r[j][k],a[j]+a[k]+x); 
			}
		}
	}
	m=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			node nd;
			nd.u=i;
			nd.v=j;
			nd.w=r[i][j];
			road[++m]=nd;
		}
	}
	Kruscar();
	return 0;
}