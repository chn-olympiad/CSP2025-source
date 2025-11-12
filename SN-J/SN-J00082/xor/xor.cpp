#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,o,n) for(int i = o;i <= n;i++)
#define dep(i,o,n) for(int i = o;i >= n;i--)
#define mem(x,p) memset(x,p,sizeof x)
const int N = 500010;

int n,k;
int v = 0;
int dp[N];
int a[N];
map<int,int> m;

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>k;
	rep(i,1,n) cin>>a[i],a[i]^=a[i-1];
	m[0] = 0;
	rep(i,1,n){
		if(m.count(a[i]^k))dp[i] = max(dp[i-1],dp[m[a[i]^k]]+1);
		else dp[i] = dp[i-1];
		m[a[i]] = i;
	}
	cout<<dp[n];
}

