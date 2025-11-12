#include<bits/stdc++.h>
using namespace std;
long long n,a[100010][5],T,ans,c[100010][5],b[100010],t;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(long long i=0;i<=n;++i)
			a[i][1]=a[i][2]=a[i][3]=b[i]=c[i][1]=c[i][2]=c[i][3]=0;
		ans=0;
		t=n/2;
		for(long long i=1;i<=n;++i)
		{
			scanf("%lld %lld %lld",a[i]+1,a[i]+2,a[i]+3);
			if(a[i][1]>=max(a[i][2],a[i][3]))
				ans+=a[i][1],c[++c[0][1]][1]=i;
			else if(a[i][2]>=max(a[i][1],a[i][3]))
				ans+=a[i][2],c[++c[0][2]][2]=i;
			else if(a[i][3]>=max(a[i][2],a[i][1]))
				ans+=a[i][3],c[++c[0][3]][3]=i;
		}
		if(c[0][1]>n/2)
		{
			t=c[0][1];
			for(long long i=1;i<=t;++i)
				b[i]=max(a[c[i][1]][2],a[c[i][1]][3])-a[c[i][1]][1];
		}
		else if(c[0][2]>n/2)
		{
			t=c[0][2];
			for(long long i=1;i<=t;++i)
				b[i]=max(a[c[i][2]][1],a[c[i][2]][3])-a[c[i][2]][2];
		}
		else if(c[0][3]>n/2)
		{
			t=c[0][3];
			for(long long i=1;i<=t;++i)
				b[i]=max(a[c[i][3]][2],a[c[i][3]][1])-a[c[i][3]][3];
		}
		sort(b+1,b+t+1,cmp);
		for(long long i=1;i<=t-n/2;++i)
			ans+=b[i];
		printf("%lld\n",ans);
	}
	return 0;
}
