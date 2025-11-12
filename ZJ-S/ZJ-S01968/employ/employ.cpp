#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
using namespace std;
const int N=20,M=3e5,mod=998244353;
int n,m,a[505],f[M][N];
char s[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	if(n<=18){
		cin>>s;
		for(int i=0;i<n;i++)cin>>a[i];
		f[0][0]=1;
		for(int i=0;i<(1<<n)-1;i++){
			int c=0;
			for(int j=0;j<n;j++)c+=(i>>j&1);
			for(int j=0;j<n;j++)if(!(i>>j&1)){
				for(int k=0;k<n;k++)
					f[i|(1<<j)][k+(c-k<a[j]&&(s[c]&1))]+=f[i][k];
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++)ans+=f[(1<<n)-1][i];
		cout<<ans<<'\n';
	}
	else{
		cin>>(s+1);
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)if(!(s[i]&1)||!a[i])
			cout<<"0\n",exit(0);
		int ans=1;
		for(int i=2;i<=n;i++)ans=1ll*ans*i%mod;
		cout<<ans<<'\n';
	}
	return 0;
}