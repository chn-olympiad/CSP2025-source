#include <bits/stdc++.h>
using namespace std;
int n,m,s[510],ans,f=0;
struct q{
	int c;
	int id;
}a[510];
bool cmp(q x,q y)
{
	return x.c<y.c;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]==0)
			f=1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].c;	
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	if(m==n)
	{
		if(f==1)
			cout<<0;
		return 0;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i].c==0||s[a[i].id]==0)
			{
				continue;
			}
			else
			{
				int s=1;
				for(int j=2;j<=n-1;j++)
				{
					s*=j;
					s=s%998244353;
				}
				ans+=s;
				ans=ans%998244353;
			}
		}
		cout<<ans;
		return 0;
	}
	else
		cout<<0;
	return 0;
}
