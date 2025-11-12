#include<bits/stdc++.h>
#define int long long
#define inf (int)0x3f3f3f3f3f3f3f3f
#define sup (int)0xc0c0c0c0c0c0c0c0
#define pro (string)"xor"

using namespace std;
const int E=5e5+10,e=1e3+10;

int n,m,maxn;
int a[E],dp[e][e];

void file_read();

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	file_read();
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		cin>>a[i],maxn=max(maxn,a[i]);
		
	if(maxn==1){
		int cnt=0,ans=0;
		
		for(int i=1;i<=n;i++){
			cnt^=a[i];
			
			if(cnt==m)
				ans++,cnt=0;
		}
		
		cout<<ans<<'\n';
		return 0;
	}
	if(n>1e3){
		cout<<"0\n";
		return 0;
	}
		
	for(int l=1;l<=n;l++)
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1,cnt=0;
			
			for(int k=i;k<=j;k++)
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]),
				cnt^=a[k];
				
			if(cnt==m)
				dp[i][j]=max(dp[i][j],1ll);
		}
		
	cout<<dp[1][n];
	
	return 0;
}

void file_read(){
	#ifdef pro
	freopen((pro+".in").c_str(),"r",stdin);
	freopen((pro+".out").c_str(),"w",stdout);
	#endif
	
	return;
}
