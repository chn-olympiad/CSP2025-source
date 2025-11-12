#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e3+5,mod=998244353;
int n,a[N],dp[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);int mx=a[1]+1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=mx;j++){
			dp[j]%=mod;
			dp[max(j-a[i],0ll)]+=dp[j];
		}
		dp[a[i]+1]++;
	}
	cout<<dp[0]%mod;
	return 0;
}

