#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int N=3e5+5,M=20,mod=998244353;
int t,n,m,a[N];
ll dp[N][M];
string s;
void colse(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve(){
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>=20){
		for(int i=1;i<=n;i++){
			if(!a[i]){
				cout<<0<<endl;
				return ;
			}
		}
		int _=1;
		for(int i=n;i>=1;i--) _=_*i%mod;
		cout<<_<<endl;
		return ;
	}
	dp[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		int op=0;
		for(int j=1;j<=n;j++) if(i&(1<<(j-1))) op++;
		for(int j=0;j<=n;j++){
			for(int k=1;k<=n;k++){
				if((i&(1<<(k-1)))==0){
					int _=j;
					if(a[k]<=j||s[op+1]=='0') _++;
					dp[i+(1<<(k-1))][_]=(dp[i+(1<<(k-1))][_]+dp[i][j])%mod;
				}
			}
		}
	}
	ll ret=0;
	for(int i=n-m;i>=1;i--) ret=(ret+dp[(1<<n)-1][i])%mod;
	cout<<ret<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	colse();
	t=1;
	while(t--) solve();
	return 0;
}