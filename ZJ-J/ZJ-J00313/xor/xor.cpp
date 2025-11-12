#include<bits/stdc++.h>
using namespace std;
long long a[500001];
bool can;
long long none,one;
long long n,k;
long long dp[500001];
int back_up(int a,int b)
{
	return b^a;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	can=true;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0)none++;
		if(a[i]==1)one++;
		if(a[i]>1)can=false;
	}
	if(can)
	{
		if(k>1)cout<<0;
		if(k==1)cout<<one;
		if(k==0)
		{
			int ans=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]==1&&a[i+1]==1)
				{
					ans++;
					i+=1;
				}
			}
			cout<<ans+none;
		}
		return 0;
	}
	int ans=0;
	int num=0;
	int p=0;
	for(int i=0;i<n;i++)
	{
		num=num^a[i];
		if(num==k)
		{
			ans++;
			p=i;
			num=0;
			continue;
		}
		if(a[i]==k)
		{
			ans++;
			p=i;
			num=0;
			continue;
		}
		dp[i]=num;
		for(int j=p;j<i;j++)
		{
			if(back_up(dp[j],num)==k)
			{
				ans++;
				p=i;
				dp[j]=back_up(dp[j],num);
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
