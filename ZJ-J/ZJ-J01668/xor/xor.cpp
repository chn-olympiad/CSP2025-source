#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],s[500010],l[500510],r[500510],dp[500510],cnt=0,ans=0;
long long f(int l,int r){
	if(l==r)return a[l];
	return (s[r]^s[l-1]);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]^s[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f(i,j)==k){
				l[++cnt]=i,r[cnt]=j;
			}
		}
	}
	for(int i=cnt;i>=1;i--){
		int dl=l[i],dr=r[i];
		dp[i]=1;
		for(int j=cnt;j>=i+1;j--){
			if(dr<l[j]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
