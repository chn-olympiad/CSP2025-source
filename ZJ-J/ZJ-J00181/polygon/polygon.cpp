#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PQ priority_queue
const int N=5005,mod=998244353;
int ans,a[N];
unsigned int sum[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]<=a[3])cout<<0;
		else cout<<1;
	}
	sum[1]=1;
	for(int i=2;i<=n;i++)
		sum[i]=(sum[i-1]*i)%mod;
	for(int i=n;i>=3;i--){
		int x=1;
		ans=(ans+sum[i]/sum[n])%mod;
	}
	if(a[n]==1)cout<<ans;
	return 0;
}
