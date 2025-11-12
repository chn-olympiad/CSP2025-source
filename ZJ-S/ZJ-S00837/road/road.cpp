#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct N{
	ll x,y,z;
	bool operator < (const N tmp) const{
		return z>tmp.z;
	}
};
priority_queue <N> r,h;
ll c[15],d[15][10005],fa[10015];
ll Find(ll x){
	if(fa[x] == x){
		return x;
	}
	return fa[x] = Find(fa[x]);
}
void Union(ll x,ll y){
	int a=Find(x),b=Find(y);
	fa[a] = b;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n,m,k,t,s,ans=1e17;
	bool f=1;
	cin>>n>>m>>k;
	t = (1<<k)-1;
	for(ll i=1;i<=m;i++){
		N g;
		cin>>g.x>>g.y>>g.z;
		r.push(g);
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]){
			f = 0;
		}
		for(ll j=1;j<=n;j++){
			cin>>d[i][j];
			if(d[i][j]){
				f = 0;
			}
		}
	}
	if(f){
		cout<<0;
		return 0;
	}
	for(ll i=0;i<=t;i++){
		h = r;
		ll res=0,cnt=0;
		s = n;
		for(ll j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				s++;
				res+=c[j];
				for(ll l=1;l<=n;l++){
					N w;
					w.x = n+j;
					w.y = l;
					w.z = d[j][l];
					h.push(w);
				}
			}
		}
		for(ll j=1;j<=n+k;j++){
			fa[j] = j;
		}
		while(!h.empty()&&cnt<s-1){
			N u = h.top();
			h.pop();
			if(Find(u.x)!=Find(u.y)){
				Union(u.x,u.y);
				cnt++;
				res+=u.z;
			}
		}
		ans = min(ans,res);
	}
	cout<<ans;
	return 0;
}
/*
rp++
*/
