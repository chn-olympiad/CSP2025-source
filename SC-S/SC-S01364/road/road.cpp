#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int u,v,w;
}mp[1000010];
int n,m,k,a[11][1000010],c[1000010],fat[1000010],ans;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find_(int i){
	if(fat[i]==i) return i;
	return fat[i]=find_(fat[i]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>mp[i].u>>mp[i].v>>mp[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(c[1]==0){
		int cnt;
		for(int i=1;i<=n;i++){
			if(a[1][i]==0) cnt++;
		}
		if(cnt==n){
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++) fat[i]=i;
	sort(mp+1,mp+1+m,cmp);
	for(int i=1;i<=m;i++){
		int u=find_(mp[i].u),v=find_(mp[i].v);
		if(u!=v){
			ans+=mp[i].w;
			fat[u]=v;
		}
	}
	cout<<ans;
	return 0;
}