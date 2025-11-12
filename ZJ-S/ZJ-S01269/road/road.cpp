#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct node{
	int u,v,w;
};
int k[N];
int fa[N];
node mp[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int ans,A;
int find(int x){
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){	
		cin>>mp[i].u>>mp[i].v>>mp[i].w;
	}
	for(int i=1;i<=k;i++){
		A=1;
		int f;
		cin>>f;
		if(f)	A=0;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			if(k)	A=0;	
		}
		if(A){
			cout<<0;
			return 0;
		}
	}

	sort(mp+1,mp+m+1,cmp);
	for(int i=1;i<=m;i++){
		int xx=find(mp[i].u);
		int yy=find(mp[i].v);
		if(xx!=yy){
			fa[mp[i].u]=fa[mp[i].v];
			ans+=mp[i].w;
		}
		
	}
	cout<<ans;
	return 0;
}                                              
