#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll le=2000010ll,ln=10010ll,maxx=9187201950435737471ll;
struct e{
	ll x,y,l;
}ed[le];
ll n,m,k;
ll c[11ll],a[11ll][ln],f[ln],edge[1010ll][1010ll];
bool cmp(e a,e b){
	return a.l<b.l;
}
ll fi(ll x){
	if(f[x]!=x){
		f[x]=fi(f[x]);
	}
	return f[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0ll){
		for(ll i=1ll;i<=m;i++){
			scanf("%lld%lld%lld",&ed[i].x,&ed[i].y,&ed[i].l);
		}
		sort(ed+1ll,ed+m+1ll,cmp);
		for(ll i=1ll;i<=n;i++){
			f[i]=i;
		}
		ll ans=0ll,cnt=0ll;
		for(ll i=1ll;i<=m&&cnt<n-1ll;i++){
			if(fi(ed[i].x)!=fi(ed[i].y)){
				f[fi(ed[i].x)]=fi(ed[i].y);
				ans+=ed[i].l;
				cnt++;
			}
		}
		cout<<ans;
	}
	else{
		memset(edge,127,sizeof(edge));
		//cout<<edge[1][1]<<endl;
		for(ll i=1ll;i<=m;i++){
			ll x,y,l;
			scanf("%lld%lld%lld",&x,&y,&l);
			edge[max(x,y)][min(x,y)]=l;
		}
		//cout<<1<<endl;
		for(ll i=1ll;i<=k;i++){
			scanf("%lld",&c[i]);
			for(ll j=1ll;j<=n;j++){
				scanf("%lld",&a[i][j]);
			}
			for(ll j=2ll;j<=n;j++){
				for(ll k=1ll;k<j;k++){
					edge[j][k]=min(edge[j][k],c[i]+a[i][j]+a[i][k]);
				}
			}
		}
		//cout<<2<<endl;
		ll len=0ll;
		for(ll i=2ll;i<=n;i++){
			for(ll j=1ll;j<i;j++){
				if(edge[i][j]!=maxx){
					ed[++len].x=j,ed[len].y=i,ed[len].l=edge[i][j];
				}
			}
		}
		//cout<<3<<endl;
		sort(ed+1ll,ed+len+1ll,cmp);
		//cout<<4<<endl;
		for(ll i=1ll;i<=n;i++){
			f[i]=i;
		}
		ll ans=0ll,cnt=0ll;
		for(ll i=1ll;i<=len&&cnt<n-1ll;i++){
			if(fi(ed[i].x)!=fi(ed[i].y)){
				f[fi(ed[i].x)]=fi(ed[i].y);
				ans+=ed[i].l;
				cnt++;
			}
		}
		cout<<ans;
	}
	//cout<<endl<<clock();//
	return 0;
}
