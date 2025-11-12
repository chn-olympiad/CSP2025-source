#include<bits/stdc++.h>
using namespace std;
int t,n,j[4];
long long s=0;
struct vis{//wish
	int w[4],ma,cma;
}a[100001];
inline int read()
{
	char ch;
	int sz=0,f=1;
	ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		sz=sz*10+int(ch-'0');
		ch=getchar();
	}
	return sz*f;
}
bool cmp(vis x,vis y)
{
	if(x.ma!=y.ma)return x.ma<=y.ma;
	else 
	{
		if(x.ma==1)
		{
			if(x.w[x.ma]==x.w[2]||x.w[x.ma]==x.w[3])
			{
				return 1;
			}
			else if(y.w[y.ma]==y.w[2]||y.w[y.ma]==y.w[3])
			{
				return 0;
			}
			else return x.w[x.ma]-x.w[x.cma]<=y.w[y.ma]-y.w[y.cma];
		}
		else if(x.ma==2)
		{
			if(x.w[x.ma]==x.w[1]||x.w[x.ma]==x.w[3])
			{
				return 1;
			}
			else if(y.w[y.ma]==y.w[1]||y.w[y.ma]==y.w[3])
			{
				return 0;
			}
			else return x.w[x.ma]-x.w[x.cma]<=y.w[y.ma]-y.w[y.cma];
		}
		else
		{
			if(x.w[x.ma]==x.w[2]||x.w[x.ma]==x.w[1])
			{
				return 1;
			}
			else if(y.w[y.ma]==y.w[2]||y.w[y.ma]==y.w[1])
			{
				return 0;
			}
			else return x.w[x.ma]-x.w[x.cma]<=y.w[y.ma]-y.w[y.cma];
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		j[1]=0;
		j[2]=0;
		j[3]=0;
		s=0;
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i].w[1]=read();
			a[i].w[2]=read();
			a[i].w[3]=read();
			if(a[i].w[1]>a[i].w[2])//1>2
			{
				if(a[i].w[2]>a[i].w[3])//1>2>3
				{
					a[i].ma=1;
					a[i].cma=2;
					j[1]++;
					s+=a[i].w[1];
				}
				else if(a[i].w[3]>a[i].w[1])//3>1>2
				{
					a[i].ma=3;
					a[i].cma=1;
					j[3]++;
					s+=a[i].w[3];
				}
				else//1>3>2
				{
					a[i].ma=1;
					a[i].cma=3;
					j[1]++;
					s+=a[i].w[1];
				}
			}
			else//2>1
			{
				if(a[i].w[1]>a[i].w[3])//2>1>3
				{
					a[i].ma=2;
					a[i].cma=1;
					j[2]++;
					s+=a[i].w[2];
				}
				else if(a[i].w[3]>a[i].w[2])//3>2>1
				{
					a[i].ma=3;
					a[i].cma=2;
					j[3]++;
					s+=a[i].w[3];
				}
				else//2>3>1
				{
					a[i].ma=2;
					a[i].cma=3;
					j[2]++;
					s+=a[i].w[2];
				}
			}
		}
		if((j[1]<=n/2&&j[2]<=n/2&&j[3]<=n/2))
		{
			printf("%lld\n",s);
			continue;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;!(j[1]<=n/2&&j[2]<=n/2&&j[3]<=n/2);i++)
		{
			if(j[a[i].ma]>n/2)
			{
				s-=(a[i].w[a[i].ma]-a[i].w[a[i].cma]);
				j[a[i].ma]--;
			}
		}
		printf("%lld\n",s);
	}
	return 0;
}
/*
1
4
8 9 8 
7 5 7 
5 5 0 
2 3 0 

*/
//made by ljy.put me on mihuoxingweidashang.
//may TLE.
