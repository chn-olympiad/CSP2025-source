#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct edge{
	int u,v,w;
}eg[50000005];
int f[10005];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]); 
}
int c[11];
int a[11][10005];
int n,m,k;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
bool ta=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		eg[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		if(c[i]!=0) ta=0;
	}
//	if(ta||k<=0){
		for(int o=1;o<=k;o++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){
					eg[++m]={i,j,a[o][i]+a[o][j]};
				}
			}
		}
		sort(eg+1,eg+1+m,cmp);
		for(int i=1;i<=n;i++) f[i]=i;
		int cnt=0;
		ll ans=0;
		for(int i=1;i<=m;i++){
			int x=eg[i].u,y=eg[i].v,w=eg[i].w;
			int fx=find(x),fy=find(y);
			if(fx==fy) continue;
			f[fx]=fy;
			ans+=w;
			if(++cnt==n-1) break;
		}
		cout<<ans;
//	}
	return 0;
}
