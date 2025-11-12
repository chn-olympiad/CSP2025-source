#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[11][11],c[11],tot,ans,f[10010];
struct s{
	int u,v,w;
}r[1000010];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
bool cmp(s x,s y){
	return x.w<y.w;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>r[i].u>>r[i].v>>r[i].w;
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	sort(r+1,r+n+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		if(tot==n-1) break;
		int x=find(r[i].u),y=find(r[i].v);
		if(x!=y){
			ans+=r[i].w;
			tot++;
			f[x]=y;
		}
	}
	cout<<ans;
	return 0;
}