#include<bits/stdc++.h>
using namespace std;
const long long N=100012;
long long t,n,js1,js2,js3,k,ans,tot;
struct node
{
	long long a,b,c;
	bool operator<(node x)const
	{
		return b>x.b;
	}
}st1[N],st2[N],st3[N],sp;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		js1=js2=js3=ans=tot=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%lld%lld%lld",&sp.a,&sp.b,&sp.c);
			if(sp.a>=sp.b)
			{
				if(sp.b>=sp.c)
				{
					++js1;
					sp.b=sp.a-sp.b;
					sp.c=1;
					st1[js1]=sp;
				}
				else if(sp.a>=sp.c)
				{
					++js1;
					swap(sp.b,sp.c);
					sp.b=sp.a-sp.b;
					sp.c=1;
					st1[js1]=sp;
				}
				else
				{
					++js3;
					k=sp.b;
					sp.b=sp.a;
					sp.a=sp.c;
					sp.c=k;
					sp.b=sp.a-sp.b;
					sp.c=1;
					st3[js3]=sp;
				}
			}
			else if(sp.a>=sp.c)
			{
				swap(sp.b,sp.a);
				sp.b=sp.a-sp.b;
				sp.c=1;
				++js2;
				st2[js2]=sp;
			}
			else if(sp.b>=sp.c)
			{
				++js2;
				k=sp.b;
				sp.b=sp.c;
				sp.c=sp.a;
				sp.a=k;
				sp.b=sp.a-sp.b;
				sp.c=1;
				st2[js2]=sp;
			}
			else
			{
				swap(sp.a,sp.c);
				sp.b=sp.a-sp.b;
				sp.c=1;
				++js3;
				st3[js3]=sp;
			}
		}
		for(int i=1;i<=js1;++i)
		{
			ans+=st1[i].a;
		}
		for(int i=1;i<=js2;++i)
		{
			ans+=st2[i].a;
		}
		for(int i=1;i<=js3;++i)
		{
			ans+=st3[i].a;
		}
		if(js1>js2)
		{
			if(js1>js3)
			{
				if(js1>(n>>1))
				{
					sort(st1+1,st1+js1+1);
					for(int i=(n>>1)+1;i<=js1;++i)
					{
						ans-=st1[i].b;
					}
				}
			}
			else
			{
				if(js3>(n>>1))
				{
					sort(st3+1,st3+js3+1);
					for(int i=(n>>1)+1;i<=js3;++i)
					{
						ans-=st3[i].b;
					}
				}
			}
		}
		else if(js2>js3)
		{
			if(js2>(n>>1))
			{
				sort(st2+1,st2+js2+1);
				for(int i=(n>>1)+1;i<=js2;++i)
				{
					ans-=st2[i].b;
				}
			}
		}
		else
		{
			if(js3>(n>>1))
			{
				sort(st3+1,st3+js3+1);
				for(int i=(n>>1)+1;i<=js3;++i)
				{
					ans-=st3[i].b;
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}