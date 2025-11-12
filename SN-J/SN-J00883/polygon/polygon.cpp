#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int flag[5005];
int n=0;
long long ans=0;
void dfs(int x,long long sum,long long maxx)
{
	if(sum>(2*maxx) and x>=3 and x<=n)
	{
		ans++;
		return;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
		
			if(flag[i]==0)
			{
				flag[i]=1;
				dfs(x++,sum+a[i],max(maxx,a[i]));
				flag[i]=0;
				
			}
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
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
