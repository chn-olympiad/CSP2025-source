#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],cnt[505],C[505][505];
string str;
namespace solve1{
	int dp[505][505];
	int cal[505][505];
	void solve(){
		for(int i=0;i<=n;i++){
			cal[i][0]=1;
			for(int j=1;j<=n;j++) cal[i][j]=1ll*cal[i][j-1]*(i+j-1)%mod;
		}
		dp[0][0]=cal[1][cnt[0]];
		int now=cnt[0];
		for(int i=0;i<n;i++){
			for(int j=0;j<=n;j++) if(dp[i][j]){
				int x=dp[i][j];
				int pre=min(now+1,i+j+1),suf=now+1-pre;
				for(int p=0;p<=cnt[i+1];p++){
					dp[i+1][j+p]=(dp[i+1][j+p]+1ll*cal[pre][p]*cal[suf][cnt[i+1]-p]%mod*C[cnt[i+1]][p]%mod*x)%mod;
				}
			}
			now+=cnt[i+1];
		}
		int ans=0;
		for(int i=m;i<=n;i++) ans=(ans+dp[n][i])%mod;
		cout<<ans<<"\n";
	}
}
namespace solve2{
	int dp[1000005][20];
	void add(int &u,int v){u+=v,u-=(u>=mod)*mod;}
	void solve(){
		dp[0][0]=1;
		for(int i=0;i<(1<<n);i++) for(int j=0;j<=n;j++) if(dp[i][j]){
			int t=__builtin_popcount(i);
			for(int k=0;k<n;k++) if(!((i>>k)&1)) add(dp[i|(1<<k)][j+(str[t+1]=='0'||j>=c[k+1])],dp[i][j]);
		}
		int ans=0;
		for(int i=0;i<=n-m;i++) add(ans,dp[(1<<n)-1][i]);
		cout<<ans<<"\n";
	}
}
namespace solve3{
	void solve(){
		int ans=1,now=0,al=1;
		for(int i=1;i<=n;i++){
			now+=cnt[i-1],al=1ll*al*i%mod;
			if(str[i]=='1') ans=1ll*ans*now%mod,now--;
		}
		for(int i=1,j=1;i<=n;i++) if(str[i]=='0') ans=1ll*ans*j%mod,j++;
		cout<<(al-ans+mod)%mod<<"\n";
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=0;i<=500;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	cin>>n>>m>>str,str=" "+str;
	for(int i=1;i<=n;i++) cin>>c[i],cnt[c[i]]++;
	int tmp=0;
	for(int i=1;i<=n;i++) tmp+=str[i]-'0';
	if(tmp<m){cout<<"0\n";return 0;}
	if(tmp==n){solve1::solve();return 0;}
	if(n<=18){solve2::solve();return 0;}
	if(m==1){solve3::solve();return 0;}
	cout<<"114514\n";
	return 0;
}