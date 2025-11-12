#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100005;
void solve(){
	int n;
	cin>>n;
	if(n==2){
		int ans=0,fa,fb,fc,sa,sb,sc;
		ans=max(fa+sb,fa+sc);
		ans=max(ans,fb+sc);
		ans=max(ans,sa+fb);
		ans=max(ans,sa+fc);
		ans=max(ans,sb+fc);
		cout<<ans<<endl;
	}
	else{
		int ans=0,a[100005],x,y;
		for(int i=1;i<=n;i++)cin>>a[i]>>x>>y;
		sort(a+1,a+n+1);
		for(int i=1;i<=n/2;i++)ans+=a[i];
		cout<<ans<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;while(t--)solve();
	
	return 0;
}