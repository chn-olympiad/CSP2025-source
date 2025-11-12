#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int s[100000][3],a[3];
int ans = 0;
void dfs(int ge,int num,int last)
{
	if(ge == n)
	{
		ans = max(ans,num);
		return ;
	}
	else
	{
		for(int i = last;i<n;i++)
		{
			for(int j = 0;j<3;j++)
			{
				if(a[j]<n/2)
				{
					a[j]+=1;
					dfs(ge+1,num+s[i][j],i+1);
					a[j]-=1;
				}
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	cin>>t;
	while(t--)
	{
		for(int i = 0;i<3;i++)
		{
			a[i] = 0;
		}
		ans = 0;
		cin>>n;
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<3;j++)
			{
				cin>>s[i][j];
			}
		}
		dfs(0,0,0);
		cout<<ans<<endl;
	}
}
