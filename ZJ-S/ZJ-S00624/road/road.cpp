#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
#define int long long
struct node{
	int u,w;
};
vector<node> g[N];
int f[N],z[N];
int c(int x){
	if(z[x]==x)return x;
	if(f[x]) return f[x];
	else{
		return f[x]=c(z[x]);
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		z[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			cout<<i<<' '<<g[i][j].u<<' '<<c(i)<<' '<<c(g[i][j].u)<<' '<<sum<<'\n';
			if(c(i)!=c(g[i][j].u)){
				z[c(g[i][j].u)]=c(i);
				f[g[i][j].u]=c(i);
				sum+=g[i][j].w;
			}else{
				for(int s=0;s<g[g[i][j].u].size();s++){
					if(g[g[i][j].u][1].w>g[i][j].w){
						sum-=g[g[i][j].u][1].w;
						sum+=g[i][j].w;
					}
				}
				
			}
		}
	}
	cout<<sum;
}
//4 2 2
//1 2 3
//2 3 1
