#include<bits/stdc++.h>
using namespace std;
int x[100005][5];
int n;
int vis[5],ans=0,cnt;
void dfs(int temp,int jishu)
{
	if(temp>n)
	{
		if(jishu>ans)
		{
			ans=jishu;
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(vis[i]<cnt)
		{
			vis[i]++;
			dfs(temp+1,jishu+x[temp][i]);
			vis[i]--;
		}
	}
	return;
}
int main()
{
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>x[i][j];	
			}
		}
		cnt=n/2;
		ans=INT_MIN;
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;	
} 
