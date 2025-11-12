#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,fa[10005],ans;
bool A = 1;
struct edge{
	int u,v,w;
	bool operator<(const edge&o)const{return w<o.w;}
}a[10005];
int find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x] = find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++) fa[i] = i;
	for(int i = 1,u,v,w;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i = 1,x;i<=k*(n+1);i++){
		cin>>x;
		if(x) A=0;
	}
	if(A&&k!=0) return cout<<0,0;
	sort(a+1,a+m+1);
	int cnt = 0;
	for(int i = 1;i<=m;i++){
		int U = find(a[i].u),V = find(a[i].v);
		if(U==V) continue;
		fa[U] = V,cnt++,ans+=a[i].w;
		if(cnt==n-1) break;
	}
	cout<<ans;
	return 0;
}
