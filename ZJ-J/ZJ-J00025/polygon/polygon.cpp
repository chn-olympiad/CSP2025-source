#include<bits/stdc++.h>
using namespace std;
int n,a[5010],cnt,su,mmx=-1e9;
void dfs(int x,int sum,int mx,int m)
{
	if(m>=3 && sum>mx*2)
	{
		cnt++;
		cnt%=998244353;
		if(x>n)    return ;
		dfs(x+1,sum+a[x],max(mx,a[x]),m+1);
		return ;
	}
	if(x>n)    return ;
	dfs(x+1,sum,mx,m);
	dfs(x+1,sum+a[x],max(mx,a[x]),m+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
		su+=a[i];
		mmx = max(mmx,a[i]);
	}
	if(n<=3)
	{
		if(su>mmx*2)    cout << 1;
		else    cout << 0;
	}
	dfs(1,0,-1e9,0);
	printf("%d",cnt);
	return 0;
}
