#include<bits/stdc++.h>
using namespace std;
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}
const int MAXN=5e2+10;
const int mod=998244353;

int n,m,c[MAXN],fac[MAXN],dp[1<<18][19];
string s;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("employ2.in","r",stdin);
//	freopen("employ1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>s;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==n){
		bool flag=true;
		for(int i=1;i<=n;i++) if(c[i]==0) flag=false;
		for(int i=0;i<n;i++) if(s[i]=='1') flag=false;
		if(flag) cout<<0;
		else cout<<fac[n];
		return 0;
	}
	bool flag=true;
	for(int i=0;i<n;i++) if(s[i]=='0') flag=false;
	if(n<=18){
		dp[0][0]=1;
		for(int i=1;i<(1<<n);i++){
			int cnt=0;
			for(int j=0;j<n;j++) if(i&(1<<j)) cnt++;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					int z=i^(1<<j);
					for(int k=0;k<cnt;k++){
						if(s[cnt-1]=='0') (dp[i][k+1]+=dp[z][k])%=mod;
						else if(c[j+1]<=k) (dp[i][k+1]+=dp[z][k])%=mod;
						else (dp[i][k]+=dp[z][k])%=mod;
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++) (ans+=dp[(1<<n)-1][i])%=mod;
		cout<<ans;
	}
	return 0;
}
