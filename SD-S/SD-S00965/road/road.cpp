#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+7;
int n,m,k,a[N],f[N];
struct edge{
	int u,v,w;
	bool operator <(const edge e)const{
		return w<e.w;
	}
}e[N];
map<pair<int,int>,int> mp;
int find(int x){
	if(f[x]==x){return x;}
	else{f[x]=find(f[x]);return f[x];}
}
int kruskal(){
	int res=0;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)==find(e[i].v))continue;
		else {
			res+=e[i].w;
			f[find(e[i].u)]=find(e[i].v);
		}
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(mp[{u,v}]&&mp[{u,v}]<e[i].w)continue;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
		mp[{u,v}]=w;
	}
	for(int i=1;i<=k;i++){
		int q;
		cin>>q;
		for(int j=1;j<=n;j++)cin>>a[j];
		for(int j=1;j<=n;j++)
			for(int l=1;l<=n;l++){
				if(mp[{j,l}]&&mp[{j,l}]<a[j]+a[l])continue;
				if(!mp[{j,l}])m++;
				e[i].u=j;
				e[i].v=l;
				e[i].w=a[j]+a[l];
				mp[{e[i].u,e[i].v}]=e[i].w;
			}
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)f[i]=i;
	cout<<kruskal()<<endl;
	return 0;
}
//kruskal 这个我不一等ccf扫钱家 
