#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct A
{
	int a,b,c,d;
	int in()
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a>b&&a>c)
			d=1;
		if(b>a&&b>c)
			d=2;
		if(c>a&&c>=b)
			d=3;
		if(a==b&&a>c)
			d=1;
		if(b==c&&b>a)
			d=2;
		if(a==c&&a>b)
			d=1;
		return 0;
	}
}N[maxn];
bool e(const A x,const A y){return x.d<y.d;}
bool f(const A x,const A y){return x.a-max(x.b,x.c)>y.a-max(y.b,y.c);}
bool g(const A x,const A y){return x.b-max(x.a,x.c)>y.b-max(y.a,y.c);}
bool h(const A x,const A y){return x.c-max(x.a,x.b)>y.c-max(y.a,y.b);}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(N,0,sizeof(N));
		int n;
		long long ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			N[i].in();
		sort(N,N+n,e);
		int ab,bc;
		for(ab=0;ab<n&&N[ab].d==1;)
			ab++;
		for(bc=ab;bc<n&&N[bc].d==2;)
			bc++;
		bool flag=1;
		if(ab>n/2)
		{
			flag=0;
			for(int i=ab;i<n;i++)
				if(N[i].d==2)
					ans+=N[i].b;
				else if(N[i].d==3)
					ans+=N[i].c;
			sort(N,N+ab,f);
			for(int i=0;i<n/2;i++)
				ans+=N[i].a;
			for(int i=n/2;i<ab;i++)
				if(N[i].b>N[i].c)
					ans+=N[i].b;
				else
					ans+=N[i].c;
		}
		if(bc-ab>n/2)
		{
			flag=0;
			for(int i=0;i<ab;i++)
				ans+=N[i].a;
			for(int i=bc;i<n;i++)
				ans+=N[i].c;
			sort(N+ab,N+bc,g);
			for(int i=ab;i<ab+n/2;i++)
				ans+=N[i].b;
			for(int i=ab+n/2;i<bc;i++)
				if(N[i].a>N[i].c)
					ans+=N[i].a;
				else
					ans+=N[i].c;
		}
		if(n-bc>n/2)
		{
			flag=0;
			for(int i=0;i<bc;i++)
				if(N[i].d==1)
					ans+=N[i].a;
				else if(N[i].d==2)
					ans+=N[i].b;
			sort(N+bc,N+n,h);
			for(int i=bc;i<bc+n/2;i++)
				ans+=N[i].c;
			for(int i=bc+n/2;i<n;i++)
				if(N[i].a>N[i].b)
					ans+=N[i].a;
				else
					ans+=N[i].b;
		}
		if(flag)
		{
			for(int i=0;i<n;i++)
				if(N[i].d==1)
					ans+=N[i].a;
				else if(N[i].d==2)
					ans+=N[i].b;
				else
					ans+=N[i].c;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
