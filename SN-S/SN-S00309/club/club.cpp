#include<bits/stdc++.h>
using namespace std;
struct r
{
	long long a1,a2,a3;
};
long long n,ans=0;
bool f=1;
r a[100001];
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].a2!=0&&a[i].a3!=0)
		{
			f=0;
		}
	}
	if(f==1)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[i].a1<a[j].a1)
				{
					long long l;
					l=a[i].a1;
					a[i].a1=a[j].a1;
					a[j].a1=l;
				}
			}
		}
		for(int i=1;i<=(n/2);i++)
		{
			ans+=a[i].a1;
		}
		cout<<ans;
	}
	
	return 0;
}
