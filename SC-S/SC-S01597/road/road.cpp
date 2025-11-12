#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,cost[20],add;
ll fa[1020];
ll findroot(ll x){
	if(fa[x]==x) return x;
	return fa[x]=findroot(fa[x]);
}
void univo(ll x,ll y){
	if(findroot(x)!=findroot(y)){
		fa[findroot(x)]=findroot(y);
	}
}
struct node{
	ll nxt,to,dis;
} tre[1500000];
ll top;
ll tree(ll open){
	for(ll i=1;i<=n+k;i++) fa[i]=i;
	ll ans=cost[open];
	for(ll i=1;i<=top;i++){
		if(tre[i].nxt>n and tre[i].nxt-n!=open){
			continue;
		}
		if(tre[i].to>n and tre[i].to-n!=open){
			continue;
		}
		ll rx=findroot(tre[i].nxt),ry=findroot(tre[i].to);
		if(rx==ry) continue;
		univo(rx,ry);
		ans+=tre[i].dis;
	}
	for(int i=2;i<=n;i++) if(findroot(i)!=findroot(i-1)) return 1e18;
	if(findroot(open+n)!=findroot(1)) return 1e18;
	return ans;
}
bool cmp(node a,node b){return a.dis<=b.dis;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		tre[++top].dis=c;
		tre[top].nxt=a;tre[top].to=b;
	}
	for(ll i=1;i<=k;i++){
		cin>>cost[i];
		for(ll j=1;j<=n;j++){
			ll a;cin>>a;
			tre[++top].dis=a;
			tre[top].nxt=i+n;tre[top].to=j;
		}
	}
	sort(tre+1,tre+1+top,cmp);
	ll com=tree(-1),add=0;
	for(ll i=1;i<=k;i++){
		ll w=tree(i);
		if(com>w){
			add+=com-w;
		}
	}
	cout<<com-add;
	return 0;
}