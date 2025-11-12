#include<bits/stdc++.h>
using namespace std;
long long m,n,ans=0;
long long s[501];
long long c[501];
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(c[j]<c[i])
			{
				long long l;
				l=s[i];
				s[i]=s[j];
				s[j]=l;
			}
		}
	}
	long long t=0;
	for(int i=1;i<=n;i++)
	{
		if(ans<m)
		{
			if(s[i]>=t)
			{
				ans++;
			}
			t++;
		}
		else
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
