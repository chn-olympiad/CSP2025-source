#include<bits/stdc++.h>
using namespace std;
struct node{int u,v,w;};
node e[1000010];
int fa[10010],dpth[10010];
bool cmp(node u,node v){return u.w<v.w;}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void craft(int u,int v){
	int ffu=find(u),ffv=find(v);
	if(dpth[ffu]<dpth[ffv])fa[ffu]=ffv;
	else if(dpth[ffv]<dpth[ffu])fa[ffv]=ffu;
	else fa[ffu]=ffv,dpth[ffv]++;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i,dpth[i]=1;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v))continue;
		ans+=w;
		craft(u,v);
	}
	cout<<ans;
	return 0;
}
