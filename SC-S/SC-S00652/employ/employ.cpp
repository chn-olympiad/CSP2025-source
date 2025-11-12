#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,MOD=998244353;
int n,m;
char s[N];
int c[N],ans;
int f[2][20][(1<<18)+1000];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)
		if(c[i])f[1&1][0][(1<<i-1)]=1;
		else f[1&1][1][(1<<i-1)]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=i;j++){
			for(int st=0;st<(1<<n);st++){
				if(f[i&1][j][st]){
					for(int k=1;k<=n;k++){
						if((1<<k-1)&st)continue;
						if(j>=c[k]||s[i+1]=='0')f[i+1&1][j+1][st|(1<<k-1)]+=f[i&1][j][st],f[i+1&1][j+1][st|(1<<k-1)]%=MOD;
						else f[i+1&1][j][st|(1<<k-1)]+=f[i&1][j][st],f[i+1&1][j][st|(1<<k-1)]%=MOD;
					}
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=i;j++){
//			for(int st=0;st<(1<<n);st++)
//				cout<<i<<' '<<j<<' '<<st<<' '<<f[i][j][st]<<'\n';
//		}
//	}
	for(int i=n-m;i>=0;i--)
		ans+=f[n&1][i][(1<<n)-1],ans%=MOD;
	cout<<ans;
	return 0;
}//20pts