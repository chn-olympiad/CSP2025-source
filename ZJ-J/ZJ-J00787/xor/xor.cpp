#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,flag=0,sum=0;
int a[N],dp[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=(a[i]==1);
	    if(a[i]>1)flag=1;
	}
	if(flag==0){
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int t=0;
		dp[i]=dp[i-1];
		for(int j=i;j>=1&&dp[j-1]+1>dp[i];j--){
			t^=a[j];
			if(t==k){
				dp[i]=dp[j-1]+1;
			    break;
			}
			if(k!=0&&t==0)break;
		}
	}
	cout<<dp[n];
	return 0;
}
