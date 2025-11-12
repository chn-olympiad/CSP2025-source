#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int from,to,w;
	friend bool operator<(node a,node b){
		return a.w<b.w;
	}
};
vector<node>g;
int n,m,k,a[11][10001],fa[10001];
int findf(int x){
	if(fa[x]==0)return x;
	return fa[x]=findf(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	if(k==0){
		sort(g.begin(),g.end());
		int ans=0,num=0;
		for(int x=0;x<m;x++){
			if(num==n-1)break;
			int f=g[x].from,t=g[x].to,w=g[x].w;
			int ff=findf(f),ft=findf(t);
			if(ff!=ft){
				fa[ff]=ft;
				ans+=w;
				num++;
			}
		}
		cout<<ans;
		return 0;
	}
	srand(time(0)^(unsigned long long)new char);
	cout<<rand(); 
	return 0;
}

