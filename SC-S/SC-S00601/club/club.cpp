#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct node{
	ll id,m[3];
};
struct nal{
	ll id,m;
};
bool cmp(const nal &x,const nal &y){return x.m>y.m;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll t,n;cin>>t;
	while(t--&&cin>>n){
		bool f=1;
		ll ans=0,cnt;
		vector<node> a(n+1);
		vector<nal> x;
		vector<vector<nal>> g(3);
		for(ll i=1;i<=n;i++)
			for(ll j=0;j<3;j++)cin>>a[i].m[j],a[i].id=i;
		for(ll i=1;i<=n;i++)
			if(a[i].m[0]==*max_element(begin(a[i].m),end(a[i].m)))g[0].push_back({a[i].id,a[i].m[0]});
			else if(a[i].m[1]==*max_element(begin(a[i].m),end(a[i].m)))g[1].push_back({a[i].id,a[i].m[1]});
			else g[2].push_back({a[i].id,a[i].m[2]});
		for(ll i=0;i<3;i++)if(g[i].size()>n/2)f=0,cnt=i;
		if(f){
			for(ll i=0;i<3;i++)
				for(ll j=0;j<g[i].size();j++)ans+=g[i][j].m;
			cout<<ans<<'\n';
		}
		else{
			for(ll i=0;i<3;i++)
				for(ll j=0;j<g[i].size();j++)ans+=g[i][j].m;
			for(ll i=0;i<g[cnt].size();i++)x.push_back({g[cnt][i].id,g[cnt][i].m-max(a[g[cnt][i].id].m[(cnt+1)%3],a[g[cnt][i].id].m[(cnt+1)%2])});
			sort(begin(x),end(x),cmp);
			for(ll i=n/2;i<x.size();i++)ans-=x[i].m;
			cout<<ans<<'\n';
		}
	}
	return 0;
}