#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,fa[100005],c[200005],ed[15][100005],cnt,ansa=INT_MAX;
bool used[15];
struct edge{
	int u,v,w,used_to;
}e[2000005];
int fin(int x){
	if(fa[x]==0)return x;
	return fa[x]=fin(fa[x]);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void kruskal(){
	sort(e+1,e+cnt+1,cmp);
	int ans=0,sum=0;
	for(int i=1;i<=cnt;i++){
		int x=fin(e[i].u),y=fin(e[i].v);
		if(x==y)continue;
		sum++;
		ans+=e[i].w;
		fa[y]=x;
		if(sum==n-1){
			ansa=min(ansa,ans);
			return ;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		if(e[i].u>e[i].v)swap(e[i].v,e[i].u);
	}
	cnt=m;
	kruskal();
	cout<<ansa;
}