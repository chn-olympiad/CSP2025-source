#include<bits/stdc++.h>
using namespace std;
int a[5005],ans,flag[5005],n;
int fact(int n)
{
	int ans=1;
	for(int i=1;i<=n;i++)
	ans*=n;
	return ans;
}
void dfs1(int pos,int end,int c)
{
	//dfs,O(n^2),+40;
	if(pos>end)
	{
		if(c<3)
		{
			return;
		}
		
		int k=0,sum=0,maxn=0;
		for(int i=1;i<=end;i++)
		{
			if(flag[i]==1)
			{
				k++;
				sum+=a[i];
				maxn=max(maxn,a[i]);
			}
			if(k==c)
			{
				break;
			}
		}
		if(sum>2*maxn)
		{
			ans=(ans+1)% 998244353;
		}
		return;
	}
	flag[pos]=0;
	dfs1(pos+1,end,c);
	flag[pos]=1;
	dfs1(pos+1,end,c+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int mm=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mm=max(mm,a[i]);
	}
	if(mm=1)
	{
		for(int i=3;i<=n;i++)
		ans+=(fact(n)/fact(n-i))/fact(i);
		cout<<ans;
		return 0;
	}
	if(n<=20)
	{
		dfs1(1,n,0);
	
	cout<<ans;
	return 0;
	}
}
