#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
int n,m,K;
struct _{
	int fr,to,w;
}E[1000006];
struct Edge{
	int fr,to,w,id;
}e[1000006];
int pre[100004];
void init(){
	for(int i=1;i<=n+K;i++) pre[i]=i; 
}
int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}
bool cmp1(_ x,_ y){
	return x.w<y.w;
}
bool cmp2(Edge x,Edge y){
	return x.w<y.w;
}
int tot=0;
int c[15];
int vis[15];
ll Kruscal(){
	ll res=0;
	for(int i=1;i<=tot;i++){
		int x=e[i].fr,y=e[i].to,w=e[i].w,id=e[i].id;
		if(!vis[id]) continue;
		x=find(x);y=find(y);
		if(x!=y){
			res+=w;
			pre[x]=y;
		}
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>E[i].fr>>E[i].to>>E[i].w;
	}
	sort(E+1,E+m+1,cmp1);
	init();
	for(int i=1;i<=m;i++){
		x=E[i].fr;y=E[i].to;z=E[i].w;
		if(find(x)!=find(y)){
			e[++tot]={x,y,z,0};
			x=find(x);y=find(y);
			pre[x]=y;
		}
	}
	for(int i=1;i<=K;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>x;
			e[++tot]={n+i,j,x,i};
		}
	}
	sort(e+1,e+tot+1,cmp2);
	ll ans=1e18;
	for(int i=0;i<(1<<K);i++){
		init();
		ll res=0;
		memset(vis,0,sizeof vis);
		vis[0]=1;
		for(int j=0;j<K;j++){
			if(i&(1<<j)) vis[j+1]=1,res+=c[j+1];
		}
		ans=min(ans,Kruscal()+res);
	}
	cout<<ans;
	return 0;
}
