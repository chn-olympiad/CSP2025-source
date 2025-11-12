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
//n-->200
int a[205],b[205],c[205];//dp[205][205][205];
int dpa[205],dpb[205],dpc[205];
int anss;
//int p[203];
void dfs(int n,int pos,int ap,int bp,int cp,int kans)
{
	if(pos-1==n)
	{
		anss=max(anss,kans);
		return ;
	}
	if(ap<n/2)
	{
//		p[pos]=1;
		dfs(n,pos+1,ap+1,bp,cp,kans+a[pos]);
	}
	if(bp<n/2)
	{
//		p[pos]=2;
		dfs(n,pos+1,ap,bp+1,cp,kans+b[pos]);
	}
	if(cp<n/2)
	{
//		p[pos]=3;
		dfs(n,pos+1,ap,bp,cp+1,kans+c[pos]);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	T=read();
	while(T--)
	{
		int n;
		n=read();
		if(n<=204)
		{
			bool km=0;
			for(int i=1;i<=n;i++)
			{
				a[i]=read();
				b[i]=read();
				c[i]=read();
				if(c[i]||b[i])
				{
					km=1;
				}
			}
			int ans=0;
			if(!km)
			{
				sort(a+1,a+1+n);
				for(int i=n;i>=n/2;i--)
				{
					ans+=a[i];
				}
			}
			else
			{
				anss=0;
				dfs(n,1,0,0,0,0);
				ans=anss;
			}
			cout<<ans<<'\n'; 
		}
	}
	
	cout<<endl;
	return 0;
 } 
 /*
 3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0
 */
