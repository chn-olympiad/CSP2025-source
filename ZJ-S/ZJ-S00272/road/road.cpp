#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,fa[100050],ans=0xffffff;
struct village{
	ll c,a[100050];
}vil[15];
ll father(ll id){
	while(fa[id]!=id){
		id=fa[id];
	}
	return id;
}
bool is_sf(ll a,ll b){
	if(father(a)==father(b)){
		return true;
	}
	return false;
}

pair<ll,pair<ll,ll > > edge[100050],fe;
priority_queue <pair<ll,ll>,vector<pair<ll,pair<ll,ll>> >,greater<pair<ll,pair<ll,ll>> > > pq;
ll ku(ll sum,ll num){
	for(ll i=-num;i<=n;i++){
		fa[i]=i;
	}
	ll c=0;
	while(c<n-1+num&&!pq.empty()){
		fe=pq.top();
		pq.pop();
		if(!is_sf(fe.second.first,fe.second.second)){
			sum+=fe.first;
			fa[fe.second.first]=fe.second.second;
			c++;
		}
	}
	return sum;
}
void solve(){
	for(int i=0;i<=pow(2,k);i++){
		ll rep=0,num=0;
		while(!pq.empty()){
			pq.pop();
		}
		for(int j=1;j<=m;j++){
			pq.push(edge[j]);
		}
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				num++;
				rep+=vil[j].c;
				for(int k=1;k<=n;k++){
					pq.push({vil[j].a[k],{k,-num}});
				}
			}
		}
		ans=min(ans,ku(rep,num));
		
	}	
	
}
void abc(){
	for(int i=1;i<=m;i++){
		pq.push(edge[i]);
	}
	ll c=0,ans=0;
	while(c<n-1&&!pq.empty()){
		fe=pq.top();
		pq.pop();
		if(is_sf(fe.second.first,fe.second.second)){
			fa[fe.second.second]=fe.second.first;
			c++;
			ans+=fe.first;
		}
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].second.first>>edge[i].second.second>>edge[i].first;
	}
	for(int i=0;i<k;i++){
		cin>>vil[i].c;
		for(int j=1;j<=n;j++){
			cin>>vil[i].a[j];
		}
	}
	solve();
	cout<<ans;
	return 0;
}
