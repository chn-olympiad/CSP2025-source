#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
#define endl "\n"
using namespace std;
const int N=505,M=(1<<18),mod=998244353;
int n,m,d[N],c[N],f[M][19],res;
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='1')d[i]=1;
		else d[i]=0;
	}f[0][0]=1;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<(1<<n);i++){
		int num=0;
		for(int k=1;k<=n;k++)
		if(i>>(k-1)&1)num++;
		for(int k=0;k<=num;k++){
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1)))continue;
				if(!d[num+1]||k>=c[j])(f[i|(1<<(j-1))][k+1]+=f[i][k])%=mod;
				else (f[i|(1<<(j-1))][k]+=f[i][k])%=mod;
			}
		}
	}
	for(int i=0;i<=n-m;i++){
		res=(res+f[(1<<n)-1][i])%mod;
	}
	cout<<res;
	return 0;
}

