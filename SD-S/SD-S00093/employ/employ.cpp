#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull fpow(ull a,ull b);

const ull N=502,Mod=998244353;
ull n,m,c[N],fac[N],inv[N];
string s;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	fac[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(!c[i])
			m++;
		fac[i]=fac[i-1]*i%Mod;
	}
	/*inv[n]=fpow(fac[n],Mod-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%Mod;*/
	cout<<(n>=m?fac[n]:0);
	return 0;
}
ull fpow(ull a,ull b)
{
	ull res=1;
	while(b)
	{
		if(b&1)
			(res*=a)%=Mod;
		(a*=a)%=Mod;
		b>>=1;
	}
	return res;
}
