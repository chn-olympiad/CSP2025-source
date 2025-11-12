#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],dp[N],pre[N];
int n,k,maxn;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	pre[1]=a[1];
	for(int i=2;i<=n;i++) pre[i]=pre[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int f=pre[i]^pre[j-1];
			if(f==k) f=1;
			else f=0;
			dp[i]=max(dp[i],dp[j-1]+f);
		}
	}
	cout<<dp[n];
	return 0;
}
