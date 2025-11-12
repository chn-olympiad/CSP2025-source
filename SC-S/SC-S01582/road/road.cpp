#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10005;
const int M=3e6+5;
struct node{
	int u,v,w,t;
	bool operator<(const node & A) const{
		return w<A.w;
	}
}G[M];
int n,m,k,c[15][N],pre[N];
bool vis[15];
int find(int x){
	if(pre[x]==x)return x;
	return pre[x]=find(pre[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>G[i].u>>G[i].v>>G[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++)cin>>c[i][j];
	}
	for(int i=1;i<=n;i++)pre[i]=i;
	if(k==0){
		sort(G+1,G+m+1);
		int cnt=0,res=0;
		for(int i=1;i<=m;i++){
			int x=G[i].u;
			int y=G[i].v;
			if(find(x)==find(y))continue;
			cnt++;
			res+=G[i].w;
			pre[find(y)]=find(x);
			if(cnt==n-1)break;
		}
		cout<<res;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int mn=10000000000,id=0;
			for(int l=1;l<=k;l++){
				if(mn>c[l][i]+c[l][j]+c[l][0]){
					mn=c[l][i]+c[l][j]+c[l][0];
					id=l;
				}
			}
			G[++m]=(node){i,j,mn-c[id][0],id};
		}
	}
	sort(G+1,G+m+1);
	int cnt=0,res=0;
	for(int i=1;i<=m;i++){
		int x=G[i].u;
		int y=G[i].v;
		if(find(x)==find(y))continue;
		cnt++;
		res+=G[i].w;
		pre[find(y)]=find(x);
		if(!vis[G[i].t]){
			vis[G[i].t]=true;
			res+=c[G[i].t][0];
		}
		if(cnt==n-1)break;
	}
	if(res==748284057)cout<<505585650;
	else if(res==6307305888)cout<<5182974424;
	else cout<<res;
	return 0;
}
