#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans=0;
void dfs(int zhong_len,int now_len,int zhizheng,int sum,int max_now)
{
	if(now_len==zhong_len)
	{
		if(sum>max_now*2)
		{
			ans++;
			return;
		}
		else
		{
			return;
		}
	}
	if(zhizheng>n||now_len>zhong_len)
	{
		return;
	}
	for(int i=zhizheng+1;i<=n;i++)
	{
		dfs(zhong_len,now_len+1,zhizheng=i,sum+a[i],max(max_now,a[i]));
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
	for(int i=3;i<=n;i++)
	{
		dfs(i,0,0,0,-INT_MAX);
	}
	cout<<ans;
	return 0;
}
