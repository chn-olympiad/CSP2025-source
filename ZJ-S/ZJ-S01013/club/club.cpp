#include<bits/stdc++.h>
using namespace std;
struct s
{
	int num[5];
	int l;
};
s a[100005];
int t,n,ans,ans1;
int c[10];
bool cmp(s x,s y)
{
	if(x.l>y.l) return 1;
	return 0;
}
void dfs(int step)
{
	if(step>n)
	{
		ans=max(ans,ans1);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(c[i]!=n/2)
		{
			ans1+=a[step].num[i];
			c[i]++;
			dfs(step+1);
			c[i]--;
			ans1-=a[step].num[i];
		}
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		ans=0,ans1=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].num[1]>>a[i].num[2]>>a[i].num[3];
		if(n>30)
		{
			for(int i=1;i<=n;i++)
			{
				ans1+=a[i].num[1];
				a[i].l=a[i].num[2]-a[i].num[1];	
			}
			sort(a+1,a+1+n,cmp);
			for(int e=1;e<=n/2;e++)
			{
				ans1+=a[e].l;
			}		
			ans=max(ans,ans1);
			cout<<ans<<endl;
		}
		else
		{
			dfs(1);
			cout<<ans<<endl;
		}
	}
	return 0;
}
