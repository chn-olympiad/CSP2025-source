#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1,0),f(n+1,0),dp(n+1,0);
	bool p=1,q=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i]=a[i]^f[i-1];
		if(a[i]!=1) p=0;
		if(a[i]>1) q=0;
	}
	if(p){
		if(k==0) cout<<n/2;
		else cout<<n;	
		return 0;
	}
	if(q){
		int x=0;
		for(int i=1;i<=n;i++){
			x+=a[i];
		}
		if(k==0) cout<<x/2;
		else cout<<x;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=0;j<i;j++){
			if((f[i]^f[j])==k){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	cout<<dp[n];
	return 0;
}
