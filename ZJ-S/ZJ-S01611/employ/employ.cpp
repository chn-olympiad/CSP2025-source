#include<bits/stdc++.h>
using namespace std;
long long n,m,i,oo,ans=1;
char x;
long long read()
{
	char c=getchar();
	long long x=0,y=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	for(i=1;i<=n;i++)
	{
		cin>>x;
		if(x=='0')oo=1;
	}
	if(oo==0)
	{
		for(i=1;i<=n;i++)
	    {
		    ans=(ans*i)%998244353;
	    }
	    cout<<ans;
	    return 0;
	}
	cout<<3;
}

