#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],f[270000][20],ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)	cin>>c[i];
	f[0][0]=1;
	for(int o=1;o<(1<<n);o++){
		int p=0;
		for(int k=0;k<n;k++)	if((o>>k)&1)	p++;
		for(int j=0;j<p;j++){
			for(int k=1;k<=n;k++){
				if((o>>k-1)&1){
					int z=o^(1<<k-1);
					if(c[k]<=j||s[p-1]=='0')	f[o][j+1]=(f[o][j+1]+f[z][j])%mod;
					else	f[o][j]=(f[o][j]+f[z][j])%mod;
				}
			}
		}
	}
	for(int i=0;i<=n-m;i++)	ans=(ans+f[(1<<n)-1][i])%mod;
	cout<<ans;
	return 0;
}
