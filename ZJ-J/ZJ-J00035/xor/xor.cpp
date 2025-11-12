#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=(1<<20);
int n,k,a[N],s[N],dp[N],last[M],l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<M;i++){
		last[i]=-1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		s[i]=(s[i-1]^a[i]);
	}for(int i=1;i<=n;i++){
		l=k^s[i];
		if(last[l]!=-1){
			dp[i]=max(dp[last[l]]+1,dp[i-1]);
		}else{
			dp[i]=dp[i-1];
		}
		last[s[i]]=i;
	}cout<<dp[n];
	return 0;
} 
