#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
ll uu[N],vv[N],ww[N];
ll a[N][3];
void solve(){
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
	ll u=0,v=0,w=0,ans=0;
	for(ll i=1;i<=n;i++){
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])uu[++u]=i,ans+=a[i][0];
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])vv[++v]=i,ans+=a[i][1];
		else ww[++w]=i,ans+=a[i][2];
	}
	if(u)sort(uu+1,uu+u+1,[&](ll x,ll y){return a[x][0]-max(a[x][1],a[x][2])>a[y][0]-max(a[y][1],a[y][2]);});
	if(v)sort(vv+1,vv+v+1,[&](ll x,ll y){return a[x][1]-max(a[x][0],a[x][2])>a[y][1]-max(a[y][0],a[y][2]);});
	if(w)sort(ww+1,ww+w+1,[&](ll x,ll y){return a[x][2]-max(a[x][1],a[x][0])>a[y][2]-max(a[y][1],a[y][0]);});
	if(u>n/2)for(ll i=u;i>n/2;i--)ans-=a[uu[i]][0]-max(a[uu[i]][1],a[uu[i]][2]);
	if(v>n/2)for(ll i=v;i>n/2;i--)ans-=a[vv[i]][1]-max(a[vv[i]][0],a[vv[i]][2]);
	if(w>n/2)for(ll i=w;i>n/2;i--)ans-=a[ww[i]][2]-max(a[ww[i]][1],a[ww[i]][0]);
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t;
	cin>>t;
	while(t--)solve();
	return 0;
}
