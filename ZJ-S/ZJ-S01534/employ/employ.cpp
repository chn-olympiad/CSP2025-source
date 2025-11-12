#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
bool flag[505];
int f[2][505][505];
int a[505],t[505],s[505],fac[505],C[505][505];
const int mod=998244353;
inline void Add(int &x,int y){((x+=y)>=mod)?(x-=mod):0;}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		flag[i]=c-'0';
	}
	for(int i=1;i<=n;i++)
		cin>>a[i],t[a[i]]++;
	for(int i=n;i>=0;i--)
		s[i]=s[i+1]+t[i];
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%mod;
	for(int i=0;i<=n;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	f[0][0][0]=1;
    int op=1;
	for(int i=1;i<=n;i++,op^=1)
	{
        for(int j=0;j<=i;j++)
            for(int k=0;k<=i;k++)
                f[op][j][k]=0;
		for(int j=0;j<i;j++)
			for(int k=0;k<i;k++)
			{
				if(flag[i])
				{
					int x=(n-s[j+1])-(i-1-k);
					for(int l=0;l<=t[j+1]&&l<=k;l++)
						Add(f[op][j+1][k-l],f[op^1][j][k]*C[t[j+1]][l]%mod*C[k][l]%mod*fac[l]%mod*x%mod);
					Add(f[op][j][k+1],f[op^1][j][k]);
				}
				else
				{
					int x=(n-s[j+1])-(i-1-k);
					for(int l=0;l<=t[j+1]&&l<=k;l++)
						Add(f[op][j+1][k-l],f[op^1][j][k]*C[t[j+1]][l]%mod*C[k][l]%mod*fac[l]%mod*x%mod);
					for(int l=0;l<=t[j+1]&&l<=k+1;l++)
						Add(f[op][j+1][k+1-l],f[op^1][j][k]*C[t[j+1]][l]%mod*C[k+1][l]%mod*fac[l]%mod);
				}
			}
		// for(int j=0;j<=i;j++)
		// 	for(int k=0;k<=i;k++)
		// 		cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<"\n";
	}
	int ans=0;
	for(int i=0;i<=n-m;i++)
		Add(ans,f[op^1][i][s[i+1]]*fac[s[i+1]]%mod);
	cout<<ans<<"\n";
}
//counting,/kx
//end at 17:42