#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, b[10005];
struct node{
	ll u, v, w;
}a[10005];
struct data{
	ll next, w;
};
ll cen[35][10005];
bool vis[35][10005];
bool cmp(node x, node y){
	return x.w<y.w;
}
ll find(ll x){
	if(b[x]==x)return x;
	return b[x]=find(b[x]);
}
//unordered_map<pair<ll, ll>, ll>mp;
ll minn=1e18, ans;
vector<ll> tre;
vector<data>t[10005];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(ll i=1; i<=m; i++)cin >> a[i].u >>  a[i].v >> a[i].w;
	for(ll j=0; j<=n; j++)b[j]=j;
	for(ll i=1; i<=k; i++){
		ll answ=0;
		for(ll j=0; j<=n; j++){
			cin >> cen[i][j];
			answ+=cen[i][j];
		}
		minn=min(answ, minn);
	}
	sort(a+1, a+1+n, cmp);
	for(ll i=1; i<=n; i++){
		ll x=find(a[i].u), y=find(a[i].v);
		if(x==y)continue;b[x]=y;
		ans+=a[i].w;
//		mp[{x, y}]=mp[{y, x}]=a[i].w;
		t[a[i].u].push_back({a[i].v, a[i].w});
		t[a[i].v].push_back({a[i].u, a[i].w});
		tre.push_back(i);
	}
	if(k==0)return cout<<ans, 0;
	minn=min(ans, minn);
	for(ll i=1; i<=k; i++){
		ll sum=0, answ=ans, maxc=0;
		for(ll j=0; j<=n; j++){
			sum+=cen[i][j];
		}
		for(ll j=1; j<=n; j++){
			sum-=cen[i][j];ll minn=1e18;
			for(auto v:t[j]){
				minn=min(minn, v.w);
			}answ-=minn;
			if(ans-sum>maxc)maxc=max(maxc, answ-sum);
			else sum+=cen[i][j], answ+=minn;
		}
	}
	cout<<minn;
	return 0;
}
//16·Ö + £¿·Ö 
