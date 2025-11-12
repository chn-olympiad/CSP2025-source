#include<bits/stdc++.h>
#define maxn 510001
#define int long long
using namespace std;
const int Mod=998244353;
int reduce(int x){return x-(x>=Mod)*Mod;}

int n,m,t[1010],f[2][606][606],fac[606],ans[606];
char s[1010];
void solve(){
	cin>>n>>m>>s;
	fac[0]=1;
	for(int i=1,x;i<=n;i++){
		fac[i]=fac[i-1]*i%Mod;
		cin>>x;
		t[x]++;
	}
	for(int i=1;i<=n;i++) t[i]+=t[i-1];
	f[0][0][0]=1;
	int op=0;
	for(int i=1;i<=n;i++){
		op^=1;
		if(s[i-1]=='0'){
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++){
					if(!j) f[op][j][k]=0;
					else f[op][j][k]=f[op^1][j-1][k];
				}
			}
			continue;
		}
		for(int j=0;j<=i;j++){
			for(int k=0;k<=i;k++){
				f[op][j][k]=f[op^1][j][k];
				if(j&&k) f[op][j][k]=(f[op][j][k]+f[op^1][j-1][k-1]*(t[j-1]-k+1))%Mod;
				if(k) f[op][j][k]=(f[op][j][k]+f[op^1][j][k-1]*(Mod-(t[j]-k+1)))%Mod;
			}
		}
	}
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) ans[i]=(ans[i]+f[op][i][j]*fac[n-j])%Mod;
	int sum=0;
	for(int i=0;i<=n-m;i++) sum=reduce(sum+ans[i]);
	sum=reduce(sum%Mod+Mod);
	cout<<sum<<'\n';
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
//	init();
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
