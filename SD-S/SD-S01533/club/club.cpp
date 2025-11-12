#include<bits/stdc++.h>
using namespace std;
#define N 100010

long long n;
struct node{
	int id;
	long long x[4];
	long long del[4];
	int M1,M2,M3;
}a[N];

long long read()
{
	char str;
	long long f=1;
	str=getchar();
	while(str<'0'||str>'9')
	{
		str=getchar();
		if(str=='-')
		{
			f=-1;
		}
	}
	long long s=0;
	while(str>='0'&&str<='9')
	{
		s=s*10+str-'0';
		str=getchar();
	}
	return f*s;
}
long long ans;

long long b[4];
long long TT;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&TT);
	while(TT--)
	{
		b[0]=b[1]=b[2]=b[3]=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			long long x,y,z;
			x=read();
			y=read();
			z=read();
//			printf("%lld %lld %lld\n",x,y,z);
			a[i].x[1]=x;a[i].del[1]=max(y,z)-x;
			a[i].x[2]=y;a[i].del[2]=max(x,z)-y;
			a[i].x[3]=z;a[i].del[3]=max(x,y)-z;
			if(max(x,max(y,z))==x)a[i].M1=1;
			if(max(x,max(y,z))==y)a[i].M1=2;
			if(max(x,max(y,z))==z)a[i].M1=3;
			if(max(x,max(y,z))!=x&&min(x,min(y,z))!=x)a[i].M2=1;
			if(max(x,max(y,z))!=y&&min(x,min(y,z))!=y)a[i].M2=2;
			if(max(x,max(y,z))!=z&&min(x,min(y,z))!=z)a[i].M2=3;
			a[i].id=i;
		}
//		for(int i=1;i<=n;i++)
//		{
//			printf("%lld %lld %lld ",a[i].x[1],a[i].x[2],a[i].x[3]);
//			printf("%lld %lld %lld ",a[i].del[1],a[i].del[2],a[i].del[3]);
//			printf("%lld %lld %lld ",a[i].x[1],a[i].x[2],a[i].x[3]);
//			printf("%lld %lld %lld ",a[i].M1,a[i].M2,a[i].M3);
//			printf("%lld\n",a[i].id);
//		}
		ans=0;
		priority_queue<pair<long long,long long> >Q[4];
		for(int i=1;i<=n;i++)
		{
			if(b[a[i].M1]==n/2)
			{
//				printf("5g");
				int x=Q[a[i].M1].top().first;
				int ID=Q[a[i].M1].top().second;
				if(x>a[i].del[a[i].M1])
				{
					Q[a[i].M1].pop();
					Q[a[i].M1].push(make_pair(a[i].del[a[i].M1],a[i].id));
					Q[a[ID].M2].push(make_pair(a[ID].del[a[ID].M2],ID));
					b[a[ID].M2]++;
					ans=ans+x+a[i].x[a[i].M1];
				}
				else
				{
					Q[a[i].M2].push(make_pair(a[i].del[a[i].M2],a[i].id));
					b[a[i].M2]++;
					ans=ans+a[i].x[a[i].M2];
				}
			}
			else
			{
				Q[a[i].M1].push(make_pair(a[i].del[a[i].M1],a[i].id));
				b[a[i].M1]++;
				ans=ans+a[i].x[a[i].M1];
			}
//			printf("	%lld\n",ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

