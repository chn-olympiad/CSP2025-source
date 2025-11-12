#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e;
long long n=0;
long long y[20005];
long long z[20005];
struct node
{
	long long f;
	long long s;
	long long w;
}x[20000005];
bool cmp(node ff,node ss)
{
	return ff.w<ss.w;
}
int fi(long long h)
{
	int be=h;
	for(;;)
	{
		if(h==y[h])
		{
			break;
		}
		h=y[h];
	}
	y[be]=h;
	return h;
}
void he(long long ff,long long ss)
{
	y[ff]=y[ss];
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>a>>b>>c;
	for(long long i=1;i<=a;i=i+1)
	{
		y[i]=i;
	}
	for(long long i=1;i<=b;i=i+1)
	{
		cin>>x[i].f>>x[i].s>>x[i].w;
	}
	for(long long i=1;i<=c;i=i+1)
	{
		long long k;
		cin>>k;
		for(long long j=1;j<=a;j=j+1)
		{
			cin>>z[j];
		}
		long long hex=b+1,tax=b+(a*a+a)/2;
		for(long long j=1;j<=a;j=j+1)
		{
			for(long long o=i+1;o<=a;o=o+1)
			{
				b=b+1;
				x[b].f=j;
			    x[b].s=o;
			    x[b].w=z[j]+z[o]+k;
			}
		}
	}
	sort(x+1,x+b+1,cmp);
	for(long long i=1;i<=b;i=i+1)
	{
		int fb=fi(x[i].f),sb=fi(x[i].s);
		if(fb!=sb)
		{
			n=n+x[i].w;
			he(fb,sb);
		}
	}
	cout<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}