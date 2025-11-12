#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,vis[10015],ans,ans1,ans2,c[15],used[15];
vector<pair<ll,ll> >ve[10015];//1~n:城市   n+1~n+k:乡村
ll kru(){
	ll res=0;
	memset(vis,0,sizeof(vis));
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q;
	q.push({0,1});
	while(!q.empty()){
		auto u=q.top();
		q.pop();
		if(vis[u.second])continue;
		vis[u.second]=1;
		res+=u.first;
		for(auto v:ve[u.second]){
			if(v.second<=n||used[v.second-n])q.push(v);
		}
	}
	for(ll i=1;i<=k;i++)res+=used[i]*c[i];
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		ve[u].push_back({w,v});
		ve[v].push_back({w,u}); 
	}
	for(ll i=1;i<=k;i++){
		ll t;
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>t;
			ve[j].push_back({t,n+i});
			ve[n+i].push_back({t,j});
		}
	}
	ans=ans1=ans2=kru();
	if(k==0){
		cout<<ans;
		return 0;
	}
	if(k<=5){	
		for(ll i=0;i<(1<<k);i++){
			for(ll j=1;j<=k;j++){
				used[j]=bool((i>>(j-1)&1ll));
			}
			ans1=min(ans1,kru());
		}
		cout<<min(ans,ans1);
		return 0;
	}
	for(ll i=0;i<(1<<(k/2));i++){
		for(ll j=1;j<=k/2;j++){
			used[j]=bool((i>>(j-1)&1ll));
		}
		ans1=min(ans1,kru());
	}
	memset(used,0,sizeof(used));
	for(ll i=0;i<(1<<(k-k/2));i++){
		for(ll j=k/2+1;j<=k;j++){
			used[j]=bool((i>>(j-k/2-1)&1));
		}
		ans2=min(ans2,kru());
	}
	cout<<min(ans,ans1+ans2-ans);
	return 0;
}
/*
4 4 2 1 4 6 2 3 7 4 2 5 4 3 4 1 1 8 2 4 100 1 3 2 4

4 3 2
1 2 1
2 3 100
2 4 100
0 100 100 1 1
0 100 100 2 2

*/

