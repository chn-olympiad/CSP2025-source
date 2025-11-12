#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct edge{
	int v,u;
	ll w;
}g[2000006];
bool cmp(edge x,edge y){ return x.w<=y.w;}
ll n,m,s,p[15][10005],k[200005],ans;
ll find(int x){
	if(k[x]!=x)return find(k[x]);
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		cin>>g[i].v>>g[i].u>>g[i].w;
		k[i]=i;
	}
	for(int i=1;i<=s;i++){
		for(int j=1;j<=n;j++) cin>>p[i][j];
	}
	sort(g+1,g+1+m,cmp);
	int f=n-1;
	for(int i=1;i<=m;i++){
		if(find(g[i].v)==find(g[i].u)) continue;
		f--;
		ans+=g[i].w;
		k[g[i].v]=find(g[i].u);
		if(f==0) break;
	}
	cout<<ans<<endl;
	return 0;
}

