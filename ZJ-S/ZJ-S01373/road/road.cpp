#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e4+5;
const int maxm=1e6+5;
ll n,m,k,cnt=0,ans=0;
ll v[maxm];
ll cost[15];
ll cont[15][maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
	    ll a,b,w;
	    cin>>a>>b>>w;
	    v[++cnt]=w;
	}
	for(ll i=1;i<=k;i++){
		cin>>cost[i];
		for(ll j=1;j<=n;j++){
			cin>>cont[i][j];
		}
		for(ll l=1;l<=n;l++){
			for(ll r=l+1;r<=n;r++){
				ll w=cont[i][l]+cont[i][r];
				v[++cnt]=w;
			}
		}
	}
	sort(v+1,v+cnt+1);
	for(ll i=1;i<n;i++)ans+=v[i];
	cout<<ans<<endl;
	return 0;
}