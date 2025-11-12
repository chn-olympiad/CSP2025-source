#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1001000;
struct node{
	int u,v,w;
}a[N];
ll n,m,k,ans,fa[N];
bool cmp(node& x,node& y){
	return x.w<y.w;
}
inline ll find(ll x){
	if(fa[x]==x) return x;
	else return find(fa[x]);
}
inline void kruskal(){
	sort(a+1,a+m+1,cmp);
	ll cnt=0;
	for(int i=1;i<=m;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		if(cnt==n-1) return ;
		if(find(a[i].u)!=find(a[i].v)){
			ans+=a[i].w;
			fa[a[i].u]=a[i].v;
			cnt++;
		}
	}
}
inline void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	kruskal();
	cout<<ans;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
}
