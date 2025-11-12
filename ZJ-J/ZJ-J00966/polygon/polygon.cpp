#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000010];
bool vis[1000010];
int num = 0;
int mx = 0;
int sum = 0;
void dfs(int now,bool *vis)
{
	if(now == n+1)
	{
		mx = 0;
		num = 0;
		for(int i = 1;i<=n;i++)
		{
			if(vis[i] == 1)
			{
				num+=a[i];
				mx = max(mx,a[i]);
			}
		}
		if(num>(mx*2))
		{
			sum++;
		}
		return;
	}
	vis[now] = 1;
	dfs(now+1,vis);
	vis[now] = 0;
	dfs(now+1,vis);
}
int main(){
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}	
	dfs(1,vis);
	cout<<sum;
	return 0;
}

