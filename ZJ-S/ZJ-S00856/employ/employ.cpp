#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
int n,m,c[505];
string s;
ll fac[505];
int dp[2][300010][19];
int cnt[300010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
	cin>>s;
	bool flg=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i-1]=='0') flg=1;
	}
	sort(c+1,c+n+1);
	if(n<=18){
		dp[0][0][0]=1;
		for(int msk=0;msk<(1<<n);msk++){
			for(int j=0;j<n;j++){
				if(msk&(1<<j)) cnt[msk]++;
			}
		}
		for(int i=0;i<n;i++){
			for(int msk=0;msk<(1<<n);msk++)
				for(int j=0;j<=n;j++)
					dp[i&1^1][msk][j]=0;
			for(int msk=0;msk<(1<<n);msk++){
				if(cnt[msk]!=i) continue;
				for(int j=0;j<=n;j++){
					if(!dp[i&1][msk][j]) continue;
					for(int k=1;k<=n;k++){
						if(msk&(1<<k-1)) continue;
						int nj=j+(c[k]<=j||s[i]=='0');
						dp[i&1^1][msk|(1<<k-1)][nj]=(dp[i&1^1][msk|(1<<k-1)][nj]+dp[i&1][msk][j])%MOD;
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++){
			ans=(ans+dp[n&1][(1<<n)-1][i])%MOD;
		}
		cout<<ans;
	}else if(m==1){
		ll ans=1;
		for(int i=1,j=0;i<=n;i++){
			while(j<n&&c[j+1]<=i-1) ++j;
			ans=ans*((ll)j-i+1)%MOD;
			if(j-i+1<=0) ans=0;
		}
		ans=fac[n]-ans+MOD;
		ans%=MOD;
		cout<<ans;
	}else if(m==n){
		if(flg) cout<<0;
		else{
			bool fflg=0;
			for(int i=1;i<=n;i++){
				if(c[i]==0) fflg=1;
			}
			if(fflg) cout<<0;
			else cout<<fac[n];
		}
	}else{
		cout<<0;	
	}
	return 0;
}