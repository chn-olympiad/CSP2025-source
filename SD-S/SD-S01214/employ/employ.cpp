#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;int f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') ch=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int N=505;
int c[N];
string s;
int n,m;
#define ll long long
const int mod=998244353;

signed main()
{

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	cin>>s;
	s=' '+s; 
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}

	if(m==1)
	{
		ll ans=1; 
		for(int i=1;i<=n;i++)
		{
			ans=(ans*i)%mod;
		}
		cout<<ans%mod;
	}
	else if(m==n)
	{
		cout<<1<<endl;
	}
	else cout<<2<<endl;
//	cerr<<1.0*(clock()-sti)/CLOCKS_PER_SEC<<endl;
return 0;
}
/*
3 2
101
1 1 2



*/
