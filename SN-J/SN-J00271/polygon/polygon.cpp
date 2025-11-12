#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,q,w,b[5005],c[4];
void qqq(long long z,long long s)
{	
	if(s>=3)
	{
		for(int i=1;i<=s;i++)
		{
			q+=c[i];
			w=max(w,c[i]);
		}
		if(q>2*w)
		{
			ans++;
		}
		q=0;
		w=0;
	}
	if(s>=n)
	{
		return;
	}
	for(int i=z;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			c[s]=a[i];
			qqq(i,s+1);
			b[i]=0;
		}	
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	qqq(1,1);
	cout<<ans%998244353;
	return 0;
}
