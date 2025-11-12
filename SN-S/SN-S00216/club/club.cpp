#include<bits/stdc++.h>
using namespace std;
int a[100005][3],b[4],c[300005];
int n,ans=0;
void dfs(int x,int sum)
{
	if(x>n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(b[i]<n/2)
		{
			b[i]++;
			dfs(x+1,sum+a[x][i]);
			b[i]--;
		}
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=0;
		int flg1=1,sum=0,t=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				t++;
				c[t]=a[i][j];
				if((j==2 or j==3) and a[i][j]!=0)
				{
					flg1=0;
				}
			}
		}
		if(flg1==1)
		{
			sort(c,c+t+1);
			for(int j=n;j>n/2;j++)
			{
				ans+=c[j];
			}
			cout<<ans;
			return 0;
		}
		for(int i=1;i<=3;i++) b[i]=0;
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
} 
