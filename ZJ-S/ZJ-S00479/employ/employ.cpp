#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define G(i,l,r) for(int i=(l),i##end=(r);i>=i##end;--i)
#define ep emplace_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define ll long long
using namespace std;
constexpr int N=109,mod=998244353;
int f[N][N][N];
int g[N][N][N];
int tmp[N][N][N];
int s[509],c[509];
int C[509][509];
inline void upd(int &a,ll b)
{
	a=(a+b)%mod;
}
void reduce(int &A)
{
	if(A>=mod)A-=mod;
}
int ans[509];
int sc[509],fac[509];
int n,m;
namespace solve1
{
	constexpr int N=509;
	int f[N][N];
	int g[N][N];
	int tmp[N][N];
	void main()
	{
		f[0][c[0]]=1;
		int s0=0;
		F(i,1,n)
		{
			F(d,0,n)F(k,0,n)g[d][k]=f[d][k],f[d][k]=0;
			if(s[i]==0)s0++;
			if(s[i]==1)
			{
				F(d,0,i)F(k,0,n)tmp[d][k]=0;
				F(d,0,i)F(k,1,n)
				{
					upd(tmp[d][k-1],(ll)g[d][k]*k);
				}
				F(d,0,i)F(k,0,n)
				{
					int l=sc[d+1]+k-n+i-s0;
					F(s,0,min(l,c[d+1]))
					{	
						int tt=(ll)C[c[d+1]][s]%mod*C[l][s]%mod*fac[s]%mod;
						upd(f[d+1][k+c[d+1]-s],(ll)tmp[d][k]*tt);
					}
				}
			}
			else
			{
				F(d,0,i)F(k,0,n)tmp[d][k]=0;
				F(d,0,i)F(k,0,n)
				{
					int l=sc[d+1]+k-n+i-s0;
					F(s,0,min(l,c[d+1]))
					{
						int tt=(ll)C[c[d+1]][s]*C[l][s]%mod*fac[s]%mod;
						upd(f[d+1][k+c[d+1]-s],(ll)g[d][k]*tt);
					}
				}
			}
		}
		int sk=fac[s0];
		F(d,0,n)F(k,0,n)if(f[d][k])
		{
			int l=sc[d+1]+k-s0;
			upd(ans[0],(ll)f[d][k]*C[sc[d+1]][l]%mod*fac[l]);
		}
		F(i,0,n)ans[i]=(ll)ans[i]*sk%mod;
		int out=1;
		F(i,1,n)out=(ll)out*i%mod;
		F(i,0,m-1)reduce(out+=mod-ans[i]);
		cout<<out<<'\n';	
	}
}
signed main()
{
	assert(freopen("employ.in","r",stdin));
	assert(freopen("employ.out","w",stdout));
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	string st;
	cin>>st;
	F(i,1,n)s[i]=st[i-1]-'0';
	fac[0]=1;
	F(i,1,n)fac[i]=(ll)fac[i-1]*i%mod;
	F(i,0,n)
	{
		C[i][0]=1;
		F(j,1,i)reduce(C[i][j]=C[i-1][j]+C[i-1][j-1]);
	}
	F(i,1,n)
	{
		int x;
		cin>>x;
		c[x]++;
	}
	F(i,0,n)sc[i]=c[i];
	G(i,n,1)sc[i]+=sc[i+1];
	f[0][c[0]][0]=1;
	if(m==1)
	{
		solve1::main();
		return 0;
	}
	int s0=0;
	F(i,1,n)
	{
		F(d,0,n)F(k,0,n)F(j,0,i)g[d][k][j]=f[d][k][j],f[d][k][j]=0;
		if(s[i]==0)s0++;
		if(s[i]==1)
		{
			F(d,0,i)F(k,0,n)F(j,0,i)tmp[d][k][j]=0;
			F(d,0,i)F(k,1,n)F(j,0,i)
			{
				upd(tmp[d][k-1][j],(ll)g[d][k][j]*k);
			}
			F(d,0,i)F(k,0,n)
			{
				int l=sc[d+1]+k-n+i-s0;
				F(s,0,min(l,c[d+1]))
				{
					int tt=(ll)C[c[d+1]][s]%mod*C[l][s]%mod*fac[s]%mod;
					F(j,0,i)if(tmp[d][k][j])
					{
						upd(f[d+1][k+c[d+1]-s][j],(ll)tmp[d][k][j]*tt);
					}
				}
			}
			F(d,0,i)F(k,0,n)F(j,0,i)reduce(f[d][k][j+1]+=g[d][k][j]);
		}
		else
		{
			F(d,0,i)F(k,0,n)F(j,0,i)tmp[d][k][j]=0;
			F(d,0,i)F(k,0,n)
			{
				int l=sc[d+1]+k-n+i-s0;
				F(s,0,min(l,c[d+1]))
				{
					int tt=(ll)C[c[d+1]][s]*C[l][s]%mod*fac[s]%mod;
					F(j,0,i)upd(f[d+1][k+c[d+1]-s][j],(ll)g[d][k][j]*tt);
				}
			}
		}
	}
	int sk=fac[s0];
	F(d,0,n)F(k,0,n)F(j,0,n)if(f[d][k][j])
	{
		int l=sc[d+1]+k-s0;
		upd(ans[j],(ll)f[d][k][j]*C[sc[d+1]][l]%mod*fac[l]);
	}
	F(i,0,n)ans[i]=(ll)ans[i]*sk%mod;
	int out=0;
	F(i,m,n)reduce(out+=ans[i]);
	cout<<out<<'\n';
	return 0;
}
