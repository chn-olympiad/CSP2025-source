#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int read()
{
	char c;
	int x=0,f=1;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
long long md=998244353;
//long long jc(long long k)
//{
//	long long ans=1;
//	for(long long i=1;i<=k;i++)
//	{
//		ans=ans*i%md;
//	}
//	return ans;
//}
int main()//20pts
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	n=read();m=read();
	int a;
	a=read();
	int nk=n;
	for(int i=1,c;i<=nk;i++)
	{
		c=read();
	}
	long long ans=1;
	if(m>n)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		ans=ans*i%998244353;
		ans%=998244353;
	} 
	cout<<ans;
	cout<<endl;
	return 0;
 } 
