#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int a[100002][4]={0},d[4]={0},n;
long long sum=0,ans=0;
void dfs(int i)
{
	if(i>n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int j=1;j<=3;j++)
	{
		if(d[j]+1<=n/2)
		{
			d[j]++;
			sum+=a[i][j];
			dfs(i+1); 
			d[j]--;
			sum-=a[i][j];
		}
	}
}
int main()
{
	freopen("club.in ","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t!=0)
	{
		t--;
		cin>>n;
		int p[100001],q[100001];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) 
			{
				cin>>a[i][j];
				p[i]=a[i][1];
			}
		}
		sum=0;
		ans=0;
		for(int i=1;i<=3;i++) d[i]=0;
		dfs(1);	
		cout<<ans<<endl;
	}
	return 0;
}
