#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100001][4],sum;
void dfs(int u,int x,int y,int z,long long sum1,long long sum2,long long sum3)
{
	if(u > n)
	{
		sum = max(sum,sum1+sum2+sum3);
		return ;
	}
	if(x < n/2)
	{
		dfs(u+1,x+1,y,z,sum1 + a[u][1],sum2,sum3);
	}
	if(y < n/2)
	{
		dfs(u+1,x,y+1,z,sum1,sum2 + a[u][2],sum3);
	}
	if(z < n/2)
	{
		dfs(u+1,x,y,z+1,sum1,sum2,sum3 + a[u][3]);
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		sum = 0;
		dfs(1,0,0,0,0,0,0);
		cout << sum << endl;
	}
	return 0;
 } 