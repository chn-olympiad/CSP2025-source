#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[514514],s[514514],lst[2000077],nxt[514514],dp[514514];
void main1(){

	memset(lst,-1,sizeof(lst));
	
	lst[0]=0;
	for(ll i=1;i<=n;i++){
//		cout<<s[i];
		if((a[i]^k)==0){
			nxt[i]=i;
		}
//		cout<<(s[i]^k)<<' ';
		if(lst[s[i]^k]!=-1){
			nxt[i]=lst[s[i]^k]+1;
		}
	
		lst[s[i]]=i;
		
		
	}

//	for(ll i=1;i<=n;i++){
//		cout<<next[i]<<' ';
//	}
//	cout<<'\n';
	for(ll i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(nxt[i]!=0){
			dp[i]=max(dp[i],dp[nxt[i]-1]+1);
		}
//		cout<<dp[i]<<' ';
	}
	cout<<dp[n];
	
//	getchar();
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	ll flag=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>255)flag=0;
		s[i]=s[i-1]^a[i];
	}
	main1();

	
	
	return 0;
}
