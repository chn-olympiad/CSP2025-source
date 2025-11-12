#include<bits/stdc++.h>
#define int long long
#define inf (int)0x3f3f3f3f3f3f3f3f
#define sup (int)0xc0c0c0c0c0c0c0c0
#define pro (string)"polygon"
#define mod (int)998244353

using namespace std;
const int e=5e3+10;

int n,maxn;
int a[e],dp[e][e];

void file_read();

void c(){
	for(int i=0;i<=n;i++)
		dp[i][1]=i,dp[i][i]=dp[i][0]=1;
	
	for(int i=1;i<=n;i++)
		for(int j=2;j<i;j++)
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
	
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	file_read();
	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],maxn=max(maxn,a[i]);
		
	if(n<=2)
		cout<<"0\n";
	else if(n==3){
		if(a[1]+a[2]<=a[3]||a[1]+a[3]<=a[2]||a[3]+a[2]<=a[1])
			cout<<"0\n";
		else cout<<"1\n";
	}
	else if(maxn==1){
		c();
		
		int ans=0;
		for(int i=3;i<=n;i++)
			ans=(ans+dp[n][i])%mod;
		
		cout<<ans<<'\n';
	}
	else cout<<"0\n";
	
	return 0;
}

void file_read(){
	#ifdef pro
	freopen((pro+".in").c_str(),"r",stdin);
	freopen((pro+".out").c_str(),"w",stdout);
	#endif
	
	return;
}
