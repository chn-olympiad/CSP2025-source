#include<bits/stdc++.h>
using namespace std;
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int n,m;
string s;
int c[505];	
const int MOD=998244353;
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
	}
	bool flagA=true;
	for(int i=1;i<=n;i++)
	{
		ans=ans*i%MOD;
	}
	cout<<ans<<endl;
	return 0;
}
