#include<bits/stdc++.h>
using namespace std;

int a[100005][5],n,ans;
bool cmp(int a,int b)
{
	return a<b;
}
int dfs(int m,int sum,int a1,int a2,int a3)
{
	if(m>n)
	{
		ans=max(ans,sum);
		return 0;
	}
	if(a1<n/2)
	{
		dfs(m+1,sum+a[m][1],a1+1,a2,a3);
	}
	if(a2<n/2)
	{
		dfs(m+1,sum+a[m][2],a1,a2+1,a3);
	}
	if(a3<n/2)
	{
		dfs(m+1,sum+a[m][3],a1,a2,a3+1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		bool f3=1,f2=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(j==2&&a[i][j]!=0&&f2)
				{
					f2=0;
				}
				if(j==3&&a[i][j]!=0&&f3)
				{
					f3=0;
				}
			}
		}
		if(n<=10)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
		}
		else
		{
			if(f2&&f3)
			{
				int b[100005];
				for(int i=1;i<=n;i++)
				{
					b[i]=a[i][1];
				}
				sort(b+1,b+n+1,cmp);
				for(int i=1;i<=n/2;i++)
				{
					ans+=b[i];
				}
				cout<<ans<<'\n';
			}
		}
	}
	
}

