#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn=5e2+10,inf=1e18,mod=998244353;
string s;
int n,m,a[maxn],c[maxn],num[maxn],fac[maxn],flag=1,p[maxn],ans,f[110][110][110];
void add(int &x,int y)
{
	((x+=y)>=mod)?x-=mod:x;
}
int qpow(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1; 
	}
	return ret;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) a[i]=s[i-1]-'0',flag&=a[i];
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=n;i++) cin>>c[i],num[c[i]]++;
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(!a[i] or !c[i]) 
			{
				cout<<0<<"\n";
				return 0;
			}
		}
		cout<<fac[n]<<'\n';
		return 0;
	}
	if(n<=10)
	{
		for(int i=1;i<=n;i++) p[i]=i;
		do{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(!a[i] or cnt>=c[p[i]]) cnt++;
			}
			if(cnt<=n-m) ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<'\n';
		return 0;
	}
//	else
//	{
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=0;j<=min(i,n-m);j++)
//			{
//				for(int k=0;k<=j;k++)
//				{
//					if(!a[i]) 
//					{
//						
//					}
//					else
//					{
//						if(j) add(f[i][j][k],f[i-1][j-1][k]*C())
//					}
//				}
//			}
//		}
//	}
	return 0;
}
