#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
struct ddd{
	ll x,y,w;
}t[N];
ll fa[N],n,m,k;
ll find(ll x){
	if(fa[x]==x){
		return x;
	}
	else{
		return fa[x]=find(fa[x]);
	}
}
ll cmp(ddd a,ddd b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	cin>>t[i].x>>t[i].y>>t[i].w;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		ll c;
		cin>>c;
		for(int j=1;j<=c;j++){
			ll d;
			cin>>d;
		}
	}
	sort(t+1,t+n+1,cmp);
	ll ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		ll xx=find(t[i].x);
		ll yy=find(t[i].y);
		if(xx!=yy){
			fa[xx]=yy;
			ans+=t[i].w;
			cnt++;
		}
		if(cnt==n-1){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
