//00255 ÕÅº²•N 
#include<bits/stdc++.h>
#define int long long
#define maxn 1000005
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}ro[maxn];
struct nod{
	int a,ro[10005];
}city[15];
int allro[10005];
int fa[10005];
int findfa(int a){
	if(fa[a]==a)return a;
	return fa[a]=findfa(fa[a]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)allro[i]=1145141919819;
	for(int i=1;i<=m;i++){
		cin>>ro[i].u>>ro[i].v>>ro[i].w;
	}
	int all=0;
	for(int i=1;i<=k;i++){
		cin>>city[i].a;
		all+=city[i].a;
		for(int j=1;j<=n;j++){
			cin>>city[i].ro[j];
			allro[j]=min(allro[j],city[i].ro[j]);
		}
	}
	if(k==0||all==0){
		int ans=0;
		for(int i=1;i<=n;i++)fa[i]=i;
		priority_queue<pair<int,pair<int,int> > >q;
		for(int i=1;i<=m;i++){
			q.push({-ro[i].w,{ro[i].v,ro[i].u}});
		}
		int u,v,w;
		while(q.size()){
			w=-q.top().first,u=q.top().second.first,v=q.top().second.second;
			q.pop();
//			if(w<=min(allroad[u],allroad[v]))continue;
			u=findfa(u),v=findfa(v);
			if(u==v)continue;
			ans+=w;
			fa[u]=v;
		}
//		for(int i=1;i<=n;i++){
//			q.push({-allro[i],{i,-1}});
//		}
//		while(q.size()){
//			w=-q.top().first,u=q.top().second.first;
//			q.pop();
//			if(findfa(1)!=findfa(u))
//		}
		cout<<ans;
	}
	return 0;
}

