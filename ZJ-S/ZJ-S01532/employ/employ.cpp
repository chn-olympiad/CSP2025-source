#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[505],dp[1 << 20][25],ans;
char str[505];
bool flag;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> (str+1) ;
	for(int i=1;i<=n;i++) cin >> c[i] ;
	for(int i=1;i<=n;i++) dp[1 << (i-1)][!!c[i]]++;
	for(int s=1;s<(1 << n)-1;s++){
		int pcnt=__builtin_popcount(s);
		flag=str[pcnt+1]-'0';
		for(int j=1;j<=n;j++){
			if((s >> (j-1)) & 1) continue;
			for(int i=0;i<=pcnt;i++) dp[s | (1 << (j-1))][i+flag*(c[j]>pcnt-i)]=(dp[s | (1 << (j-1))][i+flag*(c[j]>pcnt-i)]+dp[s][i])%mod;
		}/*cout << flag << " " << s << ":" ;
		for(int i=0;i<=pcnt;i++) cout << " " << dp[s][i] ;
		cout << "\n" ;*/
	}for(int i=m;i<=n;i++) ans=(ans+dp[(1 << n)-1][i])%mod;
	cout << ans ;
	return 0;
}
