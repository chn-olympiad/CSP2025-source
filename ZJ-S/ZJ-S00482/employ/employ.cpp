#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505];
string s;
inline void Add(int &x,int y)
{
	x=x+y>=mod?x+y-mod:x+y;
}
inline int add(int x,int y)
{
	return x+y>=mod?x+y-mod:x+y;
}
namespace bf{
	int f[1<<18][18];
	void solve()
	{
		f[0][0]=1;
		for(int i=0;i<(1<<n);i++)
		{
			int c=__builtin_popcount(i);
			for(int j=0;j<=c;j++)
			{
				if(!f[i][j]) continue ;
				for(int k=0;k<n;k++)
				{
					if(i>>k&1) continue ;
					if(s[c+1]=='0'||(c-j)>=a[k+1]) Add(f[i|(1<<k)][j],f[i][j]);
					else Add(f[i|(1<<k)][j+1],f[i][j]);
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++) Add(ans,f[(1<<n)-1][i]);
		cout<<ans<<"\n";
	}
}
namespace mn{
	void solve()
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				cout<<0<<"\n";
				return ;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cout<<0<<"\n";
				return ;
			}
		}
		int ans=1;
		for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
		cout<<ans<<"\n";
	}
}
namespace m1{
	void solve()
	{
		int ans=1,ans1=1,cc=0;
		for(int i=1;i<=n;i++)
		{
			ans=1ll*ans*i%mod;
			if(s[i]=='1')
			{
				int cnt=0;
				for(int j=1;j<=n;j++)
				{
					if(a[j]<i) cnt++;
				}
				cnt-=cc;
				cc++;
				ans1=1ll*ans1*cnt%mod;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0') ans1=1ll*ans1*(n-cc)%mod,cc++;
		}
		Add(ans,mod-ans1);
		cout<<ans<<"\n";
	}
}
namespace s1{
	int f[2][505][505],pre[505],fac[505];
	void solve()
	{
		fac[0]=1;
		for(int i=1;i<=n;i++)
		{
			fac[i]=1ll*fac[i-1]*i%mod;
		}
		for(int i=1;i<=n;i++)
		{
			pre[a[i]]++;
		}
		for(int i=1;i<=n+1;i++)
		{
			pre[i]+=pre[i-1];
		}
		f[0][0][0]=1;
		for(int i=1;i<=n;i++)
		{
			memset(f[i&1],0,sizeof(f[i&1]));
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=n;k++)
				{
					int w=f[(i&1)^1][j][k];
					if(!w) continue ;
					//cerr<<i<<" "<<j<<" "<<k<<" "<<w<<"\n";
					Add(f[i&1][j][k],w);
					Add(f[i&1][j+1][k],1ll*w*(pre[j]-(j+k))%mod);
					Add(f[i&1][j][k+1],1ll*w*(pre[j]-(j+k))%mod);
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++)
		{
			for(int j=0;j+i<=n;j++)
			{
				int w=1ll*f[n&1][i][j]*fac[n-i-j]%mod;
				//cerr<<i<<" "<<j<<" "<<w<<"\n";
				if(j&1) Add(ans,mod-w);
				else Add(ans,w);
			}
		}
		cout<<ans<<"\n";
	}
};
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=18)
	{
		bf::solve();
		return 0;
	}
	if(m==n)
	{
		mn::solve();
		return 0;
	}
	if(m==1)
	{
		m1::solve();
		return 0;
	}
	s1::solve();
}