#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500001],s[500001],dp[500001],r;
map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		int u=mp[s[i]];
		dp[i]=dp[i-1];
		if(a[i]==k){
			dp[i]++;
			r=i;
			continue;
		}
		if(u){
			if(u>r){
				dp[i]=max(dp[i],dp[u-1]+1);
				r=i;
			}
		}
		mp[s[i-1]^k]=i;
	}
	cout<<dp[n]<<endl;
	return 0;
}