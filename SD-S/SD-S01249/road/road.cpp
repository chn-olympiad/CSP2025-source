#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,pair<ll,ll> >
#define mp make_pair
inline ll read(){
	ll x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	return f?-x:x;
}
struct qwq{
	ll u,v,w;
}arr[1000010];
ll f[10010];
bool cmp(qwq x,qwq y){
	return x.w<y.w;
}
inline ll find_zx(ll x){
	if(f[x]==x) return x;
	return f[x]=find_zx(f[x]);
}
inline bool check(ll x,ll y){
	return find_zx(x)==find_zx(y);
}
inline void add(ll x,ll y){
	ll fx=find_zx(x),fy=find_zx(y);
	if(fx==fy) return;
	f[fx]=fy;
}
//priority_queue<pll ,vector<pll >,greater<pll > > q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n=read(),m=read(),k=read();
	for(ll i=1;i<=n;i++) f[i]=i;
	for(ll i=1;i<=m;i++){
		arr[i].u=read(),arr[i].v=read(),arr[i].w=read();
	}
	sort(arr+1,arr+n+1,cmp);
	if(k<=0){
		ll cnt=n,ans=0;
		for(ll i=1;i<=m;i++){
			ll u=arr[i].u,v=arr[i].v;
			if(check(u,v)) continue;
			add(u,v);
			cnt--,ans+=arr[i].w;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
