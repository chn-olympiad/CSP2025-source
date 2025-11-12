#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll sum=0,l=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')l=-1;c=getchar();}
	while(isdigit(c)){sum=(sum<<1)+(sum<<3)+(c^48);c=getchar();}
	return sum*l;
}
const ll mod=998244353;
ll dp[2][510][510],sm[510],qz1[510],qz2[510],qz[510],C[510][510];
ll qp(ll a,ll b)
{
	ll c=1;
	while(b)
	{
		if(b&1)c=c*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return c;
}
void upd(ll &x,ll y)
{
	x+=y;
	if(x>=mod)x-=mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll a=read(),b=read();
	for(ll i=qz1[0]=1;i<=a;i++)qz1[i]=qz1[i-1]*i%mod;
	qz2[a]=qp(qz1[a],mod-2);
	for(ll i=a;i>=1;i--)qz2[i-1]=qz2[i]*i%mod;
	for(ll i=0;i<=a;i++)for(ll j=0;j<=i;j++)C[i][j]=qz1[i]*qz2[j]%mod*qz2[i-j]%mod;
	string s;
	cin>>s;
	for(ll i=1;i<=a;i++)sm[read()]++;
	qz[0]=sm[0];
	for(ll i=1;i<=a;i++)qz[i]=qz[i-1]+sm[i];
	ll nw=0;
	dp[0][0][sm[0]]=1;
	for(ll i=0;i<a;i++)
	{
		nw^=1;
		for(ll j=0;j<=i+1;j++)for(ll k=0;k<=qz[j];k++)dp[nw][j][k]=0;
		for(ll j=0;j<=i;j++)
		{
			for(ll k=max(qz[j]-i,0ll);k<=min(qz[j],a-i);k++)
			{
				if(s[i]=='1')
				{
					if(k<a-i)upd(dp[nw][j][k],dp[nw^1][j][k]);
					if(k)
					{
						ll mx=i-(qz[j]-k);
						for(ll l=0;l<=min(mx,sm[j+1]);l++)
						{
							upd(dp[nw][j+1][k+sm[j+1]-l-1],dp[nw^1][j][k]*k%mod*C[mx][l]%mod*C[sm[j+1]][l]%mod*qz1[l]%mod);
						}
					}
				}
				else
				{
					if(k<a-i)
					{
						ll mx=i+1-(qz[j]-k);
						for(ll l=0;l<=min(mx,sm[j+1]);l++)
						{
							upd(dp[nw][j+1][k+sm[j+1]-l],dp[nw^1][j][k]*C[mx][l]%mod*C[sm[j+1]][l]%mod*qz1[l]%mod);
						}
					}
					if(k)
					{
						ll mx=i-(qz[j]-k);
						for(ll l=0;l<=min(mx,sm[j+1]);l++)
						{
							upd(dp[nw][j+1][k+sm[j+1]-l-1],dp[nw^1][j][k]*k%mod*C[mx][l]%mod*C[sm[j+1]][l]%mod*qz1[l]%mod);
						}
					}
				}
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<=a-b;i++)upd(ans,dp[nw][i][0]*qz1[a-qz[i]]%mod);
	cout<<ans;
	return 0;
}
