#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20;
const int S=(1<<18)+5;
const int Mod=998244353;
int n,m,s[N],c[N],ans;
int f[S][N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char x;cin>>x;
		s[i]=x-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	f[0][0]=1;
	for(int i=0;i<(1<<n)-1;i++)
	{
		int t=i,p=0;
		while(t)
		{
			if(t&1)p++;
			t>>=1;
		}
		for(int j=0;j<=p;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(i&(1<<(k-1)))continue;
				f[i|(1<<(k-1))][j+((p-j<c[k])&&s[p+1])]+=f[i][j];
				f[i|(1<<(k-1))][j+((p-j<c[k])&&s[p+1])]%=Mod;
			}
		}
	}
	for(int i=m;i<=n;i++)
	{
		ans+=f[(1<<n)-1][i];ans%=Mod;
	}
	cout<<ans<<endl;
	return 0;
}

