#include<bits/stdc++.h>
using namespace std;
const int MAXN=10500;
int n,m,k;
int f[MAXN];
struct node{
	long long u,v,w;
	long long c;
};
bool vis[MAXN];
long long c[20];
long long w[MAXN];
long long ans;
vector<node> e;
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int u){
	if(f[u]==u)
		return u;
	return f[u]=find(f[u]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w,0});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>w[j];
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				e.push_back({u,v,w[u]+w[v]+c[i],i});
			}
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=0;i<e.size();i++){
		if(f[find(e[i].u)]!=find(e[i].v)){
			f[find(e[i].u)]=find(e[i].v);
			ans+=e[i].w;
			if(vis[e[i].c]!=0){
				ans-=c[e[i].c];
			}
			vis[e[i].c]=1;
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
