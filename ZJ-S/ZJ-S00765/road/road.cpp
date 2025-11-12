#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
const int INF=1e18;
const int MOD=1e9+7;
int n,m,k,fa[10005],mp[10005][15],c[N],ans=INF;
struct edge{
	int u,v,w;
}e[N];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int kruskal(int n,int m){
	sort(e+1,e+m+1,cmp);
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v){
			fa[u]=v;
			cnt++;
			ans+=e[i].w;
			if(cnt==n-1)return ans;
		}
	}
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>mp[i][j];
	}
	for(int sta=0;sta<(1<<k);sta++){
		int base=0,x=0,pos=0;
		for(int i=k;i>=1;i--){
			if((sta&i)!=0){
				base+=c[i];
				pos++;
				for(int j=1;j<=n;j++){
					x++;
					e[m+x].u=pos+n,e[m+x].v=j,e[m+x].w=mp[i][j];
				}
			}
		}
		int p=base+kruskal(n+pos,m+x);
		ans=min(ans,p);
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
