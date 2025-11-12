#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int find(int x,vector<int>& f){
	return (f[x]==x?x:f[x]=find(f[x],f),f[x]);
}
ll solve(multiset<array<ll,3>>& e,int n){
	vector<int> f(n+5),s(n+5,1);
	for(int i=1;i<=n;i++) f[i]=i;
	ll ans=0,cnt=0;
	for(array<ll,3> ed:e){
		int u=find(ed[1],f),v=find(ed[2],f);
		if(u!=v) f[u]=v,s[v]+=s[u],ans+=ed[0],cnt++;
		if(cnt>=n) break;
	}
	if(s[find(1,f)]<n) return 9*1e18;
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k,ans=9*1e18;
	cin>>n>>m>>k;
	multiset<array<ll,3>> e;
	for(int i=1,u,v,w;i<=m&&cin>>u>>v>>w;i++)
		e.insert({w,u,v});
	ans=solve(e,n);
	for(int i=1,nn=n,c;i<=k&&cin>>c;i++){
		multiset<array<ll,3>> ne=e;
		ne.insert({c,nn+1,nn+2});
		for(int j=1,a;j<=n&&cin>>a;j++){
			ne.insert({a,j,nn+1});
			ne.insert({a,j,nn+2});
		}
		ll s=solve(ne,nn);
		if(s<ans) ans=s,nn+=2,swap(ne,e);
	}
	cout<<ans;
	
	
	return 0;
}