#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w;
	bool operator<(const node y)const{return w<y.w;}
}a[1100005];
int road[15][10005],c[15],id[15],f[10005];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i],ans+=c[i];
		for(int j=1;j<=n;j++){
			cin>>road[i][j];
			if(!road[i][j]) id[i]=j;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(j==id[i]) continue;
			a[++m]={id[i],j,road[i][j]};
		}
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++){
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx!=fy) f[fx]=fy,ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}
