#include<bits/stdc++.h>
#define ll long long
#define N 25000000
using namespace std;
ll dp[N+100],a[N+100],cnt[10001],maxx,pre[N];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	cin>>n;
	ll ans=0;
	for(ll i=1;i+2<=n;i++){
		ans+=n-i-2;
	}
	cout<<ans;
//	for(ll i=1; i<=n; i++) {
//		cin>>a[i];
//		maxx+=a[i];
//	}
//
//	sort(a+1,a+n+1);
//	for(ll i=1; i<=n; i++) {
//		for(ll j=maxx; j>0; j--) {
//			dp[j+a[i]]+=dp[j]+cnt[j];
//		}
//		cnt[a[i]]++;
//	}
//	a[n+1]=INT_MAX;
//	ll ans=0;
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=maxx;j++){
//			if(a[i]<j){
//				ans+=dp[i];
//			}
//		}
//	}
//	cout<<ans;
	return 0;
}
