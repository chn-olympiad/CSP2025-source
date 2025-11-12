#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,k,a[N],s[N],dp[N],ed;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k>>a[1];
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i-1;j>=ed;j--){
			int f=s[i]^s[j];
			if(s[i]==k&&j==0){
				ed=i;
				dp[i]=max(dp[i],1);
			}
			else if(f==k){
				ed=i;
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	cout<<dp[n];
	return 0;
}
