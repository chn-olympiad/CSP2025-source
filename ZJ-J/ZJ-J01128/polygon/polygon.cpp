#include<bits/stdc++.h>
using namespace std;

int n,a[5010];
bool vis[5010];
long long ans;
const int md=998244353;

bool judge(int mx,int sum)
{
	return sum>2*mx;
}

void dfs(int pos,int mx,int sum,int depth)
{
	if(pos>n-2&&depth<=1)
	{
		return;
	}
	if(depth>=3)
	{
		ans+=(int)judge(mx,sum);
	}
	if(pos==n)
	{
		return;
	}
	for(int i=pos+1;i<=n;i++)
	{
		dfs(i,max(mx,a[i]),sum+a[i],depth+1);
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
	for(int i=1;i<=n-2;i++)
	{
		dfs(i,a[i],a[i],1);
	}
	cout<<ans%md;
}
