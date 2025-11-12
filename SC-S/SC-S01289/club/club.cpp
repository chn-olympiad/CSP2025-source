#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define il inline
#define fi first
#define se second
using namespace std;
const ll N=1e5+10;
ll T;
ll n,a[N][3];
ll ch[N];
ll sun[N];
ll b[N],tot;
void solve(){
	cin>>n;
	ll ans=0;
	ll cnt0=0,cnt1=0,cnt2=0;
	tot=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			ch[i]=0;
			ans+=a[i][0];
			sun[i]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
			cnt0++;
		}
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			ch[i]=1;
			ans+=a[i][1];
			sun[i]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
			cnt1++;
		}
		else{
			ch[i]=2;
			ans+=a[i][2];
			sun[i]=min(a[i][2]-a[i][1],a[i][2]-a[i][0]);
			cnt2++;
		}
	}
	if(cnt0<=n/2&&cnt1<=n/2&&cnt2<=n/2){
		cout<<ans<<"\n";
		return;
	}
	for(ll i=1;i<=n;i++){
		if(ch[i]==0&&cnt0>n/2) b[++tot]=sun[i];
		else if(ch[i]==1&&cnt1>n/2) b[++tot]=sun[i];
		else if(ch[i]==2&&cnt2>n/2) b[++tot]=sun[i];
	}
	ll x;
	if(cnt0>n/2) x=cnt0-n/2;
	else if(cnt1>n/2) x=cnt1-n/2;
	else x=cnt2-n/2;
	sort(b+1,b+tot+1);
	for(ll i=1;i<=x;i++){
		ans-=b[i];
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}