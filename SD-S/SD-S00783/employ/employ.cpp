#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,mod=998244353;
int n,m,c[505],f[(1<<18)+5][20];
//f_i_j means passed i ppl,status j
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	f[0][0]=1;
	if(n<=18){
		for(int i=0;i<(1<<n);i++){
			int p=__builtin_popcount(i)+1;//considering position p
			for(int k=0;k<=p-1;k++){//alr k ppl
				for(int j=1;j<=n;j++){//last one is j
					if((i>>j-1)%2==1) continue;
					int ch=(s[p]=='1'&&c[j]>p-1-k);
	//				cout<<i<<' '<<k<<' '<<ch<<' '<<j<<'\n';
					(f[i+(1<<j-1)][k+ch]+=f[i][k])%=mod;
				}
			}	
		} 
		int ans=0;
		for(int i=m;i<=n;i++) ans=(ans+f[(1<<n)-1][i])%mod;
		cout<<ans;
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++) ans=ans*i%mod;
	cout<<ans;
	return 0;
}

