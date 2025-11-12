#include<bits/stdc++.h>
using namespace std;
long long rd()
{
	long long k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
long long la,lb,lc,a[100005],b[100005],c[100005];
long long sum,T,n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=rd();
	while(T--)
	{
		n=rd();
		la=lb=lc=sum=0;
		for(int i=1;i<=n;i++)
		{
			long long x=rd(),y=rd(),z=rd();
			sum+=max(x,max(y,z));
			long long k=max(x,max(y,z));
			if(x==k)
			{
				a[++la]=max(y,z)-x;
			}
			else if(y==k)
			{
				b[++lb]=max(x,z)-y;
			}
			else if(z==k)
			{
				c[++lc]=max(x,y)-z;
			}
		}
		if(la>n/2)
		{
			sort(a+1,a+la+1);
			for(int i=n/2+1;i<=la;i++)
			{
				sum+=a[i];
			}
		}
		if(lb>n/2)
		{
			sort(b+1,b+lb+1);
			for(int i=n/2+1;i<=lb;i++)
			{
				sum+=b[i];
			}
		}
		if(lc>n/2)
		{
			sort(c+1,c+lc+1);
			for(int i=n/2+1;i<=lc;i++)
			{
				sum+=c[i];
			}
		}
		cout<<sum<<"\n";
	}
}
