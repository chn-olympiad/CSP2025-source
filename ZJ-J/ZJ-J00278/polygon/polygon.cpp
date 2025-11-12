#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,sum,ans,d,a[5005],maxn=-2e9,cmp,res,ops;
int solve3()
{
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=j+1;k<=n;++k)
			{
				res=a[i]+a[j]+a[k];
				ops=max(a[i],max(a[j],a[k]));
				if(res>2*ops) ans++;
			}
}
int solve4()
{
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=j+1;k<=n;++k)
				for(int l=k+1;l<=n;++l)
				{
					res=a[i]+a[j]+a[k]+a[l];
					ops=max(max(a[i],a[l]),max(a[j],a[k]));
					if(res>2*ops) ans++;
				}
}
int solve5()
{
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=j+1;k<=n;++k)
				for(int l=k+1;l<=n;++l)
					for(int e=l+1;e<=n;++e)
					{
						res=a[i]+a[j]+a[k]+a[l]+a[e];
						ops=max(a[e],max(max(a[i],a[j]),max(a[k],a[l])));
						if(res>2*ops) ans++;
					}
}
int solve6()
{
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=j+1;k<=n;++k)
				for(int l=k+1;l<=n;++l)
					for(int e=l+1;e<=n;++e)
						for(int p=e+1;p<=n;++p)
						{
							res=a[i]+a[j]+a[k]+a[l]+a[e]+a[p];
							ops=max(max(a[e],a[p]),max(max(a[i],a[j]),max(a[k],a[l])));
							if(res>2*ops) ans++;
						}
}
int solve7()
{
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=j+1;k<=n;++k)
				for(int l=k+1;l<=n;++l)
					for(int e=l+1;e<=n;++e)
						for(int p=e+1;p<=n;++p)
							for(int q=p+1;q<=n;++q)
							{
								res=a[i]+a[j]+a[k]+a[l]+a[e]+a[p]+a[q];
								ops=max(a[q],max(max(a[e],a[p]),max(max(a[i],a[j]),max(a[k],a[l]))));
								if(res>2*ops) ans++;
							}
}
int solve8()
{
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=j+1;k<=n;++k)
				for(int l=k+1;l<=n;++l)
					for(int e=l+1;e<=n;++e)
						for(int p=e+1;p<=n;++p)
							for(int q=p+1;q<=n;++q)
								for(int t=q+1;t<=n;++t)
								{
									res=a[i]+a[j]+a[k]+a[l]+a[e]+a[p]+a[q]+a[t];
									ops=max(a[t],max(a[q],max(max(a[e],a[p]),max(max(a[i],a[j]),max(a[k],a[l])))));
									if(res>2*ops) ans++;
								}
}
int solve9()
{
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=j+1;k<=n;++k)
				for(int l=k+1;l<=n;++l)
					for(int e=l+1;e<=n;++e)
						for(int p=e+1;p<=n;++p)
							for(int q=p+1;q<=n;++q)
								for(int t=q+1;t<=n;++t)
									for(int z=t+1;z<=n;++z)
									{
										res=a[i]+a[j]+a[k]+a[l]+a[e]+a[p]+a[q]+a[t]+a[z];
										ops=max(a[z],max(a[t],max(a[q],max(max(a[e],a[p]),max(max(a[i],a[j]),max(a[k],a[l]))))));
										if(res>2*ops) ans++;
									}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<n;++i)
		if(a[i]!=a[i+1]) d=1;
	if(n<=3)
	{
		if(sum>2*maxn) ans++;
		return cout<<ans,0;
	}
	if(d==0)
	{
		cmp=1;
		cmp=n*(n-1)*(n-2)/6;
		ans=cmp;
		for(int i=4;i<=n;++i)
		{
			cmp=cmp*(n-i+1)/i;
			ans+=cmp;
		}
		return cout<<ans%mod,0;
	}
	if(n==4)
	{
		solve3();
		solve4();
		return cout<<ans%mod,0;
	}
	if(n==5)
	{
		solve3();
		solve4();
		solve5();
		return cout<<ans%mod,0;
	}
	if(n==6)
	{
		solve3();
		solve4();
		solve5();
		solve6();
		return cout<<ans%mod,0;
	}
	if(n==7)
	{
		solve3();
		solve4();
		solve5();
		solve6();
		solve7();
		return cout<<ans%mod,0;
	}
	if(n==8)
	{
		solve3();
		solve4();
		solve5();
		solve6();
		solve7();
		solve8();
		return cout<<ans%mod,0;
	}
	if(n==9)
	{
		solve3();
		solve4();
		solve5();
		solve6();
		solve7();
		solve8();
		solve9();
		return cout<<ans%mod,0;
	}
	else
	{
		cmp=1;
		cmp=n*(n-1)*(n-2)/6;
		ans=cmp;
		for(int i=4;i<=n;++i)
		{
			cmp=cmp*(n-i+1)/i;
			ans+=cmp;
		}
		return cout<<ans%mod,0;
	}
	return 0;
}
