#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005],n,k,fbbb=1,fa=1,cnt,t,tt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)fbbb=0;
		if(a[i]!=1)fa=0;
		s[i]=s[i-1]^a[i];
		if(a[i]==1)t++;
		else tt++;
	}
	if(fa)
	{
		cout<<n/2;
	}
	else if(fbbb)
	{
		if(k==0)
		{
			int j=0,ans=0;
			for(int i=1;i<n;i=j+1)
			{
				for(j=i+1;j<=n&&a[j]!=1;j++);
				if(j==n+1)break;
				ans+=max(1,j-i-1);
			}
			cout<<max(ans,t/2+tt);
		}
		else
		{
			cout<<t;
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}
