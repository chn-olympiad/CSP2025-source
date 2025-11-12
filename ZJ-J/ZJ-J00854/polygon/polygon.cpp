#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],maxnt,sumt,maxn,sum,ans,l,r=5005;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);   cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxnt=max(maxnt,a[i]);
		sumt+=a[i];
	}
	if(n<=3)
	{
		if(sumt>2*maxnt)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			r=j+i;
			for(int k=j;k<=r;k++)
			{
				sum+=a[k];
				maxn=max(maxn,a[k]); 
			}
			if(sum>2*maxn)
			{
				
				ans++;
			}
		}
	}
	cout<<ans*(n-2);
	}
	return 0;
} 
