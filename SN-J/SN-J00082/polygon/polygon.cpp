#include<bits/stdc++.h>
using namespace std;

#define mod 998244353
#define int long long
#define rep(i,o,n) for(int i = o;i <= n;i++)
#define dep(i,o,n) for(int i = o;i >= n;i--)
#define mem(x,p) memset(x,p,sizeof x)

const int N = 50010;
int n;
int ans1 = 1;
int ans;
int a[N];
int dp[3][N];

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	rep(i,1,n) cin>>a[i],ans1 = (ans1*2)%mod;
	sort(a+1,a+1+n);
	ans+=n*(n-1)/2+n+1;
	ans%=mod;
	dp[0][0]=1;
	rep(i,1,n){
		int x=0;
		rep(j,0,a[i]) x+=dp[2][j],x%=mod;
		ans+=x;
		ans%=mod;
		dep(k,3,1){
			dep(j,5000,a[i]) {
				dp[min(k,2ll)][j]+=dp[k-1][j-a[i]];
				dp[min(k,2ll)][j]%=mod;
			}
		}
	}
	cout<<(ans1%mod-ans%mod+mod+mod)%mod;
}

