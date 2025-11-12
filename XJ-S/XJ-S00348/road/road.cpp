#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x;
	int y;
	int cost;
};
int mp[1005][1005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	 cin>>n>>m>>k;
	 vector<node> a(n+10);
	 int b [15][20005];
	 for(int i = 1; i <= m; i++){
	 	cin>>a[i].x>>a[i].y>>a[i].cost;
	 	mp[a[i].x][a[i].y] = a[i].cost;
	 }	
	for(int i = 1; i <= k; i++)
	{
		for(int k = 1; k <= n + 1; k++)
			cin>>b[i][k];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int sum = INT_MAX;
		for(int k = 1; k <= n; k++)
		{
			if(mp[i][k] != 0)
				sum = min(sum, mp[i][k]);
		}
		if(sum != INT_MAX)
		ans += sum;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
