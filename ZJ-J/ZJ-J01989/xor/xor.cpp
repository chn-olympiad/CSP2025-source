#include<bits/stdc++.h>
using namespace	 std;
const long long N=5e5+5;
long long a[N],s[N];
long long dp[N];
map<long long,long long> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	long long ans=0;
	mp[0]=0;
	for(long long i=1;i<=n;i++){
		long long t=s[i]^k,lst=-1;
		if(mp.find(t)!=mp.end()) lst=mp[t];
		mp[s[i]]=i,dp[i]=ans;
	    if(lst!=-1) dp[i]=max(dp[i],dp[lst]+1);
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
