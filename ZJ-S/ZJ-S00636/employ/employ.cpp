#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N=505,p=998244353;
int n,m,c[N];
string s;

namespace sub1{//n<=18
	const int Ns=19;
	int dp[1<<Ns][Ns];
	int cnt(int x){
		int res=0;
		while(x)
			res+=(x&1),
			x>>=1;
		return res;
	}
	void solve(){
		dp[0][0]=1;
		for(int i=0;i<(1<<n)-1;i++){
			int C=cnt(i);
			for(int j=0;j<=C;j++){
				for(int k=1;k<=n;k++){
					if((i>>(k-1))&1)continue;
					if(c[k]>j&&s[C+1]=='1')dp[i+(1<<(k-1))][j]=(dp[i+(1<<(k-1))][j]+dp[i][j])%p;
					else dp[i+(1<<(k-1))][j+1]=(dp[i+(1<<(k-1))][j+1]+dp[i][j])%p;
				}
//				cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
			}
		}
		int ans=0;
		for(int i=n-m;i>=0;i--)
			ans=(ans+dp[(1<<n)-1][i])%p;
		cout<<ans<<"\n";
		return ;
	}	
};

namespace sub2{//m=n
	void solve(){
		for(int i=1;i<=n;i++)
			if(s[i]=='0'){
				cout<<"0\n";
				return;
			}
		for(int i=1;i<=n;i++)
			if(c[i]==0){
				cout<<"0\n";
				return;
			}
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*i%p;
		cout<<ans<<"\n";
		return;
	}	
};

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n<=18)sub1::solve();
	else if(m==n)sub2::solve();
	else cout<<"0\n";
	return 0;
}
