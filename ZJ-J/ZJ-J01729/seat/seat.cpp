#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fi first
#define se second
#define lc (u<<1)
#define rc ((u<<1)|1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pii;
const ll N=1e2+10;
pii a[N];
ll n,m,cnt;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].fi;
	a[1].se=1;
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		++cnt;
		if(a[i].se==1) break;
	}
	ll x=(cnt-1)/m+1,y=0;
	if((x&1)==1){
		y=(cnt-1)%m+1;
	}
	else{
		y=n-((cnt-1)%m);
	}
	cout<<x<<' '<<y;
	return 0;
}
