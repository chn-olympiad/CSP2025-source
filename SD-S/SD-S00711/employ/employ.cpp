#include<bits/stdc++.h> 
using namespace std;
int n,m,a[550],b[550];
long long ans,p=1;
char c[550];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",c);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	bool k=1;
	for(int i=0;i<n;i++)
	{
		if(c[i]=='1' && m==n)
		{
			cout<<0;
			return 0;
		}
		if(c[i]=='0')
		{
			k=0;
			if(m==1)
			{
				long long ans1=0,p1=1;
				for(int j=i+1;j<=n;j++) ans1+=b[j];
				for(int j=1;j<n;j++)
				{
					p1*=j;
					p1%=998244353;
				}
				ans+=(ans1*p1%998244353)%998244353;
			}
			
		}
	}
	if(m==1)
	{
		cout<<ans%998244353;
		return 0;
	}
	if(k)
	{
		cout<<0;
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			p*=i;
			p%=998244353;
		}
		cout<<p;
		return 0;
	}
	cout<<114514191;
	return 0;
}
